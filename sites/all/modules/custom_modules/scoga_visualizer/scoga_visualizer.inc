<?php
/**
 * Created by JetBrains PhpStorm.
 * User: creynder
 * Date: 11/04/12
 * Time: 14:28
 * To change this template use File | Settings | File Templates.
 */

module_load_include( 'module', 'scoga_core' );


function _get_campaigns_by_UUIDs( $campaign_UUIDs ){
    return scoga_get_output( $campaign_UUIDs, '_get_campaign_by_UUID' );
}

function _get_campaign_by_UUID($campaign_UUID)
{
    $campaign_nid = scoga_get_eid_by_uuid( $campaign_UUID );
    if( $campaign_nid ){
        return _get_campaign_by_nid( $campaign_nid );
    }
}

function _get_campaigns_by_nids( $campaign_nids ){
    return scoga_get_output( $campaign_nids, '_get_campaign_by_nid' );
}

function _get_campaign_by_nid( $campaign_nid ){
    $campaign_node = node_load( $campaign_nid );
    if( $campaign_node ){
        $team_objs = _get_teams_by_campaign_nid( $campaign_nid );
        $campaign_obj = _create_campaign_object( $campaign_node, $team_objs );
        $campaign_obj[ 'teams' ] = $team_objs;
        return $campaign_obj;
    }
}



function _create_campaign_object( $campaign_node ){
    //dd( $campaign_node, 'campaign node');
    $lang = 'und';
    $begin_time_str = $campaign_node->field_campaign_period[ $lang ][ 0 ][ 'value' ];
    $begin_time_tstamp = strtotime( $begin_time_str );
    $end_time_str = $campaign_node->field_campaign_period[ $lang ][ 0 ][ 'value2' ];
    $end_time_tstamp = strtotime( $end_time_str );
    $output = array(
        'nid'               => $campaign_node->nid,
        'title'             => $campaign_node->title,
        'uuid'              => $campaign_node->uuid,
        'begin_date'        => $begin_time_tstamp,
        'end_date'          => $end_time_tstamp,
        'teams'             => NULL,
        'last_retrieved'    => time(),
    );
    return $output;
}

function _get_teams_by_campaign_nid( $campaign_nid ){
    $query = new EntityFieldQuery();
    $entity_type = 'node';
    $result = $query
        ->entityCondition( 'entity_type', $entity_type )
        ->entityCondition( 'bundle', SCOGA_CAMPAIGNTEAM_NODETYPE )
        ->fieldCondition( 'field_campaignteam_campaign', 'target_id', $campaign_nid, '=' )
        ->execute();
    $campaignteam_nids = array_keys($result[ $entity_type ]);
    $team_objs = array();
    foreach( $campaignteam_nids as $campaignteam_nid ){
        $campaignteam_node = node_load( $campaignteam_nid );
        $lang = $campaignteam_node->language;
        $team_nid = $campaignteam_node->field_campaignteam_team[ $lang ][ 0 ][ 'target_id' ];
        $team_obj = _get_team_by_nid( $team_nid );
        $team_obj[ 'total_points' ] = $campaignteam_node->field_campaignteam_totalpoints[ $lang ][ 0 ][ 'value' ];
        $team_obj[ 'points_modifier' ] = $campaignteam_node->field_campaignteam_modifier[ $lang ][ 0 ][ 'value' ];
        $team_objs[] = $team_obj;
    }
    return $team_objs;
}

function _get_team_nids_by_campaign_nid( $campaign_nid ){

    $query =
        "SELECT field_campaignteam_team_target_id "
        . "FROM {field_data_field_campaignteam_team} team "
        . "JOIN {field_data_field_campaignteam_campaign} campaign "
        . "ON team.entity_id = campaign.entity_id "
        . "WHERE campaign.field_campaignteam_campaign_target_id = :target_nid"
    ;
    $result = db_query( $query, array(':target_nid' => $campaign_nid) );
    $nids = array();
    foreach( $result as $row ){
        $nids[] = $row->field_campaignteam_team_target_id;
    }

    return $nids;
}

function _get_teams_by_UUIDs( $team_UUIDs ){
    return scoga_get_output( $team_UUIDs, '_get_team_by_UUID' );
}

