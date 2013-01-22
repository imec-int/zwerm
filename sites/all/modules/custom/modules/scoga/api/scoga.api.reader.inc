<?php

    class Reader{
        public $nid;
        public $name;
        public $team_nid;
        public $reader_id;
        public $enabled;
    }

    /**
     * attempts to create a RFID reader node
     *
     * @param $params
     */
    function scoga_register_reader( $card_id, $reader_id ){
        module_load_include( 'api.player.inc', 'scoga', 'api/scoga' );

        /*
        * retrieve user account coupled to card id
        */
        $user_account = scoga_get_player_entity_by_card_id( $card_id );

        if( !$user_account ){
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


    /**
     * @param $reader_id
     *
     * @return bool|mixed
     */
    function  scoga_get_reader_entity_by_reader_id( $reader_id ){
        $reader_nids = scoga_get_reader_nids_by_reader_id( $reader_id );

        switch( count( $reader_nids ) ){
            case 1 :
                //exactly one match, as it should
                return node_load( $reader_nids[ 0 ] );
            case 0 :
                return FALSE;
            default :
                throw new Exception( 'RFID reader registered multiple times' );
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


    /**
     * @param $reader_id
     * @param $uid
     *
     * @return stdClass
     */
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

    /**
     * @param $reader_entity
     *
     * @return Reader
     */
    function scoga_create_reader_vo( $reader_entity ){
        $options = array(
            'entity_type' => 'node',
        );
        $output = new Reader();
        $output->enabled = $reader_entity->status;
        $output->name = $reader_entity->title;
        $output->nid = $reader_entity->nid;
        $output->reader_id = scoga_get_field_value( $reader_entity, 'field_rfidreader_id', $options);
        $options[ 'field_column' ] = 'target_id';
        $output->team_nid = scoga_get_field_value( $reader_entity, 'field_rfidreader_team', $options );
        return $output;
    }

    function scoga_get_reader_vo_by_reader_id( $reader_id ){
        $entity = scoga_get_reader_entity_by_reader_id( $reader_id );
        if( $entity ){
            return scoga_create_reader_vo( $entity );
        }

        return FALSE;
    }