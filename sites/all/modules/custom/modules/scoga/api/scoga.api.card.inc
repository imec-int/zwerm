<?php
    /**
     * Created by JetBrains PhpStorm.
     * User: creynder
     * Date: 20/04/12
     * Time: 14:49
     * To change this template use File | Settings | File Templates.
     */


    /**
     * @param $card_id
     * @param $reader_id
     *
     * @return bool|stdClass
     */
    function scoga_register_card( $card_id, $reader_id ){
        watchdog( 'SCOGA', 'scoga_register_card: @card_id, @reader_id', array( '@card_id' => $card_id, '@reader_id' => $reader_id ), WATCHDOG_NOTICE );
        module_load_include( 'api.reader.inc', 'scoga', 'api/scoga' );
        module_load_include( 'api.player.inc', 'scoga', 'api/scoga' );
        module_load_include( 'api.team.inc', 'scoga', 'api/scoga' );

        /*
        * check that the RFID reader IS registered
        */
        $reader_node = scoga_get_reader_entity_by_reader_id( $reader_id );

        if( $reader_node === FALSE ){
            //TODO: return result object
            scoga_throw_exception( 'RFID reader not registered' );
        }

        $uids = scoga_get_player_uids_by_card_id( $card_id );
        if( $uids ){
            //TODO: return result object
            scoga_throw_exception( 'RFID card already registered' );
        }

        //TODO: replace scoga_get_next_team
        $result = scoga_create_player_entity( $card_id, scoga_get_next_team() );
        return $result;

    }
