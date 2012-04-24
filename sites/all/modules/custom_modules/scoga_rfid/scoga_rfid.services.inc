<?php
/**
 * Created by JetBrains PhpStorm.
 * User: creynder
 * Date: 20/04/12
 * Time: 14:50
 * To change this template use File | Settings | File Templates.
 */



function scoga_rfid_checkin_resource_create( $params ){
    module_load_include( 'api.checkin.inc', 'scoga_rfid' );

    /*
     * catch parameters
     */
    $card_id = $params[ 'cardID' ];
    $reader_id = $params[ 'readerID' ];

    return scoga_register_checkin( $card_id, $reader_id );
}

function scoga_rfid_reader_resource_create( $params ){
    module_load_include( 'api.reader.inc', 'scoga_rfid' );
    /*
     * catch parameters
     */
    $card_id = $params[ 'cardID' ];
    $reader_id = $params[ 'readerID' ];
    //$checkin_timeMS = $params[ 'timestamp' ];

    return scoga_register_reader( $card_id, $reader_id );
}

function scoga_rfid_card_resource_create( $params ){
    module_load_include( 'api.card.inc', 'scoga_rfid' );
    /*
     * catch parameters
     */
    $card_id = $params[ 'cardID' ];
    $reader_id = $params[ 'readerID' ];

    return scoga_register_card( $card_id, $reader_id );
}

