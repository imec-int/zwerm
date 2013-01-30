<?php
/**
 * Created by JetBrains PhpStorm.
 * User: creynder
 * Date: 31/07/12
 * Time: 15:36
 * To change this template use File | Settings | File Templates.
 */


    function scoga_handle_scoga_current_campaign_started( $new_nid ){
        watchdog( 'SCOGA', 'scoga_handle_scoga_current_campaign_started', array(), WATCHDOG_DEBUG );

        //a campaign is active
        $new_campaign_node = node_load( $new_nid );

        _prepare_combo_checkins( $new_campaign_node );
        _prepare_userpoints( $new_campaign_node );
        _prepare_campaignteams( $new_campaign_node );

    }

    function scoga_handle_scoga_current_campaign_finished( $old_campaign_nid ){
        watchdog( 'SCOGA', 'scoga_handle_scoga_current_campaign_finished', array(), WATCHDOG_DEBUG );

        _finish_wisheditems( $old_campaign_nid );
        _finish_polls( $old_campaign_nid );
        _finish_userpoints( $old_campaign_nid );
    }

    function _finish_userpoints( $old_campaign_nid ){
        module_load_include( 'api.points.inc', 'scoga', 'api/scoga' );
        scoga_drop_credits_of_all_players();
        watchdog( 'SCOGA', 'all credits of players deleted', array(), WATCHDOG_DEBUG );
        scoga_reset_userpoints_totals();
        watchdog( 'SCOGA', 'all user points totals reset', array(), WATCHDOG_DEBUG );

        $userpoints_category_tid = scoga_get_current_userpoints_category_tid();

        $shown_on_profile = variable_get( USERPOINTS_CATEGORY_PROFILE_DISPLAY_TID );
        if( array_key_exists( $userpoints_category_tid, $shown_on_profile ) ){
            //$shown_on_profile[ $old_campaign_nid ] = 0;
            unset( $shown_on_profile[ $userpoints_category_tid ] );
            variable_set( USERPOINTS_CATEGORY_PROFILE_DISPLAY_TID, $shown_on_profile );
        }

        scoga_set_current_userpoints_category_tid( scoga_get_score_tid() );
    }

    function _finish_polls( $old_campaign_nid ){
        module_load_include( 'api.poll.inc', 'scoga', 'api/scoga' );
        scoga_close_all_active_polls_of_campaign( $old_campaign_nid );
        watchdog( 'SCOGA', 'all active polls closed', array(), WATCHDOG_INFO );
    }

    function _finish_wisheditems( $old_campaign_nid ){
        module_load_include( 'api.wishlist.inc', 'scoga', 'api/scoga' );
        scoga_close_all_open_wisheditems_of_campaign( $old_campaign_nid );
        watchdog( 'SCOGA', 'all wished items closed', array(), WATCHDOG_INFO );
    }

    function _prepare_campaignteams( $new_campaign_node ){
        module_load_include( 'api.team.inc', 'scoga', 'api/scoga' );
        scoga_create_campaignteam_entities_for_campaign( $new_campaign_node );
        watchdog( 'SCOGA', 'created new campaigntteam entities for new campaign', array(), WATCHDOG_INFO );
    }

    function _prepare_userpoints( $new_campaign_node ){
        module_load_include( 'api.points.inc', 'scoga', 'api/scoga' );
        scoga_award_default_credits_to_all_players();
        watchdog( 'SCOGA', 'all players default credits awarded', array(), WATCHDOG_INFO );

        $userpoints_category = scoga_create_userpoints_category( $new_campaign_node->title );
        scoga_set_current_userpoints_category_tid( $userpoints_category->tid );
        watchdog( 'SCOGA', 'created new user points category @name', array( '@name' => $userpoints_category->name ), WATCHDOG_INFO );

        $shown_on_profile = variable_get( USERPOINTS_CATEGORY_PROFILE_DISPLAY_TID );
        $shown_on_profile[ $userpoints_category->tid ] = $userpoints_category->tid;
        variable_set( USERPOINTS_CATEGORY_PROFILE_DISPLAY_TID, $shown_on_profile );
    }

    function _prepare_combo_checkins( $new_campaign_node ){
        module_load_include( 'api.checkin.inc', 'scoga', 'api/scoga' );
        $relationship_type = scoga_create_combocheckin_relationship_type( $new_campaign_node->title );
        scoga_set_current_combocheckin_rtid( $relationship_type->rtid );
        watchdog( 'SCOGA', 'created new combo checkin relationship', array(), WATCHDOG_INFO );
    }
