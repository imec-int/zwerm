<?php
/**
 * Camille Reynders, http://www.creynders.be
 * 28/02/13 - 12:09
 */

    session_start();

    define( 'SESSION_NAME', 'zwerm_events');
    define( 'KEY_PASSPHRASE', 'passphrase' );
    define( 'KEY_EVENT_NID', 'event_nid' );
    define( 'SALT', '97zw3rM&:*' );

    function session_exists(){
        return (bool) $_SESSION && isset( $_SESSION[ SESSION_NAME ] );
    }

    function session_has_key( $key ){
        return session_exists() && isset( $_SESSION[ SESSION_NAME ][ $key ] ) && $_SESSION[ SESSION_NAME ][ $key ] != '';
    }

    function get_from_session( $key ){
        if( session_has_key( $key ) ){
            return $_SESSION[ SESSION_NAME ][ $key ];
        }

        return '';
    }

    function store_in_session( $key, $value ){
        ! session_exists() && $_SESSION[ SESSION_NAME ] = array();
        $_SESSION[ SESSION_NAME ][ $key ] = $value;
    }

    function transfer_from_post_to_session( $key ){
        if( $key ){
            store_in_session( $key, $_POST[ $key ] );
        }else{
            store_in_session( $key, '' );
        }
    }

    function clear_from_session( $key ){
        unset( $_SESSION[ SESSION_NAME ][ $key ] );
    }

    function post_has_key( $key ){
        return isset( $_POST[ KEY_PASSPHRASE ] );
    }

