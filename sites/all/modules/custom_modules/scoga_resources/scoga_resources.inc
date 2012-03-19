<?php
/**
 * Created by JetBrains PhpStorm.
 * User: creynder
 * Date: 13/12/11
 * Time: 13:34
 * To change this template use File | Settings | File Templates.
 */


/**
 * Creates a node of type "RFID swipe", linked to a user account and a RFID reader node
 *
 * @param $params
 * @return stdClass|string
 */
function reader_swipe( $params ){
    watchdog('[SCOGA] reader swipe create', serialize( $params ) );

    $lang = SCOGA_DEFAULT_LANG;

    /*
     * catch parameters
     */
    $card_id = $params[ 'cardID' ];
    $reader_id = $params[ 'readerID' ];

    /*
     * get user account
     */
    $user_account = _retrieve_user_account_by_card_id( $card_id );
    if( $user_account === FALSE ) throw new Exception('card not registered' );

    /*
     * check if user has correct permissions
     *
     * NB:
     * permission string must be lower case,
     * see http://api.drupal.org/api/drupal/modules--user--user.module/function/user_access/7#comment-12914
     */

    if( user_access( strtolower( SCOGA_PERM_REST_EXECUTE_CREATE_CHECKIN ), $user_account ) === FALSE ){
        throw new Exception( 'user not allowed to create checkin' );
    }

    /*
     * get reader node
     */
    $reader_node = _retrieve_reader_node_by_reader_id( $reader_id );

    /*
     * create swipe node
     */
    $swipe_node = _create_swipe_node( $lang, $user_account, $reader_node );

    return $swipe_node;
}

/**
 * attempts to create a RFID reader node
 * @param $params
 */
function register_reader( $params ){
    watchdog('[SCOGA] register reader', serialize( $params ) );

    $lang = SCOGA_DEFAULT_LANG;

    /*
     * catch parameters
     */
    $card_id = $params[ 'cardID' ];
    $reader_id = $params[ 'readerID' ];
    //$checkin_timeMS = $params[ 'timestamp' ];

    /*
      * retrieve user account coupled to card id
      */
    $user_account = _retrieve_user_account_by_card_id( $card_id );
    if( user_access( strtolower( SCOGA_PERM_REST_EXECUTE_REGISTER_READER ), $user_account ) === FALSE ){
        throw new Exception( 'user not allowed to register reader' );
    }


    /*
     * check that the RFID reader IS registered
     */
    $reader_node = _retrieve_reader_node_by_reader_id( $reader_id );

    if( $reader_node ){
        throw new Exception( 'RFID reader already registered' );
    }

    $reader_node = _create_rfid_reader( $reader_id );

    return $reader_node;

}

/**
 * @param $params
 */
function register_card( $params ){
    $lang = SCOGA_DEFAULT_LANG;

    /*
     * catch parameters
     */
    $card_id = $params[ 'cardID' ];
    $reader_id = $params[ 'readerID' ];

    /*
     * check that the RFID reader IS registered
     */
    $reader_node = _retrieve_reader_node_by_reader_id( $reader_id );

    if( $reader_node === FALSE ){
        throw new Exception( 'RFID reader not registered' );
    }

    $uids = _retrieve_uids_by_card_id( $card_id );
    if( $uids > 0 ){
        throw new Exception( 'RFID card already registered' );
    }

    return _create_kliek_user( $card_id, SCOGA_DEFAULT_TEAM );

}

/**
 * @param $timeMS
 * @return int|string
 */
function _time_MS_to_SEC( $timeMS = null ){
    if( $timeMS ){
        return number_format( $timeMS / 1000, 0, '.', '' );
    }

    return time();
}

function _retrieve_user_account_by_card_id( $card_id ){
    $user_uids = _retrieve_uids_by_card_id( $card_id );
    switch( count( $user_uids ) ){
        case 1 : {
            //exactly one match, as it should
            return user_load( $user_uids[ 0 ] );
        }
        case 0 : {
            return FALSE;
        }
        default : {
            // multiple matches
            //TODO determine what to do with multiple matches
            throw new Exception( 'card registered multiple times' );
        }
    }
}

/**
 * retrieve user id's by card ID
 * @param $card_id
 * @return array
 */
