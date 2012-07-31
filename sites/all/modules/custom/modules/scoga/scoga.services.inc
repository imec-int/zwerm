<?php
    /**
     * Created by JetBrains PhpStorm.
     * User: creynder
     * Date: 20/04/12
     * Time: 14:41
     * To change this template use File | Settings | File Templates.
     *
     * Invoked from services
     */

    function scoga_service_campaign_index( $params = array() ){
        watchdog( 'SCOGA', 'scoga_service_campaign_index: @params', array( '@params' => implode( ', ', $params ) ), WATCHDOG_DEBUG );
        module_load_include( 'api.campaign.inc', 'scoga' );
        if( $params ){
            if( array_key_exists( 'uuid', $params ) ){
                return scoga_get_campaign_vos_by_UUIDs( $params[ 'uuid' ] );
            }

            if( array_key_exists( 'nid', $params ) ){
                return scoga_get_campaign_vos_by_nids( $params[ 'nid' ] );
            }
        }
        return scoga_get_campaign_vo_by_nid( scoga_get_current_campaign_nid() );
    }

    function scoga_service_team_index( $params ){
        watchdog( 'SCOGA', 'scoga_service_team_index: @params', array( '@params' => implode( ', ', $params ) ), WATCHDOG_DEBUG );
        module_load_include( 'api.team.inc', 'scoga' );
        if( array_key_exists( 'uuid', $params ) ){
            return scoga_get_team_vos_by_UUIDs( $params[ 'uuid' ] );
        }

        if( array_key_exists( 'nid', $params ) ){
            return scoga_get_team_vos_by_nids( $params[ 'nid' ] );
        }

        return FALSE;
    }

    function scoga_service_player_index( $params ){
        watchdog( 'SCOGA', 'scoga_service_player_index: @params', array( '@params' => implode( ', ', $params ) ), WATCHDOG_DEBUG );
        module_load_include( 'api.player.inc', 'scoga' );
        if( array_key_exists( 'uuid', $params ) ){
            return scoga_get_player_vos_by_UUIDs( $params[ 'uuid' ] );
        }

        if( array_key_exists( 'uid', $params ) ){
            return scoga_get_player_vos_by_uids( $params[ 'uid' ] );
        }

        return FALSE;
    }

    function scoga_service_transaction_index( $params ){
        watchdog( 'SCOGA', 'scoga_service_transaction_index: @params', array( '@params' => implode( ', ', $params ) ), WATCHDOG_DEBUG );
        module_load_include( 'api.transaction.inc', 'scoga' );
        $last_txnid = ( array_key_exists( 'last_txnid', $params ) ) ? $params[ 'last_txnid' ] : '0';
        return scoga_get_transaction_vos_by_txnid( $last_txnid );
    }
    
    function scoga_service_overview_index(){
        watchdog( 'SCOGA', 'scoga_service_overview_index', NULL, WATCHDOG_INFO );
    	module_load_include( 'api.message.inc', 'scoga' );
        $output = array();
        $output[ 'campaign' ] = scoga_service_campaign_index();
        $output[ 'last_message_nid' ] = scoga_get_last_message_nid();
        return $output;
    }

    function scoga_service_message_index( $params ){
        watchdog( 'SCOGA', 'scoga_service_message_index: @params', array( '@params' => implode( ', ', $params ) ), WATCHDOG_DEBUG );
    	module_load_include( 'api.message.inc', 'scoga' );
        $last_nid = ( array_key_exists( 'last_nid', $params ) )
            ? $params[ 'last_nid' ]
            : NULL
        ;
        return scoga_get_message_vos_after_nid( $last_nid );
    } 
    
    
    function scoga_service_checkin_create( $params ){
        watchdog( 'SCOGA', 'scoga_service_checkin_create: @params', array( '@params' => implode( ', ', $params ) ), WATCHDOG_INFO );
        module_load_include( 'api.checkin.inc', 'scoga' );

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
        watchdog( 'SCOGA', 'scoga_service_reader_create: @params', array( '@params' => implode( ', ', $params ) ), WATCHDOG_NOTICE );
        module_load_include( 'api.reader.inc', 'scoga' );
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
        watchdog( 'SCOGA', 'scoga_service_card_create: @params', array( '@params' => implode( ', ', $params ) ), WATCHDOG_NOTICE );
        module_load_include( 'api.card.inc', 'scoga' );
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

