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
        //public $players;

    }

    class TeamPoints{
        public $timestamp;
        public $points;
    }

    /**
     * creates campaignteam nodes for all teams linked to a campaign
     * @param $campaign_node
     */
    function scoga_create_campaignteam_entities_for_campaign( $campaign_node ){
        $team_nids = scoga_get_team_nids();
        foreach( $team_nids as $team_nid ){
            $score = 0;
            $latest_campaignteam_node = scoga_get_latest_campaignteam_entity( $campaign_node->nid, $team_nid );
            if( $latest_campaignteam_node ){
                $score = scoga_get_field_value( $latest_campaignteam_node, 'field_campaignteam_totalpoints' );
            }
            scoga_create_campaignteam_entity( $campaign_node, node_load( $team_nid ), $score );
        }
    }

    /**
     * @param $campaign_nid
     * @param $team_nid
     *
     * @return bool|mixed
     */
    function scoga_get_latest_campaignteam_entity( $campaign_nid, $team_nid ){
        $previous_campaignteam_nids = scoga_get_campaignteam_nids_by_references( $campaign_nid, $team_nid );
        if( count( $previous_campaignteam_nids ) > 0 ){
            $latest_campaignteam_nid = $previous_campaignteam_nids[ 0 ];
            return node_load( $latest_campaignteam_nid );
        }

        return FALSE;
    }

    /**
     * Creates a campaignteam entity for a team and a campaign
     * @param $campaign_node
     * @param $team_node
     */
    function scoga_create_campaignteam_entity( $campaign_node, $team_node, $score = 0 ){
        $date = strftime( '%Y%m%d', time() );
        $node = new stdClass();
        $node->type = SCOGA_CAMPAIGNTEAM_NODETYPE;
        node_object_prepare( $node );
        scoga_set_eid_in_field( $node, 'field_campaignteam_campaign', $campaign_node->nid );
        scoga_set_eid_in_field( $node, 'field_campaignteam_team', $team_node->nid );
        scoga_set_field_value( $node, 'field_campaignteam_totalpoints', $score );
        $node->title = $campaign_node->title . ' - ' . $team_node->title . ' - ' . $date;
        $node->language = LANGUAGE_NONE;

        node_save( $node );
    }

    /**
     * @param null $campaign_nid
     * @param null $team_nid
     *
     * @return array
     */
    function scoga_get_campaignteam_nids_by_references( $campaign_nid = NULL, $team_nid = NULL, $timestamp = NULL ){
        $query = new EntityFieldQuery();
        $entity_type = 'node';
        $query
            ->entityCondition( 'entity_type', $entity_type )
            ->entityCondition( 'bundle', SCOGA_CAMPAIGNTEAM_NODETYPE )
            ->propertyOrderBy( 'created', 'DESC')
        ;
        if( $campaign_nid ){
            $query->fieldCondition( 'field_campaignteam_campaign', 'target_id', $campaign_nid, '=' );
        }
        if( $team_nid ){
            $query->fieldCondition( 'field_campaignteam_team', 'target_id', $team_nid, '=' );
        }
        if( $timestamp ){
            $date_info = new DateTime( date( 'Y-m-d', $timestamp ) );
            $today = $date_info->getTimestamp();
            $interval = new DateInterval( 'P1D' );
            $date_info->add( $interval );
            $tomorrow = $date_info->getTimestamp();
            $query
                ->propertyCondition( 'created', $today, '>=' )
                ->propertyCondition( 'created', $tomorrow, '<' )
            ;
        }

        $result = $query->execute();
        if( array_key_exists( $entity_type, $result ) ){
            $campaignteam_nids = array_keys( $result[ $entity_type ] );
            return $campaignteam_nids;
        }

        return array();
    }

    function scoga_determine_campaignteam_creation(){
        $campaign_nid = scoga_get_current_campaign_nid();
        if( $campaign_nid> SCOGA_NULL_CAMPAIGN_NID ){
            $nids = scoga_get_campaignteam_nids_by_references( $campaign_nid, NULL, time() );
            if( count( $nids ) < 1 ){
                scoga_create_campaignteam_entities_for_campaign( node_load( $campaign_nid ) );
            }
        }
    }



