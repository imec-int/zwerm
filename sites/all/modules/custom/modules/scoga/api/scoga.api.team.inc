<?php
    /**
     * User: creynder
     * Date: 20/04/12
     * Time: 14:24
     */

    /**
     *
     */
    class Team{

        public $nid;
        public $title;
        public $colour;
        public $total_points;
        public $points_modifier;

    }

//    function scoga_get_team_vos_by_UUIDs( $team_UUIDs ){
//        return scoga_get_output( $team_UUIDs, 'scoga_get_team_vo_by_UUID' );
//    }
//
//    /**
//     * @param $team_UUID
//     *
//     * @return bool|Team
//     */
//    function scoga_get_team_vo_by_UUID( $team_UUID ){
//        $team_nid = scoga_get_eid_by_uuid( $team_UUID );
//        if( $team_nid ){
//            return scoga_get_team_vo_by_nid( $team_nid );
//        }
//
//        return FALSE;
//    }

    /**
     * @param $team_nids
     *
     * @return array
     */
    function scoga_get_team_vos_by_nids( $team_nids ){
        return scoga_get_output( $team_nids, 'scoga_get_team_vo_by_nid' );
    }

    /**
     * @param $team_nid
     *
     * @return bool|Team
     */
    function scoga_get_team_vo_by_nid( $team_nid ){
        module_load_include( 'api.player.inc', 'scoga', 'api/scoga' );
        $team_node = node_load( $team_nid );
        if( $team_node ){
            $team_obj = scoga_create_team_vo( $team_node );
            return $team_obj;
        }

        return FALSE;
    }

    /**
     * @param $team_node
     *
     * @return Team
     */
    function scoga_create_team_vo( $team_node ){
        $output = new Team();
        $output->nid = $team_node->nid;
        $output->colour = scoga_get_field_value( $team_node, 'field_team_colour' );
        $output->title = $team_node->title;
        return $output;
    }

    /**
     * @return array
     */
    function scoga_get_team_nids(){
        $entity_type = 'node';
        $query = new EntityFieldQuery();
        $result = $query
            ->entityCondition( 'entity_type', $entity_type )
            ->entityCondition( 'bundle', SCOGA_TEAM_NODETYPE )
            ->execute()
        ;
        $nids = array_keys( $result[ $entity_type ] );

        return $nids;
    }

//    function scoga_get_next_team(){
//        $nids = scoga_get_team_nids();
//        $index = array_search( scoga_get_current_team_nid(), $nids );
//        if( $index  >= count( $nids ) - 1 || $index === FALSE ){
//            $index = 0;
//        }else{
//            $index++;
//        }
//        $new_nid = $nids[ $index ];
//        scoga_set_current_team_nid( $new_nid );
//        return $new_nid;
//
//    }

    /**
     * @param $campaign_node
     */
    function scoga_create_campaignteam_entities_for_campaign( $campaign_node ){
        $team_nids = scoga_get_team_nids();
        foreach( $team_nids as $team_nid ){
            scoga_create_campaignteam_entity( $campaign_node, node_load( $team_nid ) );
        }
    }

    /**
     * @param $campaign_node
     * @param $team_node
     */
    function scoga_create_campaignteam_entity( $campaign_node, $team_node ){
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

    /**
     * @param $campaign_node
     */
    function scoga_delete_campaignteam_entities_for_campaign( $campaign_node ){
        $nids = scoga_get_campaignteam_nids_by_campaign_nid( $campaign_node->nid );

        foreach( $nids as $nid ){
            node_delete( $nid );
        }

    }

    /**
     * @param $campaign_nid
     *
     * @return array
     */
    function scoga_get_team_vos_by_campaign_nid( $campaign_nid ){
        $campaignteam_nids = scoga_get_campaignteam_nids_by_campaign_nid( $campaign_nid );
        $team_objs = array();
        foreach( $campaignteam_nids as $campaignteam_nid ){
            $campaignteam_node = node_load( $campaignteam_nid );
            $lang = $campaignteam_node->language;
            $team_nid = $campaignteam_node->field_campaignteam_team[ $lang ][ 0 ][ 'target_id' ];
            $team_obj = scoga_get_team_vo_by_nid( $team_nid );
            $team_obj->total_points = $campaignteam_node->field_campaignteam_totalpoints[ $lang ][ 0 ][ 'value' ];
            $team_obj->points_modifier = $campaignteam_node->field_campaignteam_modifier[ $lang ][ 0 ][ 'value' ];
            $team_objs[ ] = $team_obj;
        }
        return $team_objs;
    }

    /**
     * @param $campaign_nid
     *
     * @return array
     */
    function scoga_get_campaignteam_nids_by_campaign_nid( $campaign_nid ){
        $query = new EntityFieldQuery();
        $entity_type = 'node';
        $result = $query
            ->entityCondition( 'entity_type', $entity_type )
            ->entityCondition( 'bundle', SCOGA_CAMPAIGNTEAM_NODETYPE )
            ->fieldCondition( 'field_campaignteam_campaign', 'target_id', $campaign_nid, '=' )
            ->execute();
        $campaignteam_nids = array_keys( $result[ $entity_type ] );
        return $campaignteam_nids;
    }

    /**
     * @param $campaign_nid
     *
     * @return array
     */
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

    /**
     * @param      $team_nid
     * @param null $campaign_nid
     *
     * @return bool|mixed
     */
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
