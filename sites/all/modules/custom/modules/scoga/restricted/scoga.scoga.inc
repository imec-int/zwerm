<?php
/**
 * Created by JetBrains PhpStorm.
 * User: creynder
 * Date: 31/07/12
 * Time: 15:36
 * To change this template use File | Settings | File Templates.
 */

    function scoga_handle_scoga_current_campaign_changed( $new_nid, $old_nid ){
        watchdog( 'SCOGA', 'scoga_handle_scoga_current_campaign_changed', array(), WATCHDOG_DEBUG );
//        module_load_include( 'module', 'userpoints_reset' );
//        userpoints_reset_do();
//        watchdog( 'SCOGA', 'all user points reset due to campaign switch', array(), WATCHDOG_INFO );

        $new_campaign_node = node_load( $new_nid );

        module_load_include( 'api.player.inc', 'scoga', 'api/scoga' );
        scoga_award_default_credits_to_all_players();
        watchdog( 'SCOGA', 'all players default credits awarded', array(), WATCHDOG_INFO );

        module_load_include( 'api.checkin.inc', 'scoga', 'api/scoga' );
        $relationship_type = scoga_create_combocheckin_relationship_type( $new_campaign_node->title );
        scoga_set_current_combocheckin_rtid( $relationship_type->rtid );
        watchdog( 'SCOGA', 'created new combo checkin relationship', array(), WATCHDOG_INFO );

        module_load_include( 'api.points.inc', 'scoga', 'api/scoga' );
        $userpoints_category = scoga_create_userpoints_category( $new_campaign_node->title );
        scoga_set_current_userpoints_category_tid( $userpoints_category->tid );
        watchdog( 'SCOGA', 'created new user points category @name', array( '@name' => $userpoints_category->name ), WATCHDOG_INFO );

        module_load_include( 'api.wishlist.inc', 'scoga', 'api/scoga' );
        //TODO: should close 'm for the OLD campaign !!!
        scoga_close_all_open_wisheditems();
        watchdog( 'SCOGA', 'all wished items closed', array(), WATCHDOG_INFO );

        module_load_include( 'api.poll.inc', 'scoga', 'api/scoga' );
        scoga_close_all_active_polls_of_campaign( $old_nid );
        watchdog( 'SCOGA', 'all active polls closed', array(), WATCHDOG_INFO );

        module_load_include( 'api.team.inc', 'scoga', 'api/scoga' );
        scoga_create_campaignteam_entities_for_campaign( $new_campaign_node );
        watchdog( 'SCOGA', 'created new campaigntteam entities for new campaign', array(), WATCHDOG_INFO );
    }

