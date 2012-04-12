<?php
/**
 * Created by JetBrains PhpStorm.
 * User: creynder
 * Date: 11/04/12
 * Time: 14:28
 * To change this template use File | Settings | File Templates.
 */

module_load_include( 'module', 'scoga_core' );

function _get_campaign_by_UUID($campaign_UUID)
{
    $campaign_nid = scoga_get_eid_by_uuid( $campaign_UUID );
    if( $campaign_nid ){
        return _get_campaign_by_nid( $campaign_nid );
    }
}

function _get_campaign_by_nid( $campaign_nid ){
    $campaign_node = node_load( $campaign_nid );
    if( $campaign_node ){
        $team_nids = _get_team_nids_by_campaign_nid( $campaign_nid );
        return _create_campaign_object( $campaign_node, $team_nids );
    }
}



function _create_campaign_object( $campaign_node, $team_nids ){
    $lang = $campaign_node->language || 'und';
    $begin_time_str = $campaign_node->field_campaign_period[ $lang ][ 0 ][ 'value' ];
    $begin_time_tstamp = strtotime( $begin_time_str );
    $end_time_str = $campaign_node->field_campaign_period[ $lang ][ 0 ][ 'value2' ];
    $end_time_tstamp = strtotime( $end_time_str );
    $output = array(
        'nid'           => $campaign_node->nid,
        'title'         => $campaign_node->title,
        'uuid'          => $campaign_node->uuid,
        'begin_date'    => $begin_time_tstamp,
        'end_date'      => $end_time_tstamp,
        'team_nids'     => $team_nids,
    );
    return $output;
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

function _get_team_by_UUID( $team_UUID ){
    $team_nid = scoga_get_eid_by_uuid( $team_UUID );
    if( $team_nid ){
        return _get_team_by_nid( $team_nid );
    }

}

function _get_team_by_nid( $team_nid ){
    $team_node = node_load( $team_nid );
    if( $team_node ){
        $player_uids = _get_player_uids_for_team( $team_nid );
        return _create_team_object( $team_node, $player_uids );
    }
}

function _create_team_object( $team_node, $player_uids ){
    $lang = $team_node->language || 'und';
    $output = array(
        'nid'       => $team_node->nid,
        'uuid'      => $team_node->uuid,
        'title'     => $team_node->title,
        'players'   => $player_uids
    );

    return $output;
}

function _get_player_uids_for_team( $team_nid ){
    $query = new EntityFieldQuery();
    $entity_type = 'user';
    $result = $query
        ->entityCondition( 'entity_type', $entity_type )
        ->fieldCondition( 'field_user_team', 'target_id', $team_nid, '=' )
        ->execute();

    $uids = array_keys($result[ $entity_type ]);
    return $uids;
}


function _get_player_by_UUID( $player_UUID ){
    $player_uid = scoga_get_eid_by_uuid( $player_UUID, 'user' );
    if( $player_uid ){
        return _get_player_by_uid( $player_uid );
    }
}

function _get_player_by_uid( $player_uid ){
    $player_profile = user_load( $player_uid );
    if( $player_profile ){
        return _create_player_object( $player_profile );
    }
}

function _create_player_object( $player_profile ){
    $lang = 'und';
    $output = array(
        'uid'           => $player_profile->uid,
        'username'      => $player_profile->name,
        'uuid'          => $player_profile->uuid,
        'registered'    => $player_profile->field_user_registered[ $lang ][ 0 ][ 'value' ],
        'team_nid'      => $player_profile->field_user_team[ $lang ][ 0 ][ 'target_id' ],
        'firstname'     => $player_profile->field_user_firstname[ $lang ][ 0 ][ 'value' ],
        'surname'       => $player_profile->field_user_surname[ $lang ][ 0 ][ 'value' ],
        'avatar_url'    => image_style_url( 'avatar_pinhead', $player_profile->picture->uri )
    );
    return $output;
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
