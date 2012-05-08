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

    function scoga_service_campaign_index( $params = NULL ){
        module_load_include( 'api.campaign.inc', 'scoga_core' );
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
        module_load_include( 'api.team.inc', 'scoga_core' );
        if( array_key_exists( 'uuid', $params ) ){
            return scoga_get_team_vos_by_UUIDs( $params[ 'uuid' ] );
        }

        if( array_key_exists( 'nid', $params ) ){
            return scoga_get_team_vos_by_nids( $params[ 'nid' ] );
        }

        return FALSE;
    }

    function scoga_service_player_index( $params ){
        module_load_include( 'api.player.inc', 'scoga_core' );
        if( array_key_exists( 'uuid', $params ) ){
            return scoga_get_player_vos_by_UUIDs( $params[ 'uuid' ] );
        }

        if( array_key_exists( 'uid', $params ) ){
            return scoga_get_player_vos_by_uids( $params[ 'uid' ] );
        }

        return FALSE;
    }

    function scoga_service_transaction_index( $params ){
        module_load_include( 'api.transaction.inc', 'scoga_core' );
        $last_txnid = ( array_key_exists( 'last_txnid', $params ) ) ? $params[ 'last_txnid' ] : '0';
        return scoga_get_transaction_vos_by_txnid( $last_txnid );
    }