function _get_team_by_UUID( $team_UUID ){
    $team_nid = scoga_get_eid_by_uuid( $team_UUID );
    if( $team_nid ){
        return _get_team_by_nid( $team_nid );
    }

}

function _get_teams_by_nids( $team_nids ){
    return scoga_get_output( $team_nids, '_get_team_by_nid' );
}

function _get_team_by_nid( $team_nid ){
    $team_node = node_load( $team_nid );
    if( $team_node ){
        $player_uids = _get_player_uids_by_team_nid( $team_nid );
        $team_obj = _create_team_object( $team_node );
        $team_obj[ 'players' ] = _get_players_by_uids( $player_uids );
        return $team_obj;
    }
}

function _create_team_object( $team_node ){
    $lang = 'und';
    $output = array(
        'nid'               => $team_node->nid,
        'uuid'              => $team_node->uuid,
        'title'             => $team_node->title,
        'colour'            => $team_node->field_team_colour[ $lang ][ 0 ][ 'value' ],
        'total_points'      => NULL,
        'points_modifier'   => NULL,
        'players'           => NULL,
    );

    return $output;
}

function _get_player_uids_by_team_nid( $team_nid ){
    $query = new EntityFieldQuery();
    $entity_type = 'user';
    $result = $query
        ->entityCondition( 'entity_type', $entity_type )
        ->fieldCondition( 'field_user_team', 'target_id', $team_nid, '=' )
        ->execute();

    $uids = array_keys($result[ $entity_type ]);
    return $uids;
}

function _get_players_by_UUIDs( $player_UUIDs ){
    return scoga_get_output( $player_UUIDs, '_get_player_by_UUID' );
}

function _get_player_by_UUID( $player_UUID ){
    $player_uid = scoga_get_eid_by_uuid( $player_UUID, 'user' );
    if( $player_uid ){
        return _get_player_by_uid( $player_uid );
    }
}

function _get_players_by_uids( $player_uids ){
    return scoga_get_output( $player_uids, '_get_player_by_uid' );
}

function _get_player_by_uid( $player_uid ){
    $player_profile = user_load( $player_uid );
    if( $player_profile ){
        $result = _create_player_object( $player_profile );
        $result = _inject_player_points( $result );
        return $result;
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
        'avatar_url'    => image_style_url( 'avatar_pinhead', $player_profile->picture->uri ),
        'points'        => 0,
    );
    return $output;
}


function _inject_player_points( $player ){

    //TODO: use userpoints_service method and filter out the relevant point categories,
    //now it returns ALL the user points
    //use: userpoints_get_current_points
    $query =
        "SELECT points "
        . "FROM {userpoints_total} "
        . "WHERE uid = :target_uid"
    ;
    $rows = db_query( $query, array(':target_uid' => $player[ 'uid' ] ) );

    foreach( $rows as $row ){
        $player[ 'points' ] += $row->points;
    }

    return $player;
}


function _get_transactions_in_range( $begin_time = NULL, $end_time = NULL ){

    if( $begin_time == NULL ){
        $begin_time = 0;
    }
    if( $end_time == NULL ){
        $end_time = time();
    }

    //dd( $begin_time, 'begin time');
    //dd( $end_time, 'end time' );

    $query  =
        " SELECT txn_id, time_stamp "
        . "FROM {userpoints_txn} "
        . "WHERE tid = :tid "
        . "AND time_stamp > :begin_time "
        . "AND time_stamp <= :end_time"
    ;
    $rows = db_query( $query, array(
        ':tid'          => SCOGA_SCORE_TID,
        ':begin_time'   => $begin_time,
        ':end_time'     => $end_time,
    ) );

    $options = array(
        'link' => FALSE,
        'truncate' => FALSE,
        'skip_description' => FALSE,
    );

    $result = array();
    foreach( $rows as $row ){
        $transaction = userpoints_transaction_load( $row->txn_id );
        $description = userpoints_create_description( $transaction, $options );
        $result[] = _create_transaction_object( $transaction, $description );
    }

    return $result;
}

function _create_transaction_object( $transaction, $description ){
    $output = array(
        'txn_id'        => $transaction->txn_id,
        'uid'           => $transaction->uid,
        'points'        => $transaction->points,
        'time_stamp'    => $transaction->time_stamp,
        'description'   => $description,
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