function _retrieve_uids_by_card_id( $card_id ){
    $user_entity_type = 'user';
    $user_query = new EntityFieldQuery();

    //get user profile by card ID if possible
    $user_entities = $user_query
        ->entityCondition( 'entity_type', $user_entity_type )
        ->fieldCondition( 'field_card_id', 'value', $card_id, '=', 0 )
        ->execute();

    return array_keys( $user_entities[ $user_entity_type ] );

}

/**
 * create a kliek user
 * @param $card_id
 * @return bool|stdClass
 */
function _create_kliek_user( $card_id, $team_nid ){
    $user_profile = new stdClass();
    $user_profile->name = 'kliek user '. $card_id;
    $user_profile->status = 0; //published
    $user_profile->mail = 'none';
    $user_profile->field_team_reference[ SCOGA_DEFAULT_LANG ][ 0 ] = array(
        'nid' => $team_nid
    );
    $user_profile->roles = array(
        2 => 'authenticated user',
        4 => 'kliek user'
    );
    $user_profile->field_card_id[ SCOGA_DEFAULT_LANG ][ 0 ] = array(
        'value' => $card_id
    );

    return user_save( $user_profile );
}

function  _retrieve_reader_node_by_reader_id( $reader_id ){
    $reader_nids = _retrieve_reader_nids_by_reader_id( $reader_id );
//
    switch( count( $reader_nids ) ){
        case 1 : {
            //exactly one match, as it should
            return node_load( $reader_nids[ 0 ] );
            break;
        }
        case 0 : {
            return FALSE;
        }
        default : {
            return new Exception( 'RFID reader registered multiple times' );
        }
    }
}
/**
 * get reader nids by RFID reader ID
 * @param $reader_id
 * @return array
 */
function _retrieve_reader_nids_by_reader_id( $reader_id ){
    $reader_entity_type = 'node';
    $reader_query = new EntityFieldQuery();

    //get reader node by RFID reader ID
    $reader_entities = $reader_query
        ->entityCondition( 'entity_type', $reader_entity_type )
        ->fieldCondition( 'field_reader_id', 'value', $reader_id, '=', 0 )
        ->execute();

    //possible multiple matches
    return array_keys( $reader_entities[ $reader_entity_type ] );
}

function _create_swipe_node( $lang, $user_account, $reader_node ){

    $user_registered = (
        isset( $user_account->field_user_registered )
        && $user_account->field_user_registered[ $lang ][ 0 ][ 'value' ] == "1"
    );

    $swipe_node = new stdClass();
    $swipe_node->type = SCOGA_SWIPE_NODETYPE;
    node_object_prepare( $swipe_node );

    $checkin_time_formatted = date( SCOGA_TIME_FORMAT, $swipe_node->created );

    //required fields
    $swipe_node->uid = $user_account->uid;
    $swipe_node->language = $lang;

    //optional fields
    //reader reference
    $swipe_node->field_reader_reference[ $lang ][ 0 ] = array(
        'nid' => $reader_node->nid
    );

    //title
    $swipe_node->title = $user_account->name
        . ' checked in with ' . $reader_node->title
        . ' at ' . $checkin_time_formatted;

    //published or not
    $swipe_node->status= ( $user_registered ) ? "1" : "0";

    $swipe_node->field_term_playeraction[ $lang ][ 0 ] = array(
        'tid' => SCOGA_CHECKIN_TID
    );

    //save the mofo node
    $swipe_node = node_submit( $swipe_node );
    node_save( $swipe_node );


    return $swipe_node;
}

function _create_rfid_reader( $reader_id ){
    $reader_node = new stdClass();
    $reader_node->type = SCOGA_READER_NODETYPE;
    node_object_prepare( $reader_node );
    $reader_node->language = LANGUAGE_NONE;
    $reader_node->title = 'RFID reader ' . $reader_id;
    $reader_node->field_reader_id[ LANGUAGE_NONE ][ 0 ] = array(
        'value' => $reader_id
    );

    //node_save will contrary to user_save NOT return the node object
    //but $reader_node is passed by reference, so it WILL contain the new nid
    node_save( $reader_node );

    return $reader_node;
}

function _retrieve_team_node_by_nid( $nid ){

    $team_node = node_load( $nid );
    if( $team_node && $team_node->type == SCOGA_TEAM_NODETYPE ){
        return $team_node;
    }

    return FALSE;

}