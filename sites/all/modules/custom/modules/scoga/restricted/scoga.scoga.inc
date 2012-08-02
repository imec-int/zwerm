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



        module_load_include( 'api.player.inc', 'scoga', 'api/scoga' );
        scoga_award_default_credits_to_all_players();
        watchdog( 'SCOGA', 'all players default credits awarded', array(), WATCHDOG_INFO );

        module_load_include( 'api.checkin.inc', 'scoga', 'api/scoga' );
        $campaign_node = node_load( $new_nid );
        scoga_create_combocheckin_relationship( $campaign_node->title );
        watchdog( 'SCOGA', 'created new combo checkin relationship', array(), WATCHDOG_INFO );

//        scoga_assign_random_teams_to_players();
//        watchdog( 'SCOGA', 'all teams randomized', array(), WATCHDOG_INFO );

//        scoga_reset_user_relationships();
//        watchdog( 'SCOGA', 'all user relationships deleted', array(), WATCHDOG_INFO );

//        module_load_include( 'api.wisheditem.inc', 'scoga', 'api/scoga' );
//        scoga_close_all_open_wisheditems();
//        watchdog( 'SCOGA', 'all wished items closed', array(), WATCHDOG_INFO );
    }

