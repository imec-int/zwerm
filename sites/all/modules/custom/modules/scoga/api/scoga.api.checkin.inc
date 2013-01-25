<?php
    /**
     * User: creynder
     * Date: 20/04/12
     * Time: 14:49
     */

    class Checkin{

        /**
         * @var []Relationship
         */
        public $new_relationships;

        /**
         * @var []PointsTransaction
         */
        public $users_points;

        /**
         * @var []PointsTransaction
         */
        public $conn_points;
        public $cardID;
        public $expires;
        public $nid;
    }

    /**
     * Creates a node of type "checkin", linked to a user account and a RFID reader node
     *
     * @param $card_id
     * @param $reader_id
     *
     * @return Result
     */
    function scoga_register_checkin( $card_id, $reader_id ){
//        ddl( '--- scoga_register_checkin ---');
        $output = new Result();

        $current_campaign_nid = scoga_get_current_campaign_nid();
//        ddl( $current_campaign_nid, '$current_campaign_nid');
        if( !$current_campaign_nid ){
            $output->message = t( 'no campaign is running at the moment' );
            $output->code = CODE_NO_CAMPAIGN;
            return $output;
        }

        /*
        * get user account
        */
        module_load_include( 'api.player.inc', 'scoga', 'api/scoga' );
        $user_account = scoga_get_player_entity_by_card_id( $card_id );
//        ddl( $user_account, '$user_account');
        if( !$user_account ){
            $output->message = t( "card @card_id not registered", array( '@card_id' => $card_id ) );
            $output->code = CODE_CARD_NOT_REGISTERED;
            return $output;
        }


        $output->uid = $user_account->uid;

        /*
        * check if user has correct permissions
        */

        if( user_access( SCOGA_PERM_REST_EXECUTE_CREATE_CHECKIN, $user_account ) === FALSE ){
            $output->message = t( 'user @uid not allowed to create checkin', array( '@uid' => $user_account->uid ) );
            $output->code = CODE_NOT_ALLOWED;
            return $output;
        }


        /*
        * get reader node by reader ID, this is NOT a nid,
        * this is the unique ID of the reader as hardcoded
        */
        module_load_include( 'api.reader.inc', 'scoga', 'api/scoga' );
        $reader_node = scoga_get_reader_entity_by_reader_id( $reader_id );
//        ddl( $reader_node, '$reader_node');

        if( !$reader_node ){
            $output->message = t( "invalid RFID reader with id @reader_id", array( '@reader_id' => $reader_id ) );
            $output->code = CODE_INVALID_READER;
            return $output;
        }

        /*
        * create checkin node
        */
        $checkin_node = scoga_create_checkin_entity( $user_account, $reader_node, $current_campaign_nid );
//        ddl( $checkin_node, '$checkin_node');

        $users_points = array();
        if( scoga_player_has_cooled_down( $user_account ) ){
            $output->message =  t( 'checkin' );
            $output->code = CODE_CHECKIN_SUCCESS;
            module_load_include( 'api.points.inc', 'scoga', 'api/scoga' );
            $transaction_node = scoga_award_points_to_user( $user_account->uid, scoga_get_rfidcheckin_reward(), $output->message );
            $users_points[] = scoga_create_transaction_vo_from_assoc_arr( $transaction_node );
            $checkin_node->status=1;
        }else{
            $output->message =  t( 'Player needs to cool down' );
            $output->code = CODE_PLAYER_NEEDS_COOLDOWN;
        }


        $relationships_list = scoga_evaluate_checkin_node_for_combo( $checkin_node->created, $reader_node->nid, $user_account, $current_campaign_nid );
//        ddl( $relationships_list, '$relationships_list');

        $checkin_vo = new Checkin();
        $checkin_vo->nid = $checkin_node->nid;
        $checkin_vo->cardID = $card_id;

        $conn_points = array();

        if( count( $relationships_list ) > 0 ){
            $output->message =  t( 'combo checkin' );
            $output->code = CODE_COMBO_SUCCESS;
            foreach( $relationships_list as $relationship_vo ){
                $transaction_node = scoga_award_points_to_user( $relationship_vo->requester_id, scoga_get_combocheckin_reward(), $output->message );
                $conn_points[] = scoga_create_transaction_vo_from_assoc_arr( $transaction_node );
                $transaction_node = scoga_award_points_to_user( $relationship_vo->requestee_id , scoga_get_combocheckin_reward(), $output->message );
                $conn_points[] = scoga_create_transaction_vo_from_assoc_arr( $transaction_node );
            }
            scoga_set_field_value( $checkin_node, 'field_checkin_type', 'combo' );
            $checkin_node->status=1;
        }

        node_save( $checkin_node );

        $checkin_vo->users_points = $users_points;
        $checkin_vo->conn_points = $conn_points;
        $checkin_vo->new_relationships = $relationships_list;
        $checkin_vo->expires = time() + scoga_get_combocheckin_timeframe();
        $output->result = $checkin_vo;
        return $output;
    }

    function scoga_evaluate_checkin_node_for_combo( $new_time, $new_reader_nid, $user_account, $new_campaign_nid ){
        $new_team_nid = scoga_get_eid_from_field( $user_account, 'field_user_team',array( 'entity_type'  => 'user' ) );
        $new_player_uid = $user_account->uid;

        $index = 0;
        $combo_uids = array();
        $comparison_time = $new_time;

        //we need to skip the newly created node, so pre-increment index
        while( $old_checkin_node = scoga_get_checkin_node_by_index( ++$index, 'DESC' ) ){
//            ddl( $old_checkin_node, 'iteration '. $index );

            //sequence of checks is of importance, both for optimal performance
            //but also logic
            //continue -> the old checkin should be ignored, for instance because it was made at a different reader.
            //people should be able to checkin at the various hollow trees at the same time, without interrupting each others
            //combo checkin chains
            //break -> no more combo legible checkins possible

            //should be during same campaign, otherwise exit
            $old_campaign_nid = scoga_get_eid_from_field( $old_checkin_node, 'field_checkin_campaign' );
            if( $old_campaign_nid != $new_campaign_nid ){
//                ddl( 'not during same campaign');
                break;
            }

            //should be same reader, otherwise ignore
            $old_reader_nid = scoga_get_eid_from_field( $old_checkin_node, 'field_checkin_reader' );
            if( $old_reader_nid != $new_reader_nid ){
//                ddl( 'not same reader');
                continue;
            }

            //should be within time frame, otherwise exit
            $old_time = $old_checkin_node->created;
            if( $old_time + scoga_get_combocheckin_timeframe() < $comparison_time ){
//                ddl( 'not within time frame');
                break;
            }else{
                $comparison_time = $old_time;
            }


            $old_user_account = user_load( $old_checkin_node->uid );

            //should not be same player, otherwise exit
            $old_player_uid = $old_user_account->uid;
            if( $old_player_uid == $new_player_uid ){
                //invalid uid, clear
//                ddl( 'same player');
                $combo_uids = array();
                break;
            }

            //should be from same team, otherwise exit
            //(we already know the checkin occurs at same reader, otherwise we wouldn't have gotten here)
            $old_team_nid = scoga_get_eid_from_field( $old_user_account, 'field_user_team',array( 'entity_type'  => 'user' ) );
            if( $old_team_nid != $new_team_nid ){
//                ddl( 'other team');
                break;
            }

            //
            $combo_uids[] = $old_checkin_node->uid;
        };

        $relationships_list = array();
        foreach( $combo_uids as $new_uid ){
            $relationship_node = scoga_request_combocheckin_relationship( $user_account->uid, $new_uid );
            if( $relationship_node ){
                module_load_include( 'api.network.inc', 'scoga', 'api/scoga' );
                $relationships_list[] = scoga_create_relationship_vo( $relationship_node );
            }
        }



        return $relationships_list;
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

        $nids = array_keys( $result[ $entity_type ] );
        if( $nids ){
            $node = node_load( $nids[ 0 ] );
            return intval( $node->created );
        }

        return FALSE;
    }


    /**
     * @param int $index 0-based
     *
     * @return bool|mixed
     */
    function scoga_get_checkin_node_by_index( $index, $order = 'ASC' ){
        $entity_type = 'node';
        $query = new EntityFieldQuery();
        //get last checkin
        $result = $query
            ->entityCondition( 'entity_type', $entity_type )
            ->entityCondition( 'bundle', SCOGA_CHECKIN_NODETYPE )
            ->propertyOrderBy( 'created', $order )
            ->range( $index, 1 )
            ->execute();

        $nids = array_keys( $result[ $entity_type ] );
        if( $nids ){
            return node_load( $nids[ 0 ] );
        }
        return FALSE;
    }

    /**
     * @param $user_account
     * @param $reader_node
     * @param $current_campaign_nid
     *
     * @return stdClass
     */
    function scoga_create_checkin_entity( $user_account, $reader_node, $current_campaign_nid ){

        $lang = LANGUAGE_NONE;

        $user_registered_raw = scoga_get_field_value( $user_account, 'field_user_registered', array( 'entity_type' => 'user' ) );

        $checkin_node = new stdClass();
        $checkin_node->type = SCOGA_CHECKIN_NODETYPE;
        node_object_prepare( $checkin_node );

        $checkin_time_formatted = date( SCOGA_TIME_FORMAT, $checkin_node->created );

        //required fields
        $checkin_node->uid = $user_account->uid;

        //optional fields
        //reader reference
        scoga_set_eid_in_field( $checkin_node, 'field_checkin_reader', $reader_node->nid );
        scoga_set_eid_in_field( $checkin_node, 'field_checkin_campaign', $current_campaign_nid );

        //title
        $title_params = array(
            '@user'   => $user_account->name,
            '@reader' => $reader_node->title,
            '@time'   => $checkin_time_formatted,
        );
        $checkin_node->title = t( '@user checked in with @reader at @time', $title_params );

        $checkin_node->status = 0; //NOT PUBLISHED BY DEFAULT

        //save the mofo node
        $checkin_node = node_submit( $checkin_node );
        node_save( $checkin_node );


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