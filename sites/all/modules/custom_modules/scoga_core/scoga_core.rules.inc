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
    function scoga_transfer_transaction_points_to_team( $transaction ){
        if( $transaction->tid === userpoints_get_default_tid() ){
            module_load_include( 'api.campaign.inc', 'scoga_core' );
            $user_account = user_load( $transaction->uid );
            $team_nid = $user_account->field_user_team[ LANGUAGE_NONE ][ 0 ][ 'target_id' ];
            $campaignteam_node = scoga_get_campaignteam_entity_by_team_nid( $team_nid );
            if( $campaignteam_node ){
                $campaignteam_node->field_campaignteam_totalpoints[ LANGUAGE_NONE ][ 0 ][ 'value' ] += $transaction->points;
                node_save( $campaignteam_node );
            }
        }
    }