<?php
    /**
     * Created by JetBrains PhpStorm.
     * User: creynder
     * Date: 20/04/12
     * Time: 14:50
     * To change this template use File | Settings | File Templates.
     */


    function scoga_service_checkin_create( $params ){
        module_load_include( 'api.checkin.inc', 'scoga_rfid' );

        /*
        * catch parameters
        */
        $card_id = $params[ 'cardID' ];
        $reader_id = $params[ 'readerID' ];
        try{
            $result = scoga_register_checkin( $card_id, $reader_id );
        }catch ( Exception $e ){
            $message = $e->getMessage();
            watchdog( 'SCOGA', $message );
            $result = $e->getMessage();
        }
        return $result;
    }

    function scoga_service_reader_create( $params ){
        module_load_include( 'api.reader.inc', 'scoga_rfid' );
        /*
        * catch parameters
        */
        $card_id = $params[ 'cardID' ];
        $reader_id = $params[ 'readerID' ];
        //$checkin_timeMS = $params[ 'timestamp' ];

        try{
            $result = scoga_register_reader( $card_id, $reader_id );
        }catch ( Exception $e ){
            $message = $e->getMessage();
            watchdog( 'SCOGA', $message );
            $result = $e->getMessage();
        }

        return $result;
    }

    function scoga_service_card_create( $params ){
        module_load_include( 'api.card.inc', 'scoga_rfid' );
        /*
        * catch parameters
        */
        $card_id = $params[ 'cardID' ];
        $reader_id = $params[ 'readerID' ];

        try{
            $result = scoga_register_card( $card_id, $reader_id );
        }catch ( Exception $e ){
            $message = $e->getMessage();
            watchdog( 'SCOGA', $message );
            $result = $e->getMessage();
        }

        return $result;
    }

