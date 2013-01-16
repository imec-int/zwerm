<?php
/**
 * Camille Reynders, http://www.creynders.be
 * 15/01/13 - 10:25
 */

    function scoga_handle_poll_cancel_vote( $poll_node ){
        module_load_include( 'api.points.inc', 'scoga', 'api/scoga' );
        global $user;
        $points = - scoga_get_field_value( $poll_node, 'field_poll_reward' );
        $reason = t( 'Canceled poll answer' );
        scoga_award_points_to_user( $user->uid, $points, $reason );
    }

    function scoga_handle_poll_save_vote( $poll_node, $choice ){
        module_load_include( 'api.points.inc', 'scoga', 'api/scoga' );
        global $user;
        $points = scoga_get_field_value( $poll_node, 'field_poll_reward' );
        $reason = t( 'Answered poll' );
        scoga_award_points_to_user( $user->uid, $points, $reason );
    }