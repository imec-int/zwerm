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
     * @return Result
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
            $result->message = t( 'RFID reader with id @reader_id not registered', array( '@reader_id' => $reader_id ) );
            $result->code = CODE_READER_UNREGISTERED;
            return $result;
        }

        module_load_include( 'api.player.inc', 'scoga', 'api/scoga' );
        $uids = scoga_get_player_uids_by_card_id( $card_id );
        if( $uids ){
            $result->message = t( 'RFID card with id @card_id already registered', array( '@card_id' => $card_id ) );
            $result->code = CODE_CARD_MULTIPLE;
            return $result;

        }

        module_load_include( 'api.team.inc', 'scoga', 'api/scoga' );
        $result->result = scoga_create_player_entity( $card_id );
        $result->code = CODE_CARD_REGISTRATION_SUCCESS;
        return $result;

    }
