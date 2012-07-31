<?php
/**
 * Created by JetBrains PhpStorm.
 * User: creynder
 * Date: 31/07/12
 * Time: 16:02
 * To change this template use File | Settings | File Templates.
 */

    function scoga_handle_rule_transfer_transaction_points_to_team( $transaction ){
        module_load_include( 'scoga.api.transaction.inc', 'scoga', 'api/' );
        scoga_transfer_transaction_points_to_team( $transaction );
    }

    function scoga_handle_rule_determine_current_campaign(){
        module_load_include( 'scoga.api.campaign.inc', 'scoga', 'api/' );
        scoga_determine_current_campaign();
    }

    function scoga_handle_rule_create_campaignteam_nodes_for_campaign( $campaign_node ){
        module_load_include( 'scoga.api.campaign.inc', 'scoga', 'api/' );
        scoga_create_campaignteam_nodes_for_campaign( $campaign_node );
    }

    function scoga_handle_rule_delete_campaignteam_nodes_for_campaign( $campaign_node ){
        module_load_include( 'scoga.api.campaign.inc', 'scoga', 'api/' );
        scoga_delete_campaignteam_nodes_for_campaign( $campaign_node );
    }