<?php
    /**
     * User: creynder
     * Date: 20/04/12
     * Time: 14:49
     */

    /**
     * Creates a node of type "checkin", linked to a user account and a RFID reader node
     *
     * @param $card_id
     * @param $reader_id
     *
     * @return Result
     */
    function scoga_register_checkin( $card_id, $reader_id ){

        $output = new Result();

        $current_campaign_nid = scoga_get_current_campaign_nid();
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
        if( !$user_account ){
            $output->message = t( "card @card_id not registered", array( '@card_id', $card_id ) );
            $output->code = CODE_CARD_NOT_REGISTERED;
            return $output;
        }


        $output->uid = $user_account->uid;

        /*
        * check if user has correct permissions
        */

        if( user_access( SCOGA_PERM_REST_EXECUTE_CREATE_CHECKIN, $user_account ) === FALSE ){
            $output->message = t( 'user @uid not allowed to create checkin', array( '@uid', $user_account->uid ) );
            $output->code = CODE_NOT_ALLOWED;
            return $output;
        }


        /*
        * get reader node by reader ID, this is NOT a nid,
        * this is the unique ID of the reader as hardcoded
        */
        module_load_include( 'api.reader.inc', 'scoga', 'api/scoga' );
        $reader_node = scoga_get_reader_entity_by_reader_id( $reader_id );

        if( !$reader_node ){
            $output->message = t( "invalid RFID reader with id @reader_id", array( '@reader_id', $reader_id ) );
            $output->code = CODE_INVALID_READER;
            return $output;
        }

        /*
        * create checkin node
        */
        $checkin_node = scoga_create_checkin_entity( $user_account, $reader_node, $current_campaign_nid );

        $is_combo = scoga_evaluate_checkin_node_for_combo( $checkin_node->created, $reader_node->nid, $user_account, $current_campaign_nid );

        $output->result = $checkin_node;
        if( $is_combo ){
            $output->message =  t( 'combo checkin' );
            $output->code = CODE_COMBO_SUCCESS;
        }else{
            if( scoga_player_has_cooled_down( $user_account ) ){
                //TODO: reward points
                $output->message =  t( 'checkin' );
                $output->code = CODE_CHECKIN_SUCCESS;
            }else{
                $output->message =  t( 'Player needs to cool down' );
                $output->code = CODE_PLAYER_NEEDS_COOLDOWN;
            }
        }

        return $output;
    }

    function scoga_evaluate_checkin_node_for_combo( $new_time, $new_reader_nid, $user_account, $new_campaign_nid ){
        module_load_include( 'api.player.inc', 'scoga', 'api/scoga' );
        $new_team_nid = scoga_get_eid_from_field( $user_account, 'field_user_team',array( 'entity_type'  => 'user' ) );
        $new_player_uid = $user_account->uid;

        $index = 0;
        $at_least_one_combo = FALSE;
        while( $old_checkin_node = scoga_get_checkin_node_by_index( $index++, 'DESC' ) ){

            //sequence of checks is of importance, both for optimal performance
            //but also logic
            //continue -> the old checkin should be ignored, for instance because it was made at a different reader.
            //people should be able to checkin at the various hollow trees at the same time, without interrupting each others
            //combo checkin chains
            //break -> no more combo legible checkins possible

            //should be during same campaign
            $old_campaign_nid = scoga_get_eid_from_field( $old_checkin_node, 'field_checkin_campaign' );
            if( $old_campaign_nid != $new_campaign_nid ){
                break;
            }

            //should be same reader
            $old_reader_nid = scoga_get_eid_from_field( $old_checkin_node, 'field_checkin_reader' );
            if( $old_reader_nid != $new_reader_nid ){
                continue;
            }

            //should be within time frame
            $old_time = $old_checkin_node->created;
            if( $old_time + scoga_get_combocheckin_timeframe() < $new_time ){
                break;
            }


            $old_user_account = user_load( $old_checkin_node->uid );

            //should not be same player
            $old_player_uid = $old_user_account->uid;
            if( $old_player_uid == $new_player_uid ){
                continue;
            }

            //should be from same team (since we already know the checkin occurs at same reader, otherwise we wouldn't have gotten here)
            $old_team_nid = scoga_get_eid_from_field( $old_user_account, 'field_user_team',array( 'entity_type'  => 'user' ) );
            if( $old_team_nid != $new_team_nid ){
                break;
            }

            //if we made it here, the checkin is valid
            $is_combo = scoga_award_combocheckin_if_new_partners( $user_account->uid, $old_checkin_node->uid );
            $at_least_one_combo = $at_least_one_combo || $is_combo;
        };
        return $at_least_one_combo;
    }

    function scoga_award_combocheckin_if_new_partners( $requester_uid, $requestee_uid ){
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
    function scoga_get_checkin_node_by_index( int $index, $order = 'ASC' ){
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

        //published or not
        $checkin_node->status = ( $user_registered_raw ) ? "1" : "0";

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

        return $relationship_type;
    }