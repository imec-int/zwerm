<?php
/**
 * Camille Reynders, http://www.creynders.be
 * 05/09/12 - 11:30
 */

    class SyncData{
        public $timeMS;
        public $campaignID;
        public $messages;
        public $transactions;
        public $relationships;
    }

    function scoga_get_sync_vo( $messageID = 0, $transactionID = 0, $relationshipID = 0 ){
        module_load_include( 'api.message.inc', 'scoga', 'api/scoga' );
        module_load_include( 'api.points.inc', 'scoga', 'api/scoga' );
        $output = new SyncData();
        $output->timeMS = scoga_get_current_time_MS();
        $output->campaignID = scoga_get_current_campaign_nid();
        $output->messages = scoga_get_message_vos_after_nid( $messageID );
        $output->points = scoga_get_transaction_vos_after_txnid( $transactionID );
        $output->relationships = scoga_get_relationship_vos_after_rid( $relationshipID );
        return $output;
    }