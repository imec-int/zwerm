<?php
/**
 * Created by JetBrains PhpStorm.
 * User: creynder
 * Date: 13/12/11
 * Time: 13:34
 * To change this template use File | Settings | File Templates.
 */

function _reader_checkin_index( $params ){
    watchdog( '[SCOGA] reader checkin index', serialize($params));
    $view = views_get_view( 'checkins' );
   	$view->execute_display( 'default' );
   	$results = $view->result;
    return $results;
}

function _reader_checkin_create( $params ){
    watchdog('[SCOGA} reader checkin create', serialize( $params ) );

    $lang = LANGUAGE_NONE; //'en';

    /*
     * catch parameters
     */
    $card_id = $params[ 'cardID' ];
    $reader_id = $params[ 'readerID' ];
    $checkin_time = $params[ 'timestamp' ];

    /*
     * retrieve user profile by user ID
     */
    $user_entity_type = 'user';
    $user_query = new EntityFieldQuery();

    $user_entities = $user_query
        ->entityCondition( 'entity_type', $user_entity_type )
        ->fieldCondition( 'field_card_id', 'value', $card_id, '=', 0 )
        ->execute();

    //FYI: if you'd need the user data
    //$users = user_load_multiple( array_keys( $entities[ 'user' ] ) );

    $user_uids = array_keys( $user_entities[ $user_entity_type ] );

    //exit; should be distinct
    if( count( $user_uids ) != 1 ) return null;

    $user_profile = user_load( $user_uids[ 0 ] );

    /*
     * get reader node by RFID reader ID
     */
    $reader_entity_type = 'node';
    $reader_query = new EntityFieldQuery();

    $reader_entities = $reader_query
        ->entityCondition( 'entity_type', $reader_entity_type )
        ->fieldCondition( 'field_reader_id', 'value', $reader_id, '=', 0 )
        ->execute();

    $reader_nids = array_keys( $reader_entities[ $reader_entity_type ] );

    //exit; reader ID's should be unique for content type RFID reader
    if( count( $reader_nids ) != 1 ) return null;

    $reader_node = node_load( $reader_nids[ 0 ] );

    /*
     * create checkin node
     */
    $checkin_node = new stdClass();
    $checkin_node->type = 'checkin';
    node_object_prepare( $checkin_node );

    //required fields
    $checkin_node->uid = $user_profile->uid;
    $checkin_node->title = $user_profile->name
        . ' checked in with '
        . $reader_node->title;

    $checkin_node->language = $lang;

    //user reference
    $checkin_node->field_user_reference[ $lang ][ 0 ] = array(
        'uid' => $user_profile->uid
    );

    //reader reference
    $checkin_node->field_reader_reference[ $lang ][ 0 ] = array(
        'nid' => $reader_node->nid
    );


    //checkin time, if any
    if( $checkin_time ){
        $checkin_node->title .= ' at ' . date( 'H:i:s d/m/Y', intval( $checkin_time / 1000 ) );
        $checkin_node->field_checkin_time[ $lang ][ 0 ] = array(
            'value' => $checkin_time
        );
    }

    //save the mofo node
    $checkin_node = node_submit( $checkin_node );
    node_save( $checkin_node );

    return $checkin_node;
}