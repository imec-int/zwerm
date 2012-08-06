<?php
/**
 * Created by JetBrains PhpStorm.
 * User: creynder
 * Date: 31/07/12
 * Time: 15:36
 * To change this template use File | Settings | File Templates.
 */

    function scoga_handle_scoga_current_campaign_changed( $new_nid, $current_nid ){

//        module_load_include( 'module', 'userpoints_reset' );
//        userpoints_reset_do();
//        watchdog( 'SCOGA', 'all user points reset due to campaign switch', array(), WATCHDOG_INFO );

        $campaign_node = node_load( $new_nid );

        module_load_include( 'api.player.inc', 'scoga', 'api/scoga' );
        scoga_award_default_credits_to_all_players();
        watchdog( 'SCOGA', 'all players default credits awarded', array(), WATCHDOG_INFO );

        module_load_include( 'api.checkin.inc', 'scoga', 'api/scoga' );
        $relationship_type = scoga_create_combocheckin_relationship_type( $campaign_node->title );
        scoga_set_current_combocheckin_rtid( $relationship_type->rtid );
        watchdog( 'SCOGA', 'created new combo checkin relationship', array(), WATCHDOG_INFO );

        $userpoints_category = scoga_create_userpoints_category( $campaign_node->title );
        scoga_set_current_userpoints_category_tid( $userpoints_category->tid );
        watchdog( 'SCOGA', 'created new user points category @name', array( '@name' => $userpoints_category->name ), WATCHDOG_INFO );

//        scoga_assign_random_teams_to_players();
//        watchdog( 'SCOGA', 'all teams randomized', array(), WATCHDOG_INFO );

//        scoga_reset_user_relationships();
//        watchdog( 'SCOGA', 'all user relationships deleted', array(), WATCHDOG_INFO );

//        module_load_include( 'api.wisheditem.inc', 'scoga', 'api/scoga' );
//        scoga_close_all_open_wisheditems();
//        watchdog( 'SCOGA', 'all wished items closed', array(), WATCHDOG_INFO );
    }

