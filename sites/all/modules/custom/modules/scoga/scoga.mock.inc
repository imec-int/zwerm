<?php
/**
 * Camille Reynders, http://www.creynders.be
 * 09/11/12 - 10:40
 */

function scoga_mock_award_random_points(){
    module_load_include( 'api.player.inc', 'scoga', 'api/scoga' );
    $uids = scoga_get_all_player_uids();
    module_load_include( 'api.points.inc', 'scoga', 'api/scoga' );
    foreach( $uids as $uid ){
        $points = rand( 1, 100 );
        scoga_award_points_to_user( $uid, $points, 'mock' );
    }
}