//    /**
//     * @param      $team_nid
//     * @param null $campaign_nid
//     *
//     * @return bool|mixed
//     */
//    function scoga_get_campaignteam_nids_by_team_nid( $team_nid, $campaign_nid = NULL ){
//        if( $campaign_nid == NULL ){
//            $campaign_nid = scoga_get_current_campaign_nid();
//        }
//        $query = new EntityFieldQuery();
//        $entity_type = 'node';
//        $result = $query
//            ->entityCondition( 'entity_type', $entity_type )
//            ->entityCondition( 'bundle', SCOGA_CAMPAIGNTEAM_NODETYPE )
//            ->fieldCondition( 'field_campaignteam_team', 'target_id', $team_nid, '=' )
//            ->fieldCondition( 'field_campaignteam_campaign', 'target_id', $campaign_nid, '=' )
//            ->execute();
//        if( $result ){
//            $campaignteam_nids = array_keys( $result[ $entity_type ] );
//            return node_load( $campaignteam_nids[ 0 ] );
//        }
//        return FALSE;
//    }


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

    function scoga_get_team_vos_by_campaign_nid( $campaign_nid ){
        $nids = scoga_get_team_nids();
        $vos = scoga_get_team_vos_by_nids( $nids );
        foreach( $vos as $team_vo ){
            $team_vo->total_points = scoga_get_teampoints_vos_by_references( $campaign_nid, $team_vo->nid );
        }
        return $vos;

    }

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
        module_load_include( 'api.player.inc', 'scoga', 'api/scoga' );
        $output = new Team();
        $output->nid = $team_node->nid;
        $output->colour = scoga_get_field_value( $team_node, 'field_team_colour' );
        $output->title = $team_node->title;
        //$output->players = scoga_get_player_vos_by_team_nid( $team_node->nid );
        //$output->total_points = scoga_get_teampoints_vos_by_references( $team_node->nid );
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

        if( array_key_exists( $entity_type, $result ) ){
            $nids = array_keys( $result[ $entity_type ] );
        }else{
            $nids = array();
        }

        return $nids;
    }

    function scoga_get_teampoints_vos_by_references( $campaign_nid, $team_nid ){
        $campaignteam_entities = scoga_get_campaignteam_nodes_by_references( $campaign_nid, $team_nid );
        $output = array();
        foreach( $campaignteam_entities as $campaignteam_entity ){
            $teampoints_vo = scoga_create_teampoints_vo( $campaignteam_entity );
            $output[] = $teampoints_vo;
        }
        return $output;
    }

    function scoga_get_campaignteam_nodes_by_references( $campaign_nid, $team_nid ){
        $campaignteam_nids = scoga_get_campaignteam_nids_by_references( $campaign_nid, $team_nid );
        $campaignteam_entities = node_load_multiple( $campaignteam_nids );
        return $campaignteam_entities;
    }

    function scoga_create_teampoints_vo( $campaignteam_node ){
        $output = new TeamPoints();
        $output->points = scoga_get_field_value( $campaignteam_node, 'field_campaignteam_totalpoints' );
        $output->timestamp = $campaignteam_node->created;
        return $output;
    }

    function scoga_get_opposing_teams_nid($player_team,$current_campaign_id){
        $teams = scoga_get_team_vos_by_campaign_nid($current_campaign_id);
        $returnvalues = array();
        foreach ($teams as $team)
        {
            if ($team->nid != $player_team)
                $returnvalues[] = $team->nid;
        }
        return $returnvalues;
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

//    /**
//     * @param $campaign_nid
//     *
//     * @return array
//     */
//    function scoga_get_team_vos_by_campaign_nid( $campaign_nid ){
//        $team_nids = scoga_get_team_nids();
//        $team_vos = scoga_get_team_vos_by_nids( $team_nids );
//        foreach( $team_vos as $team_vo ){
//            $campaignteam_nids = scoga_get_campaignteam_entity_by_team_nid( $team_vo->nid, $campaign_nid );
//        }
//        $campaignteam_nids = scoga_get_campaignteam_nids_by_references( $campaign_nid );
//        $team_objs = array();
//        foreach( $campaignteam_nids as $campaignteam_nid ){
//            $campaignteam_node = node_load( $campaignteam_nid );
//            $lang = $campaignteam_node->language;
//            $team_nid = scoga_get_eid_from_field( $campaignteam_node, 'field_campaignteam_team' );
//            $team_obj = scoga_get_team_vo_by_nid( $team_nid );
//            $team_obj->total_points = scoga_get_field_value( $campaignteam_node, 'field_campaignteam_totalpoints' );
//
//            $team_objs[ ] = $team_obj;
//        }
//        return $team_objs;
//    }

//    /**
//     * @param $campaign_nid
//     *
//     * @return array
//     */
//    function scoga_get_team_nids_by_campaign_nid( $campaign_nid ){
//
//        $query =
//            "SELECT field_campaignteam_team_target_id "
//                . "FROM {field_data_field_campaignteam_team} team "
//                . "JOIN {field_data_field_campaignteam_campaign} campaign "
//                . "ON team.entity_id = campaign.entity_id "
//                . "WHERE campaign.field_campaignteam_campaign_target_id = :target_nid";
//        $result = db_query( $query, array( ':target_nid' => $campaign_nid ) );
//        $nids = array();
//        foreach( $result as $row ){
//            $nids[ $row->field_campaignteam_team_target_id ] = $row->field_campaignteam_team_target_id;
//        }
//
//        return $nids;
//    }

