<?php
    /**
     * User: creynder
     * Date: 20/04/12
     * Time: 14:49
     */

    class CheckinBase{
        /**
         * @var string
         */
        public $message;

        /**
         * @var int
         */
        public $code = CODE_UNKNOWN_ERROR;

        /**
         * @var number
         */
        public $nid;

    }

    class SingleCheckin extends CheckinBase{
        /**
         * @var string
         */
        public $type = SCOGA_CHECKIN_TYPE_SINGLE;

        /**
         * @var number timestamp
         */
        public $expires;

        /**
         * @var PointsTransaction
         */
        public $transaction;

        /**
         * stores the data of the player doing the checkin
         * THE POINTS HAVE NOT YET BEEN ADDED
         * @var Player
         */
        public $player;

        /**
         * @var string
         */
        public $card_id;
    }

    class ComboCheckin extends CheckinBase{

        /**
         * @var string
         */
        public $type = SCOGA_CHECKIN_TYPE_COMBO;

        /**
         * @var []Relationship
         */
        public $transactions = array();
        /**
         * @var Relationship
         */
        public $relationship;
        /**
         * @var SingleCheckin
         */
        public $single;

        /**
         * stores the  data of the player the combo checkin is done with [!]
         * THE POINTS HAVE NOT YET BEEN ADDED !
         * @var Player
         */
        public $partner;
    }


    /**
     *
     * @param $card_id
     * @param $reader_node stdClass
     * @param $now number timestamp
     * @param $campaign_nid number
     *
     * @return SingleCheckin
     */
    function scoga_register_single_checkin( $card_id, $reader_node, $now, $campaign_nid ){
        $checkin_vo = new SingleCheckin();
        $checkin_vo->card_id = $card_id;

        /*
        * get reader node by reader ID, this is NOT a nid,
        * this is the unique ID of the reader as hardcoded
        */
        module_load_include( 'api.reader.inc', 'scoga', 'api/scoga' );

        if( !$reader_node ){
            $checkin_vo->message = t( "invalid RFID reader" );
            $checkin_vo->code = CODE_INVALID_READER;
            return $checkin_vo;
        }


        if( !$campaign_nid ){
            $checkin_vo->message = t( 'no campaign is running at the moment' );
            $checkin_vo->code = CODE_NO_CAMPAIGN;
            return $checkin_vo;
        }

        /*
        * get user account
        */
        module_load_include( 'api.player.inc', 'scoga', 'api/scoga' );
        try{
            $player_entity = scoga_get_player_entity_by_card_id( $card_id );
        }catch ( Exception $error ){
            $checkin_vo->message = $error->getMessage();
            $checkin_vo->code = $error->getCode();
            return $checkin_vo;
        }

        if( !$player_entity ){
            $checkin_vo->message = t( "card with ID '@card_id' not registered", array( '@card_id' => $card_id ) );
            $checkin_vo->code = CODE_CARD_NOT_REGISTERED;
            return $checkin_vo;
        }

        $checkin_vo->player = scoga_create_player_vo( $player_entity );

        /*
        * check if user has correct permissions
        */

        if( user_access( SCOGA_PERM_REST_EXECUTE_CREATE_CHECKIN, $player_entity ) === FALSE ){
            $checkin_vo->message = t( 'user @username not allowed to create checkin', array( '@username' => $player_entity->name ) );
            $checkin_vo->code = CODE_NOT_ALLOWED;
            return $checkin_vo;
        }


        /*
        * It's a valid checkin
        */
        $checkin_time_formatted = date( SCOGA_TIME_FORMAT, $now );

        $new_checkin_node = scoga_create_checkin_entity(
            $player_entity->uid,
            $reader_node,
            $campaign_nid,
            $checkin_vo->type
        );

        $title_params = array(
            '@user'   => $player_entity->name,
            '@reader' => $reader_node->title,
            '@time'   => $checkin_time_formatted,
        );

        $checkin_vo->expires = $now + scoga_get_combocheckin_timeframe();

        if( scoga_player_has_cooled_down( $player_entity ) ){
            $checkin_vo->message =  t( '@user checked in with @reader at @time', $title_params );
            $checkin_vo->code = CODE_CHECKIN_SUCCESS;
            module_load_include( 'api.points.inc', 'scoga', 'api/scoga' );
            $transaction_arr = scoga_award_points_to_user(
                $player_entity->uid,
                scoga_get_rfidcheckin_reward(),
                'checkin'
            );
            $checkin_vo->transaction = scoga_create_transaction_vo_from_assoc_arr( $transaction_arr );
            $new_checkin_node->status=1;
        }else{
            $checkin_vo->message =  t( '@user needs to cool down', $title_params );
            $checkin_vo->code = CODE_PLAYER_NEEDS_COOLDOWN;
            $new_checkin_node->status=0;
        }

        $new_checkin_node->title = $checkin_vo->message;
        node_save( $new_checkin_node );
        $checkin_vo->nid = $new_checkin_node->nid;

        return $checkin_vo;
    }

    function scoga_register_combo_checkin( $card_id, $reader_node, $now, $campaign_nid ){
        $prev_single_checkin_nid = _get_last_checkin_node_nid( $reader_node->nid, $campaign_nid );

        $current_single_checkin_vo = scoga_register_single_checkin( $card_id, $reader_node, $now, $campaign_nid );
        $fatal_codes = array(
            CODE_UNKNOWN_ERROR,
            CODE_NO_CAMPAIGN,
            CODE_CARD_NOT_REGISTERED,
            CODE_NOT_ALLOWED,
            CODE_INVALID_READER,
            CODE_CARD_MULTIPLE
        );

        if( array_search( $current_single_checkin_vo->code, $fatal_codes ) !== FALSE ){
            //something gross has happened, terminate
            return $current_single_checkin_vo;
        }

        //we're safe to proceed for combo checking

        $prev_single_checkin_node = node_load( $prev_single_checkin_nid );
        $prev_player_entity = user_load( $prev_single_checkin_node->uid );
        $prev_player_vo = scoga_create_player_vo( $prev_player_entity );

        $current_player_vo = $current_single_checkin_vo->player;

        $current_combo_checkin_vo = new ComboCheckin();
        $current_combo_checkin_vo->single = $current_single_checkin_vo;
        $current_combo_checkin_vo->partner = $prev_player_vo;

        //test user
        if( $prev_player_vo->uid == $current_player_vo->uid ){
            //same user

            $current_combo_checkin_vo->message = t( 'You cannot combo with yourself' );
            $current_combo_checkin_vo->code = CODE_SAME_USER;
            return $current_combo_checkin_vo;
        }

        $players = array( '@player' => $current_player_vo->username, '@partner' => $prev_player_vo->username );

        //test team
        if( $prev_player_vo->team_nid != $current_player_vo->team_nid ){
            //not on the same team

            $current_combo_checkin_vo->message = t( '@player is not on the same team as @partner', $players );
            $current_combo_checkin_vo->code = CODE_OTHER_TEAM;
            return $current_combo_checkin_vo;
        }

        //test timeout
        if( $prev_single_checkin_node->created < $now - scoga_get_combocheckin_timeframe() ){
            //checkin is too old
            $current_combo_checkin_vo->message = t( 'Too late to combo' );
            $current_combo_checkin_vo->code = CODE_COMBO_TIMEOUT;
            return $current_combo_checkin_vo;
        }

        //test relationship exists
        $relationship_node = scoga_request_combocheckin_relationship( $current_player_vo->uid, $prev_player_vo->uid );
        if( !$relationship_node ){
            $current_combo_checkin_vo->message = t( '@player already checked in with @partner', $players );
            $current_combo_checkin_vo->code = CODE_RELATIONSHIP_EXISTS;
            return $current_combo_checkin_vo;
        }

        //Woohoow, a genuine combo checkin !

        module_load_include( 'api.network.inc', 'scoga', 'api/scoga' );
        $current_combo_checkin_vo->message = t( '@player successfully combo checked in with @partner', $players );
        $current_combo_checkin_vo->code = CODE_COMBO_SUCCESS;

        $relationship_vo = scoga_create_relationship_vo( $relationship_node );
        $current_combo_checkin_vo->relationship = $relationship_vo;

        $transaction_arr = scoga_award_points_to_user( $prev_player_vo->uid, scoga_get_combocheckin_reward(), 'combo' );
        $current_combo_checkin_vo->transactions[] = scoga_create_transaction_vo_from_assoc_arr( $transaction_arr );
        $transaction_arr = scoga_award_points_to_user( $current_player_vo->uid, scoga_get_combocheckin_reward(), 'combo' );
        $current_combo_checkin_vo->transactions[] = scoga_create_transaction_vo_from_assoc_arr( $transaction_arr );

        $current_combo_checkin_node = scoga_create_checkin_entity(
            $current_player_vo->uid,
            $reader_node,
            $campaign_nid,
            $current_combo_checkin_vo->type
        );

        $current_combo_checkin_node->title = $current_combo_checkin_vo->message;
        $current_combo_checkin_node->status=1;
        node_save( $current_combo_checkin_node );

        $current_combo_checkin_vo->nid = $current_combo_checkin_node->nid;

        return $current_combo_checkin_vo;
    }

    /**
     * returns the last single checkin at reader <code>reader_nid</code> and during <code>campaign_nid</code> campaign
     *
     * @param $reader_nid
     * @param $campaign_nid
     *
     * @return int
     */

    function _get_last_checkin_node_nid( $reader_nid, $campaign_nid ){
        $entity_type = 'node';
        $query = new EntityFieldQuery();

        $entity_type = 'node';
        $query = new EntityFieldQuery();
        $query
            ->entityCondition( 'entity_type', $entity_type )
            ->entityCondition( 'bundle', SCOGA_CHECKIN_NODETYPE )
            ->fieldCondition( 'field_checkin_type', 'value', SCOGA_CHECKIN_TYPE_SINGLE ) // of type
            ->fieldCondition( 'field_checkin_reader', 'target_id', $reader_nid) //of reader
            ->fieldCondition( 'field_checkin_campaign', 'target_id', $campaign_nid ) // of campaign
            ->propertyOrderBy( 'created', 'DESC' )
            ->range( 0, 1 )
        ;
        $result = $query->execute();
        if( isset( $result['node'] ) ){
            return array_shift( array_keys( $result['node'] ) );
        }

        return 0;
    }

    /**
     * If the relationship already exists it returns NULL otherwise the object of the newly
     * created relationship
     *
     * @param $requester_uid
     * @param $requestee_uid
     *
     * @return object|NULL
     */
    function scoga_request_combocheckin_relationship( $requester_uid, $requestee_uid ){
        return user_relationships_request_relationship(
            $requester_uid,
            $requestee_uid,
            scoga_get_current_combocheckin_rtid(),
            TRUE
        );
    }

    /**
     * @param      $user_account
     * @param null $time defaults to current timestamp
     *
     * @return bool
     */
    function scoga_player_has_cooled_down( $user_account, $time = NULL ){
        isset( $time ) || $time = time();
        $cooldown_tstamp = scoga_get_cooldown_timestamp_by_player_uid( $user_account->uid );
        return $time >= $cooldown_tstamp;
    }

    /**
     * @param $uid
     *
     * @return int
     */
    function scoga_get_cooldown_timestamp_by_player_uid( $uid ){
        $checkin_time = scoga_get_last_checkintime_of_player( $uid );
        return ( $checkin_time )
            ? $checkin_time + scoga_get_checkin_cooldown()
            : 0;
    }

    /**
     * @param $uid
     *
     * @return bool|int
     */
    function scoga_get_last_checkintime_of_player( $uid ){
        $entity_type = 'node';
        $query = new EntityFieldQuery();

        //get last swipe
        $result = $query
            ->entityCondition( 'entity_type', $entity_type )
            ->entityCondition( 'bundle', SCOGA_CHECKIN_NODETYPE )
            ->propertyCondition( 'uid', $uid )
            ->propertyCondition( 'status', 1 )
            ->fieldCondition( 'field_checkin_type', 'value', 'single', '=')
            ->propertyOrderBy( 'created', 'DESC' )
            ->range( 0, 1 )
            ->execute();

        if( isset( $result[ $entity_type ] ) ){
            $nids = array_keys( $result[ $entity_type ] );
            if( $nids ){
                $node = node_load( $nids[ 0 ] );
                return intval( $node->created );
            }
        }

        return FALSE;
    }

    /**
     * @param $user_account
     * @param $reader_node
     * @param $current_campaign_nid
     * @param $type string type of checkin
     *
     * @return stdClass
     */
    function scoga_create_checkin_entity( $player_uid, $reader_node, $current_campaign_nid, $type ){

        $lang = LANGUAGE_NONE;

        $checkin_node = new stdClass();
        $checkin_node->type = SCOGA_CHECKIN_NODETYPE;
        node_object_prepare( $checkin_node );

        //required fields
        $checkin_node->uid = $player_uid;

        //optional fields
        //reader reference
        scoga_set_eid_in_field( $checkin_node, 'field_checkin_reader', $reader_node->nid );
        scoga_set_eid_in_field( $checkin_node, 'field_checkin_campaign', $current_campaign_nid );
        scoga_set_field_value( $checkin_node, 'field_checkin_type', $type );

        $checkin_node->status = 0; //NOT PUBLISHED BY DEFAULT

        return $checkin_node;
    }


    /**
     * depends on user_relationship, saves and loads a user relationship
     *
     * @param $prefix
     *
     * @return bool|StdClass
     */
    function scoga_create_combocheckin_relationship_type( $prefix ){
        //TODO: load user_relationship module??
        $params = array( '@prefix' => $prefix );
        $relationship_type = new StdClass;
        $relationship_type->name = t( '@prefix checkin partner', $params );
        $relationship_type->plural_name = t( '@prefix checkin partners', $params );
        $relationship_type->is_oneway = FALSE;
        $relationship_type->requires_approval = FALSE;
        $relationship_type->expires_val = 0;

        //$relationship_type is updated by reference
        user_relationships_type_save( $relationship_type );

        scoga_grant_player_role_permissions_to_combocheckin_relationship_type( $relationship_type );

        return $relationship_type;
    }

    function scoga_delete_combocheckin_relationship_type( $prefix ){
        $types = user_relationships_types_load( TRUE );
        $params = array( '@prefix' => $prefix );
        $name = t( '@prefix checkin partner', $params );
        foreach( $types as $type ){
            if( $type->name == $name ){
                user_relationships_type_delete( $type->rtid );
            }
        }
    }

    function scoga_grant_player_role_permissions_to_combocheckin_relationship_type( $relationship_type ){
        cache_clear_all( 'user_relationships', 'cache', TRUE );

        /*
         * resets the user_relationships_types list.
         * DO NOT REMOVE, otherwise the newly inserted user relationship type won't be available
         * to grant permissions to.
         */
        user_relationships_types_load( TRUE );

        //grant permissions
        $permissions = array();
        $permissions[ 'can have '       . $relationship_type->name . ' relationships' ] = TRUE;
        $permissions[ 'can request '    . $relationship_type->name . ' relationships' ] = TRUE;
        $permissions[ 'view all '       . $relationship_type->name . ' relationships' ] = TRUE;
        user_role_change_permissions( SCOGA_PLAYER_ROLE, $permissions );
    }