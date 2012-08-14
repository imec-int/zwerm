<?php
    /**
     * User: creynder
     * Date: 20/04/12
     * Time: 14:49
     */


    /**
     * @param $card_id
     * @param $reader_id
     *
     * @return bool|stdClass
     */
    function scoga_register_card( $card_id, $reader_id ){
        watchdog( 'SCOGA', 'scoga_register_card: @card_id, @reader_id', array( '@card_id' => $card_id, '@reader_id' => $reader_id ), WATCHDOG_NOTICE );

        $result = new Result();


        /*
        * check that the RFID reader IS registered
        */
        module_load_include( 'api.reader.inc', 'scoga', 'api/scoga' );
        $reader_node = scoga_get_reader_entity_by_reader_id( $reader_id );
        if( $reader_node === FALSE ){
            $result->message = 'RFID reader with id @reader_id not registered';
            $result->variables = array( '@reader_id' => $reader_id );
            return $result;
        }

        module_load_include( 'api.player.inc', 'scoga', 'api/scoga' );
        $uids = scoga_get_player_uids_by_card_id( $card_id );
        if( $uids ){
            $result->message = 'RFID card with id @card_id already registered';
            $result->variables = array( '@card_id' => $card_id );
            return $result;

        }

        module_load_include( 'api.team.inc', 'scoga', 'api/scoga' );
        $result = scoga_create_player_entity( $card_id );
        return $result;

    }
