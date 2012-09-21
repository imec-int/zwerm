<?php
/**
 * Camille Reynders, http://www.creynders.be
 * 05/09/12 - 11:30
 */

    class SyncData{
        public $time;
        public $campaignID;
        public $messages;
    }

    function scoga_get_sync_vo( $messageID = NULL ){
        module_load_include( 'api.message.inc', 'scoga', 'api/scoga' );
        $output = new SyncData();
        $output->time = scoga_get_current_time();
        $output->campaignID = scoga_get_current_campaign_nid();
        $output->messages = scoga_get_message_vos_after_nid( $messageID );
        return $output;
    }