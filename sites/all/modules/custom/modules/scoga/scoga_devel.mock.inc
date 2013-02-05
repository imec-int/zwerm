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

    function scoga_create_random_relationships( $relationships_per_team = 20 ){
        module_load_include( 'api.player.inc', 'scoga', 'api/scoga' );
        module_load_include( 'api.team.inc', 'scoga', 'api/scoga' );
        $team_nids = scoga_get_team_nids();
        $rtid = scoga_get_current_combocheckin_rtid();
        foreach( $team_nids as $team_nid ){
            $player_uids = scoga_get_player_uids_by_team_nid( $team_nid );
            $num_players = count( $player_uids );
            for( $i=0; $i<$relationships_per_team; $i++ ){
                $requester_index = rand( 0, $num_players -1 );
                $requestee_index = rand( 0, $num_players -1 );
                if( $requestee_index != $requester_index ){
                    $requester_uid = $player_uids[ $requester_index ];
                    $requestee_uid = $player_uids[ $requestee_index ];
                    $request = user_relationships_request_relationship( $requester_uid, $requestee_uid, $rtid, TRUE );
                }
            }
        }

//        module_load_include( 'api.player.inc', 'scoga', 'api/scoga' );
//        $uids = scoga_get_all_player_uids();
//        $rtid = scoga_get_current_combocheckin_rtid();
//        $num_uids = count( $uids );
//        for( $i=0; $i<$n; $i++ ){
//            $requester_index = rand( 0, $num_uids -1 );
//            $requestee_index = rand( 0, $num_uids -1 );
//            if( $requestee_index != $requester_index ){
//                $requester_uid = $uids[ $requester_index ];
//                $requestee_uid = $uids[ $requestee_index ];
//                $request = user_relationships_request_relationship( $requester_uid, $requestee_uid, $rtid, TRUE );
//            }
//        }
    }