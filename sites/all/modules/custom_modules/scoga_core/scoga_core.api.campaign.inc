<?php
    /**
     * Created by JetBrains PhpStorm.
     * User: creynder
     * Date: 20/04/12
     * Time: 14:24
     * To change this template use File | Settings | File Templates.
     */


    function scoga_get_campaign_vos_by_UUIDs( $campaign_UUIDs ){
        return scoga_get_output( $campaign_UUIDs, 'scoga_get_campaign_vo_by_UUID' );
    }

    function scoga_get_campaign_vo_by_UUID( $campaign_UUID ){
        $campaign_nid = scoga_get_eid_by_uuid( $campaign_UUID );
        if( $campaign_nid ){
            return scoga_get_campaign_vo_by_nid( $campaign_nid );
        }

        return FALSE;
    }

    function scoga_get_campaign_vos_by_nids( $campaign_nids ){
        return scoga_get_output( $campaign_nids, 'scoga_get_campaign_vo_by_nid' );
    }

    function scoga_get_campaign_vo_by_nid( $campaign_nid ){
        $campaign_node = node_load( $campaign_nid );
        if( $campaign_node ){
            $team_objs = scoga_get_team_vos_by_campaign_nid( $campaign_nid );
            $campaign_obj = scoga_create_campaign_vo( $campaign_node, $team_objs );
            $campaign_obj[ 'teams' ] = $team_objs;
            return $campaign_obj;
        }

        return FALSE;
    }

    function scoga_create_campaign_vo( $campaign_node ){
        //dd( $campaign_node, 'campaign node');
        $lang = LANGUAGE_NONE;
        $begin_time_tstamp = $campaign_node->field_campaign_period[ $lang ][ 0 ][ 'value' ];
        $end_time_tstamp = $campaign_node->field_campaign_period[ $lang ][ 0 ][ 'value2' ];
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


    function scoga_get_team_vos_by_campaign_nid( $campaign_nid ){
        module_load_include( 'api.team.inc', 'scoga_core' );

        $query = new EntityFieldQuery();
        $entity_type = 'node';
        $result = $query
            ->entityCondition( 'entity_type', $entity_type )
            ->entityCondition( 'bundle', SCOGA_CAMPAIGNTEAM_NODETYPE )
            ->fieldCondition( 'field_campaignteam_campaign', 'target_id', $campaign_nid, '=' )
            ->execute();
        $campaignteam_nids = array_keys( $result[ $entity_type ] );
        $team_objs = array();
        foreach( $campaignteam_nids as $campaignteam_nid ){
            $campaignteam_node = node_load( $campaignteam_nid );
            $lang = $campaignteam_node->language;
            $team_nid = $campaignteam_node->field_campaignteam_team[ $lang ][ 0 ][ 'target_id' ];
            $team_obj = scoga_get_team_vo_by_nid( $team_nid );
            $team_obj[ 'total_points' ] = $campaignteam_node->field_campaignteam_totalpoints[ $lang ][ 0 ][ 'value' ];
            $team_obj[ 'points_modifier' ] = $campaignteam_node->field_campaignteam_modifier[ $lang ][ 0 ][ 'value' ];
            $team_objs[ ] = $team_obj;
        }
        return $team_objs;
    }

    function scoga_get_team_nids_by_campaign_nid( $campaign_nid ){

        $query =
            "SELECT field_campaignteam_team_target_id "
                . "FROM {field_data_field_campaignteam_team} team "
                . "JOIN {field_data_field_campaignteam_campaign} campaign "
                . "ON team.entity_id = campaign.entity_id "
                . "WHERE campaign.field_campaignteam_campaign_target_id = :target_nid";
        $result = db_query( $query, array( ':target_nid' => $campaign_nid ) );
        $nids = array();
        foreach( $result as $row ){
            $nids[ $row->field_campaignteam_team_target_id ] = $row->field_campaignteam_team_target_id;
        }

        return $nids;
    }

    function scoga_get_campaignteam_entity_by_team_nid( $team_nid, $campaign_nid = NULL ){
        if( $campaign_nid == NULL ){
            $campaign_nid = scoga_get_current_campaign_nid();
        }
        $query = new EntityFieldQuery();
        $entity_type = 'node';
        $result = $query
            ->entityCondition( 'entity_type', $entity_type )
            ->entityCondition( 'bundle', SCOGA_CAMPAIGNTEAM_NODETYPE )
            ->fieldCondition( 'field_campaignteam_team', 'target_id', $team_nid, '=' )
            ->fieldCondition( 'field_campaignteam_campaign', 'target_id', $campaign_nid, '=' )
            ->execute();
        if( $result ){
            $campaignteam_nids = array_keys( $result[ $entity_type ] );
            return node_load( $campaignteam_nids[ 0 ] );
        }
        return FALSE;
    }

    function scoga_determine_current_campaign(){
        $current_nid = scoga_get_current_campaign_nid();
        $query = new EntityFieldQuery();
        $entity_type = 'node';
        $now = time();
        $result = $query
            ->entityCondition( 'entity_type', $entity_type )
            ->entityCondition( 'bundle', SCOGA_CAMPAIGN_NODETYPE )
            ->fieldCondition( 'field_campaign_period', 'value', $now, '<=' )
            ->fieldCondition( 'field_campaign_period', 'value2', $now, '>' )
            ->execute();

        if( $result ){
            $partial_node = reset( $result[ $entity_type ] );
            $new_nid = $partial_node->nid;
        }else{
            $new_nid = 0;
        }
        if( $new_nid != $current_nid ){
            scoga_set_current_campaign_nid( $new_nid );
            watchdog( 'SCOGA', 'invoke scoga_core_current_campaign_changed');
            module_invoke_all( 'scoga_current_campaign_changed', $new_nid, $current_nid );
        }
    }

    function scoga_create_campaignteam_nodes_for_campaign( $campaign_node ){
        module_load_include( 'api.team.inc', 'scoga_core' );
        $team_nids = scoga_get_team_nids();
        foreach( $team_nids as $team_nid ){
            scoga_create_campaignteam_node( $campaign_node, node_load( $team_nid ) );
        }
    }

    function scoga_create_campaignteam_node( $campaign_node, $team_node ){
        $node = new stdClass();
        $node->type = SCOGA_CAMPAIGNTEAM_NODETYPE;
        node_object_prepare( $node );
        $node->field_campaignteam_campaign[ LANGUAGE_NONE ][ 0 ]= array(
            'target_id' => $campaign_node->nid,
        );
        $node->field_campaignteam_team[ LANGUAGE_NONE ][ 0 ]= array(
            'target_id' => $team_node->nid,
        );
        $node->title = $campaign_node->title . ' - ' . $team_node->title;
        $node->language = LANGUAGE_NONE;

        node_save( $node );
    }

    function scoga_delete_campaignteam_nodes_for_campaign( $campaign_node ){
        module_load_include( 'api.team.inc', 'scoga_core' );
        $entity_type = 'node';
        $query = new EntityFieldQuery();
        $result = $query
            ->entityCondition( 'entity_type', $entity_type )
            ->entityCondition( 'bundle', SCOGA_CAMPAIGNTEAM_NODETYPE )
            ->fieldCondition( 'field_campaignteam_campaign', 'target_id', $campaign_node->nid, '=' )
            ->execute()
        ;

        $nids = array_keys( $result[ $entity_type ] );

        foreach( $nids as $nid ){
            node_delete( $nid );
        }

    }
