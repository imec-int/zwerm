<?php
/**
 * Camille Reynders, http://www.creynders.be
 * 27/02/13 - 10:13
 */

    function scoga_register_eventfulfilled( $card_id, $passphrase ){
        module_load_include( 'api.player.inc', 'scoga', 'api/scoga' );

        if( $player_account = scoga_get_player_entity_by_card_id( $card_id ) ){
            if( $event_node = scoga_get_single_event_node_by_passphrase( $passphrase ) ){
                $existing_nids = scoga_get_eventfulfilled_nids_by_references( $player_account->uid, $event_node->nid );
                if(count( $existing_nids ) <= 0 ){
                    if( $ef_node = scoga_create_eventfulfilled_node( $player_account, $event_node ) ){
                        $reward = scoga_get_field_value( $event_node, 'field_event_reward' );
                        $reason = t('event fulfilled');
                        module_load_include( 'api.points.inc', 'scoga', 'api/scoga' );
                        scoga_award_points_to_user( $player_account->uid, $reward, $reason );
                    }
                }else{
                    throw new ErrorException( t( '@user already received points for event "@event"', array( '@user' => $player_account->name, '@event' => $event_node->title ) ) );
                }
            }else{
                throw new ErrorException( t( 'Incorrect passphrase for event' ) );
            }
        }else{
            throw new ErrorException( t( 'user with card ID "@cardID" not found', array( '@cardID' => $card_id ) ) );
        }

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

        node_save( $ef_node );

        return $ef_node;

    }

    /**
     * retrieves event node by passphrase.
     * returns FALSE when not found
     * @param string $passphrase
     *
     * @return bool|stdClass
     */
    function scoga_get_single_event_node_by_passphrase( $passphrase = '' ){
        $nid = scoga_get_single_event_nid_by_passphrase( $passphrase );
        if( $nid > 0 ){
            return node_load( $nid );
        }

        return FALSE;
    }

        /**
         * @param string $passphrase uniquely identifying passphrase
         *
         * @return int returns -1 when none found and
         */
    function scoga_get_single_event_nid_by_passphrase( $passphrase = '' ){
        $nids = scoga_get_event_nids_by_passphrase( $passphrase );
        switch( count( $nids ) ){
            default:
                watchdog( 'SCOGA', 'multiple events with same passphrase: @nids', array( '@nids' => implode( ',', $nids ) ), WATCHDOG_ERROR );
                //N.B. fall through
            case 1:
                return $nids[ 0 ];
            case 0:
                watchdog( 'SCOGA', 'event with passphrase "@passphrase" not found', array( '@passphrase' => $passphrase ), WATCHDOG_WARNING );
                //N.B. fall through
        }
        return -1;
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