<?php
    /**
     * Invoked from rules, i.e. rule handlers
     * rule wiring happens in the rules themselves, i.e. hard-coded includes
     *
     *
     * User: creynder
     * Date: 25/04/12
     * Time: 11:23
     * To change this template use File | Settings | File Templates.
     */

    /**
     * @param $transaction
     * stdClass Object
    (
    [points] => 1
    [tid] => 4
    [uid] => 2
    [operation] => userpoints_nc_node_insert
    [entity_id] => 226
    [entity_type] => node
    [description] =>
    [reference] =>
    [display] =>
    [status] => 0
    [expired] =>
    [parent_txn_id] =>
    [expirydate] => 0
    [time_stamp] => 1335345899
    [changed] => 1335345899
    [txn_id] => 178
    [approver_uid] => 0
     */
    function scoga_rule_transfer_transaction_points_to_team( $transaction ){
//        module_load_include( 'api.transaction.inc', 'scoga', 'api/scoga' );
//        scoga_transfer_transaction_points_to_team( $transaction );
    }

    function scoga_rule_determine_current_campaign(){
//        module_load_include( 'api.campaign.inc', 'scoga', 'api/scoga' );
//        scoga_determine_current_campaign();
    }

    function scoga_rule_create_campaignteam_nodes_for_campaign( $campaign_node ){
//        module_load_include( 'api.campaign.inc', 'scoga', 'api/scoga' );
//        scoga_create_campaignteam_nodes_for_campaign( $campaign_node );
    }

    function scoga_rule_delete_campaignteam_nodes_for_campaign( $campaign_node ){
//        module_load_include( 'api.campaign.inc', 'scoga', 'api/scoga' );
//        scoga_delete_campaignteam_nodes_for_campaign( $campaign_node );
    }

    function scoga_rule_log_user_points( $transaction ){
//        module_load_include( 'api.message.inc', 'scoga', 'api/scoga' );
//        $options = array(
//                    'link'             => FALSE,
//                    'truncate'         => FALSE,
//                    'skip_description' => FALSE,
//        );
//        $description = userpoints_create_description( $transaction, $options );
//        scoga_create_message_entity( $description, t( 'Points transaction' ), $transaction->uid, $transaction->points );
    }

    function scoga_rule_close_wisheditems(){
//        module_load_include( 'api.wisheditem.inc', 'scoga', 'api/scoga' );
//        scoga_close_all_open_wisheditems();
     }