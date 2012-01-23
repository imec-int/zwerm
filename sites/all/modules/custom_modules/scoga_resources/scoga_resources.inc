<?php
/**
 * Created by JetBrains PhpStorm.
 * User: creynder
 * Date: 13/12/11
 * Time: 13:34
 * To change this template use File | Settings | File Templates.
 */

const SCOGA_TIME_FORMAT = 'H:i:s d/m/Y';
const SCOGA_DEFAULT_LANG = LANGUAGE_NONE;
const SCOGA_TEAM_NODETYPE = 'kliek_team';
const SCOGA_CHECKIN_NODETYPE = 'checkin';
const SCOGA_READER_NODETYPE = 'rfid_reader';

/**
 * Creates a node of type "Checkin", linked to a user account and a RFID reader node
 *
 * @param $params
 * @return stdClass|string
 */
function reader_checkin( $params ){
    watchdog('[SCOGA] reader checkin create', serialize( $params ) );

    $lang = SCOGA_DEFAULT_LANG;

    /*
     * catch parameters
     */
    $card_id = $params[ 'cardID' ];
    $reader_id = $params[ 'readerID' ];
    //$checkin_time_MS = $params[ 'timestamp' ];
    $checkin_time = time();

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
     * create checkin node
     */
    $checkin_node = _create_checkin_node( $lang, $user_account, $reader_node, $checkin_time );

    return $checkin_node;
}

/**
 * attempts to create a RFID reader node
 * @param $params
 */
function register_reader( $params ){
    watchdog('[SCOGA} register reader', serialize( $params ) );

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
function _create_kliek_user( $card_id ){
    $user_profile = new stdClass();
    $user_profile->name = 'kliek user '. $card_id;
    $user_profile->status = 1; //published
    $user_profile->mail = 'none';
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

function _create_checkin_node( $lang, $user_account, $reader_node, $checkin_time ){
    $checkin_time_formatted = date( SCOGA_TIME_FORMAT, $checkin_time );

    $user_registered = (
        isset( $user_account->field_user_registered )
        && $user_account->field_user_registered[ $lang ][ 0 ][ 'value' ] == "1"
    );

    $checkin_node = new stdClass();
    $checkin_node->type = SCOGA_CHECKIN_NODETYPE;
    node_object_prepare( $checkin_node );

    //required fields
    $checkin_node->uid = $user_account->uid;
    $checkin_node->language = $lang;

    //optional fields
    //user reference
    $checkin_node->field_user_reference[ $lang ][ 0 ] = array(
        'uid' => $user_account->uid
    );

    //reader reference
    $checkin_node->field_reader_reference[ $lang ][ 0 ] = array(
        'nid' => $reader_node->nid
    );

    //title
    $checkin_node->title = $user_account->name
        . ' checked in with ' . $reader_node->title
        . ' at ' . $checkin_time_formatted;

    //checkin time
    $checkin_node->field_checkin_time[ $lang ][ 0 ] = array(
        'value' => $checkin_time
    );

    //published or not
    $checkin_node->status= ( $user_registered ) ? "1" : "0";

    //save the mofo node
    $checkin_node = node_submit( $checkin_node );
    node_save( $checkin_node );


    return $checkin_node;
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