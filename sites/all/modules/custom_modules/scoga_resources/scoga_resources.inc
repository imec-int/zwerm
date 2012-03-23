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
function create_checkin( $params ){
    watchdog('SCOGA', 'create checkin' );

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
        _throw_fatal_error( 'user @uid not allowed to create checkin', array(
            '@uid' => $user_account->uid,
        ) );
    }

    $cooldown_tstamp = _get_cooldown_timestamp( $user_account->uid );
    if( time() < $cooldown_tstamp ){
        _throw_fatal_error( 'checkin not created for user with id @uid, will be cooled down on @cooldown_date', array(
            '@uid' => $user_account->uid,
            '@cooldown_date' => date( 'd/m/Y H:i:s', $cooldown_tstamp ),
        ) );
    }

    /*
     * get reader node
     */
    $reader_node = _retrieve_reader_node_by_reader_id( $reader_id );

    if( ! $reader_node ){
        _throw_fatal_error( 'RFID reader with id @reader_id not found', array(
            '@reader_id' => $reader_id,
        ) );
    }

    /*
     * create checkin node
     */
    $checkin_node = _create_checkin_node( $lang, $user_account, $reader_node );

    return $checkin_node;
}

/**
 * attempts to create a RFID reader node
 * @param $params
 */
function register_reader( $params ){

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
        _throw_fatal_error('user not allowed to register reader');
    }


    /*
     * check that the RFID reader IS registered
     */
    $reader_node = _retrieve_reader_node_by_reader_id( $reader_id );

    if( $reader_node ){
        _throw_fatal_error( 'RFID reader already registered' );
    }

    $reader_node = _create_rfid_reader( $reader_id, $user_account->uid );

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
        _throw_fatal_error( 'RFID reader not registered' );
    }

    $uids = _retrieve_uids_by_card_id( $card_id );
    if( $uids > 0 ){
        _throw_fatal_error( 'RFID card already registered' );
    }

    return _create_kliek_user( $card_id, SCOGA_DEFAULT_TEAM );

}

function _throw_fatal_error($message, $variables = NULL )
{
    watchdog('SCOGA', $message, $variables, WATCHDOG_ERROR);
    throw new Exception($message);
}

function _get_cooldown_timestamp( $uid ){
    $entity_type = 'node';
    $query = new EntityFieldQuery();


    //get last swipe
    $result = $query
        ->entityCondition( 'entity_type', $entity_type )
        ->entityCondition( 'bundle', SCOGA_CHECKIN_NODETYPE )
        ->propertyCondition( 'uid', $uid )
        ->propertyOrderBy( 'created', 'DESC' )
        ->range( 0, 1 )
        ->execute();

    $nids = array_keys($result[ $entity_type ]);
    if( $nids ){
        $cooldown_period = variable_get( 'scoga_settings_checkins_cooldown' );
        $node = node_load( $nids[ 0 ] );
        return intval( $node->created ) + intval( $cooldown_period );
    }

    return 0;
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
            _throw_fatal_error( 'card registered multiple times' );
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
            _throw_fatal_error( 'RFID reader registered multiple times' );
        }
    }
}
/**
 * get reader nids by RFID reader ID
 * @param $reader_id
 * @return array
 */
function _retrieve_reader_nids_by_reader_id( $reader_id ){
    $entity_type = 'node';
    $reader_query = new EntityFieldQuery();

    //get reader node by RFID reader ID
    $reader_entities = $reader_query
        ->entityCondition( 'entity_type', $entity_type )
        ->entityCondition( 'bundle', SCOGA_READER_NODETYPE )
        ->fieldCondition( 'field_reader_id', 'value', $reader_id, '=', 0 )
        ->execute();

    //possible multiple matches
    return array_keys( $reader_entities[ $entity_type ] );
}

function _create_checkin_node( $lang, $user_account, $reader_node ){

    $user_registered = (
        isset( $user_account->field_user_registered )
        && $user_account->field_user_registered[ $lang ][ 0 ][ 'value' ] == "1"
    );

    $checkin_node = new stdClass();
    $checkin_node->type = SCOGA_CHECKIN_NODETYPE;
    node_object_prepare( $checkin_node );

    $checkin_time_formatted = date( SCOGA_TIME_FORMAT, $checkin_node->created );

    //required fields
    $checkin_node->uid = $user_account->uid;
    $checkin_node->language = $lang;

    //optional fields
    //reader reference
    $checkin_node->field_reader_reference[ $lang ][ 0 ] = array(
        'nid' => $reader_node->nid
    );

    //title
    $checkin_node->title = $user_account->name
        . ' checked in with ' . $reader_node->title
        . ' at ' . $checkin_time_formatted;

    //published or not
    $checkin_node->status= ( $user_registered ) ? "1" : "0";

    //save the mofo node
    $checkin_node = node_submit( $checkin_node );
    node_save( $checkin_node );


    return $checkin_node;
}

function _create_rfid_reader( $reader_id, $uid ){
    $reader_node = new stdClass();
    $reader_node->type = SCOGA_READER_NODETYPE;
    node_object_prepare( $reader_node );
    $reader_node->uid = $uid;
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