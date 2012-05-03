<?php
    /**
     * Created by JetBrains PhpStorm.
     * User: creynder
     * Date: 20/04/12
     * Time: 14:48
     * To change this template use File | Settings | File Templates.
     */


    /**
     * attempts to create a RFID reader node
     *
     * @param $params
     */
    function scoga_register_reader( $card_id, $reader_id ){
        module_load_include( 'api.player.inc', 'scoga_core' );

        /*
        * retrieve user account coupled to card id
        */
        $user_account = scoga_get_player_entity_by_card_id( $card_id );

        if( ! $user_account ){
            throw new Exception( "card $card_id not registered" );
        }

        $user_access = user_access( SCOGA_PERM_REST_EXECUTE_REGISTER_READER, $user_account );
        if( $user_access === FALSE ){
            throw new Exception( "user " . $user_account->uid . " not allowed to register reader" );
        }


        /*
        * check that the RFID reader IS registered
        */
        $reader_node = scoga_get_reader_entity_by_reader_id( $reader_id );

        if( $reader_node ){
            throw new Exception( 'RFID reader ' . $reader_id . ' already registered' );
        }

        $reader_node = scoga_create_reader_entity( $reader_id, $user_account->uid );

        return $reader_node;

    }


    function  scoga_get_reader_entity_by_reader_id( $reader_id ){
        $reader_nids = scoga_get_reader_nids_by_reader_id( $reader_id );

//
        switch( count( $reader_nids ) ){
            case 1 :
                {
                //exactly one match, as it should
                return node_load( $reader_nids[ 0 ] );
                break;
                }
            case 0 :
                {
                return FALSE;
                }
            default :
                {
                scoga_throw_exception( 'RFID reader registered multiple times' );
                }
        }
    }


    /**
     * get reader nids by RFID reader ID
     *
     * @param $reader_id
     *
     * @return array
     */
    function scoga_get_reader_nids_by_reader_id( $reader_id ){
        $entity_type = 'node';
        $reader_query = new EntityFieldQuery();

        //get reader node by RFID reader ID
        $reader_entities = $reader_query
            ->entityCondition( 'entity_type', $entity_type )
            ->entityCondition( 'bundle', SCOGA_READER_NODETYPE )
            ->fieldCondition( 'field_rfidreader_id', 'value', $reader_id, '=', 0 )
            ->execute();

        //possible multiple matches
        return array_keys( $reader_entities[ $entity_type ] );
    }


    function scoga_create_reader_entity( $reader_id, $uid ){
        $reader_node = new stdClass();
        $reader_node->type = SCOGA_READER_NODETYPE;
        node_object_prepare( $reader_node );
        $reader_node->uid = $uid;
        $reader_node->language = LANGUAGE_NONE;
        $reader_node->title = 'RFID reader ' . $reader_id;
        $reader_node->field_rfidreader_id[ LANGUAGE_NONE ][ 0 ] = array(
            'value' => $reader_id
        );

        //node_save will contrary to user_save NOT return the node object
        //but $reader_node is passed by reference, so it WILL contain the new nid
        node_save( $reader_node );

        return $reader_node;
    }
