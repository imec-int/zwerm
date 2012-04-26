<?php
    /**
     * Created by JetBrains PhpStorm.
     * User: creynder
     * Date: 25/04/12
     * Time: 11:23
     * To change this template use File | Settings | File Templates.
     */

    /**
     * called from rule
     *
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
        module_load_include( 'api.transaction.inc', 'scoga_core' );
        scoga_transfer_transaction_points_to_team( $transaction );
    }


    function scoga_rule_determine_current_campaign(){
        module_load_include( 'api.campaign.inc', 'scoga_core' );
        scoga_determine_current_campaign();
    }

