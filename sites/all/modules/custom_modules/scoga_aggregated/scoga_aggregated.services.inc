<?php
/**
 * Created by JetBrains PhpStorm.
 * User: creynder
 * Date: 08/05/12
 * Time: 11:37
 * To change this template use File | Settings | File Templates.
 */
    module_load_include( 'api.message.inc', 'scoga_aggregated' );

    function scoga_service_overview_index(){
        module_load_include( 'services.inc', 'scoga_core' );
        $output = array();
        $output[ 'campaign' ] = scoga_service_campaign_index();
        $output[ 'last_message_nid' ] = scoga_get_last_message_nid();
        return $output;
    }

    function scoga_service_message_index( $params ){
        $last_nid = ( array_key_exists( 'last_nid', $params ) )
            ? $params[ 'last_nid' ]
            : NULL
        ;
        return scoga_get_message_vos_after_nid( $last_nid );
    }