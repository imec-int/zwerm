<?php
/**
 * Created by JetBrains PhpStorm.
 * User: creynder
 * Date: 20/04/12
 * Time: 14:49
 * To change this template use File | Settings | File Templates.
 */


/**
 * @param $params
 */
function scoga_register_card( $card_id, $reader_id ){
    module_load_include( 'api.reader.inc', 'scoga_rfid' );
    module_load_include( 'api.player.inc', 'scoga_core' );

    $lang = LANGUAGE_NONE;

    /*
     * check that the RFID reader IS registered
     */
    $reader_node = scoga_get_reader_entity_by_reader_id( $reader_id );

    if( $reader_node === FALSE ){
        scoga_throw_fatal_error( 'RFID reader not registered' );
    }

    $uids = scoga_get_player_uids_by_card_id( $card_id );
    if( $uids ){
        scoga_throw_fatal_error( 'RFID card already registered' );
    }


    //TODO: default team should be set through admin UI
    return scoga_create_player_entity( $card_id, SCOGA_DEFAULT_TEAM );

}
