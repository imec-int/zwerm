<?php
/**
 * Created by JetBrains PhpStorm.
 * User: creynder
 * Date: 11/04/12
 * Time: 14:28
 * To change this template use File | Settings | File Templates.
 */
define( 'SCOGA_CAMPAIGNTEAM_NODETYPE', 'nodetype_campaign_team' );

function get_data_for_campaign($campaign_uuid)
{
    $campaign_nid = _get_nid_by_uuid( $campaign_uuid );
    if( ! $campaign_nid ){
        return '"data not found for ' . $campaign_uuid . '"';
    }
    $team_nids = _get_team_nids_by_campaign_nid( $campaign_nid );

    $teams = array();
    foreach( $team_nids as $team_nid ){
        $teams[] = node_load( $team_nid );
        $player_nids = _get_players_for_team( $team_nid );
    }
    $campaign_node = node_load( $campaign_nid );
    return $campaign_uuid;
}


function _get_nid_by_uuid( $uuid ){
    $query = new EntityFieldQuery();
    $entity_type = 'node';
    $result = $query
        ->entityCondition( 'entity_type', $entity_type )
        ->propertyCondition( 'uuid', $uuid )
        ->range( 0, 1 )
        ->execute();

    $nids = array_keys($result[ $entity_type ]);
    if( $nids ){
        return $nids[ 0 ];
    }

    return FALSE;
}

function _get_team_nids_by_campaign_nid( $campaignteam_nid ){

    $query =
        "SELECT field_campaignteam_team_target_id "
        . "FROM {field_data_field_campaignteam_team} team "
        . "JOIN {field_data_field_campaignteam_campaign} campaign "
        . "ON team.entity_id = campaign.entity_id "
        . "WHERE campaign.field_campaignteam_campaign_target_id = :target_nid"
    ;
    $result = db_query( $query, array(':target_nid' => $campaignteam_nid) );
    $nids = array();
    foreach( $result as $row ){
        $nids[] = $row->field_campaignteam_team_target_id;
    }

    return $nids;
}

function _get_players_for_team( $team_nid ){
    dd( $team_nid );
    $query = new EntityFieldQuery();
    $entity_type = 'user';
    $result = $query
        ->entityCondition( 'entity_type', $entity_type )
        ->fieldCondition( 'field_user_team', 'target_id', $team_nid, '=' )
        ->execute();

    $nids = array_keys($result[ $entity_type ]);
    dd( $nids );
    if( $nids ){
        return $nids[ 0 ];
    }
}


//POTENTIALLY USEFUL SHIZZLE

    /*
     *
     *
    $query = new EntityFieldQuery();
    $entity_type = 'node';
    $result = $query
        ->entityCondition( 'entity_type', $entity_type )
        ->entityCondition( 'bundle', SCOGA_CAMPAIGNTEAM_NODETYPE )
        ->fieldCondition( 'field_campaignteam_campaign', 'target_id', $campaignteam_nid, '=' )
        ->execute();

    $campaignteam_nids = array_keys($result[ $entity_type ]);
    if( $campaignteam_nids ){
        $campaignteam_nodes = array();
        foreach( $campaignteam_nids as $key => $campaignteam_nid ){
           $campaignteam_nodes[] = node_load( $campaignteam_nid );
        }
        dd( $campaignteam_nodes );
    }

        */
