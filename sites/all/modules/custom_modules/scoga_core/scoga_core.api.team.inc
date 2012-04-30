<?php
    /**
     * Created by JetBrains PhpStorm.
     * User: creynder
     * Date: 20/04/12
     * Time: 14:24
     * To change this template use File | Settings | File Templates.
     */

    function scoga_get_team_vos_by_UUIDs( $team_UUIDs ){
        return scoga_get_output( $team_UUIDs, 'scoga_get_team_vo_by_UUID' );
    }

    function scoga_get_team_vo_by_UUID( $team_UUID ){
        $team_nid = scoga_get_eid_by_uuid( $team_UUID );
        if( $team_nid ){
            return scoga_get_team_vo_by_nid( $team_nid );
        }

        return FALSE;
    }

    function scoga_get_team_vos_by_nids( $team_nids ){
        return scoga_get_output( $team_nids, 'scoga_get_team_vo_by_nid' );
    }

    function scoga_get_team_vo_by_nid( $team_nid ){
        module_load_include( 'api.player.inc', 'scoga_core' );
        $team_node = node_load( $team_nid );
        if( $team_node ){
            $player_uids = scoga_get_player_uids_by_team_nid( $team_nid );
            $team_obj = scoga_create_team_vo( $team_node );
            $team_obj[ 'players' ] = scoga_get_player_vos_by_uids( $player_uids );
            return $team_obj;
        }

        return FALSE;
    }

    function scoga_create_team_vo( $team_node ){
        $colour_values =field_get_items( 'node', $team_node, 'field_team_colour' );
        $output = array(
            'nid'               => $team_node->nid,
            'uuid'              => $team_node->uuid,
            'title'             => $team_node->title,
            'colour'            => $colour_values[ 0 ][ 'value' ],
        );

        return $output;
    }

