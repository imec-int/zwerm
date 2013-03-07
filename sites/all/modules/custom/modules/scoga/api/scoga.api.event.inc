<?php
/**
 * Camille Reynders, http://www.creynders.be
 * 27/02/13 - 10:13
 */

    function scoga_register_eventfulfilled( $event_nid, $card_id, $remote_p, $hash, $remote_signature ){

        $result = new Result();
        $feedback_params = array(
            '@cardID' => $card_id,
            '@eventNID' => $event_nid,
        );


        $unenc_signature = $hash . $event_nid . SCOGA_SALT;
        $enc_signature = hash( 'sha256', $unenc_signature );
        if( $enc_signature != $remote_signature ){
            $result->message = t( 'incorrect signature', $feedback_params );
            $result->code = CODE_INCORRECT_SIGNATURE;
            return $result;
        }


        module_load_include( 'api.player.inc', 'scoga', 'api/scoga' );

        if( ! $player_account = scoga_get_player_entity_by_card_id( $card_id ) ){
            $result->message = t( 'user with card ID "@cardID" not found', $feedback_params );
            $result->code = CODE_USER_NOT_FOUND;
            return $result;
        }

        $feedback_params['@user']=$player_account->name;

        if( ! $event_node = node_load( $event_nid ) ){
            $result->message = t( 'Incorrect passphrase or event with ID "@eventNID" not found', $feedback_params );
            $result->code = CODE_INCORRECT_PASS_OR_EVENT;
            return $result;
        }

        $feedback_params[ '@event' ] = $event_node->title;

        $unenc_passphrase = scoga_get_field_value( $event_node, 'field_event_passphrase' ) . SCOGA_SALT . $hash;
        $local_p =hash( 'sha256', $unenc_passphrase );
        if( $local_p != $remote_p ){
            $result->message = t( 'Incorrect passphrase or event with ID "@eventNID" not found', $feedback_params );
            $result->code = CODE_INCORRECT_PASS_OR_EVENT;
            return $result;
        }

        $existing_nids = scoga_get_eventfulfilled_nids_by_references( $player_account->uid, $event_node->nid );
        if(count( $existing_nids ) > 0 ){
            $result->message = t( '@user already received points for event "@event"', $feedback_params );
            $result->code = CODE_PLAYER_ALREADY_FULFILLED;
            return $result;
        }

        if( ! $ef_node = scoga_create_eventfulfilled_node( $player_account, $event_node ) ){
            $result->message = t( 'Unknown error occurred. @user did not receive points for event "@event"', $feedback_params );
            $result->code = CODE_UNKNOWN_ERROR;
            return $result;
        }
        $reward = scoga_get_field_value( $event_node, 'field_event_reward' );
        $reason = t('event fulfilled');
        module_load_include( 'api.points.inc', 'scoga', 'api/scoga' );
        //scoga_award_points_to_user( $player_account->uid, $reward, $reason );

        $feedback_params['@points']=$reward;

        $result->message = t( '@user received @points point(s) for event "@event"', $feedback_params );
        $result->code = CODE_EVENT_SUCCESS;
        return $result;
    }

    function scoga_create_eventfulfilled_node( $player_account, $event_node ){
        $lang = LANGUAGE_NONE;

        $ef_node = new stdClass();
        $ef_node->type = SCOGA_EVENTFULFILLED_NODETYPE;
        node_object_prepare( $ef_node );

        //required fields
        $ef_node->uid = $player_account->uid;

        //optional fields
        //reader reference
        scoga_set_eid_in_field( $ef_node, 'field_eventfulfilled_event', $event_node->nid );

        $ef_node->title = t('@user fulfilled event @event',array( '@user' => $player_account->name, '@event' => $event_node->title ) );

        //node_save( $ef_node );

        return $ef_node;

    }

    /**
     * retrieves all events that match the passphrase. Returns an empty array when non found
     * @param string $passphrase
     *
     * @return array
     */
    function scoga_get_event_nids_by_passphrase( $passphrase = '' ){
        if( $passphrase ){
            $entity_type = 'node';
            $query = new EntityFieldQuery();
            $result = $query
                ->entityCondition( 'entity_type', $entity_type )
                ->entityCondition( 'bundle', SCOGA_EVENT_NODETYPE )
                ->fieldCondition( 'field_event_passphrase', 'value', $passphrase )
                ->propertyOrderBy( 'nid', 'DESC' )
                ->execute()
            ;

            if( isset( $result[ $entity_type ] ) ){
                $nids = array_keys( $result[ $entity_type ] );
                return $nids;
            }
        }

        return array();
    }

    function scoga_check_nonunique_passphrase( $event_node ){
        $passphrase = scoga_get_field_value( $event_node, 'field_event_passphrase' );
        $existing_nids = scoga_get_event_nids_by_passphrase( $passphrase );

        switch( count( $existing_nids ) ){
            case 0:
                break;
            case 1:

                if( $existing_nids[ 0 ] == $event_node->nid ){
                    //no problemo, it's the same node
                    break;
                }

            //N.B. fall through
            default:
                //multiple found
                drupal_set_message( t( 'Multiple events with the same passphrase exist, please modify the passphrase' ), 'error' );
                break;
        }
    }

    /**
     * retrieves all event fulfilled nids that were created by $player_uid for $event_nid
     * returns empty array when none found
     *
     * @param $player_uid
     * @param $event_nid
     *
     * @return array
     */
    function scoga_get_eventfulfilled_nids_by_references( $player_uid, $event_nid ){
        $query = new EntityFieldQuery();
        $entity_type = 'node';
        $query
            ->entityCondition( 'entity_type', $entity_type )
            ->entityCondition( 'bundle', SCOGA_EVENTFULFILLED_NODETYPE )
            ->fieldCondition( 'field_eventfulfilled_event', 'target_id', $event_nid, '=' );
        ;
        $result = $query->execute();
        if( isset( $result[ $entity_type ] ) ){
            return array_keys( $result[ $entity_type ] );
        }

        return array();
    }