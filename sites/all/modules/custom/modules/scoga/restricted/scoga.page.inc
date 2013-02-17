<?php
    /*
     * Construct the list of /not_checkin candidates that the logged in user has not checkin in with in the current campaign
     * and from the same team as the player
     * @return string
     */
    function scoga_get_list_of_not_checkin_parnters()
    {
        module_load_include( 'api.inc', 'scoga', 'api/scoga' );
        $active_relationsip_tid = scoga_get_current_combocheckin_rtid();
        global $user;
        $user_data = user_load($user->uid);
        $user_team = $user_data->field_user_team['und']['0']['target_id'];
        global $user;
        $no_checkin_candidates = array();
        $query = "SELECT DISTINCT
                  users.name AS users_name,
                  users.uid AS uid
                  FROM users users
                  LEFT JOIN field_data_field_user_active = field_data_field_user_active
                  ON users.uid = field_data_field_user_active.entity_id
                  LEFT JOIN field_data_field_user_team field_data_field_user_team
                  ON users.uid = field_data_field_user_team.entity_id
                  WHERE field_data_field_user_active.field_user_active_value=1
                  AND field_data_field_user_team.field_user_team_target_id = :team_id
                  AND uid !=276
                  AND uid NOT IN
                  (
                      SELECT DISTINCT
                      users.uid AS uid
                      FROM users users
                      LEFT JOIN user_relationships user_relationships
                      ON users.uid = user_relationships.requestee_id
                      WHERE user_relationships.requester_id = :uid
                      AND user_relationships.rtid = :active_rel_id
	              )";
        $result = db_query($query, array(':team_id'=>$user_team,
                                         ':uid'=>$user->uid,
                                         ':active_rel_id' => $active_relationsip_tid
                                        ));
        foreach ($result as $row)
        {
            $no_checkin_candidates[$row->uid] = $row->users_name;
        }
        //theme the output
        $output = '<div class="help"><a >?</a></div>';
        $output .= theme('no_checkin',array('names' => array_values($no_checkin_candidates),'uids' => array_keys($no_checkin_candidates)));
        return $output;

    }

    /*
     * Construct the list of /get_points
     * @return string
     */
    function scoga_overview_of_assignments_to_get_point()
    {
        module_load_include( 'api.campaign.inc', 'scoga', 'api/scoga' );
        $current_campaign_id = scoga_get_campaign_nid_for_time(time());
        $output='';
        if ($current_campaign_id>0)
        {
            global $user;
            $user_data = user_load($user->uid);
            $user_team = $user_data->field_user_team['und']['0']['target_id'];
            $output='';
            $output.= '<div class="help"><a >?</a></div>';
            $assignment_titles = array();
            $assignment_paths = array();
            //add time interval to end of current campaign
            $time_interval_elements = scoga_get_current_campaign_expiration_time();
            $output .= theme('time_interval',array('interval_elements' => $time_interval_elements));
            //add link to node based on path stored in SCOGA_SETTING_CHECKIN_EXPLANATION_NID to output
            $assignment_titles[] = t('Check-in : find new partners');
            $assignment_paths[] = SCOGA_NOT_PARTNER_PAGE;
            //add link to wish creation page to output
            $assignment_titles[] = t ('Make a wish');
            $assignment_paths[] = 'node/add/nodetype-wished-item';
            //add other playable elements to output
            _scoga_add_assignments_to_output('nodetype_event','Event','Active events','field_campaign','field_event_team',$user_team,$current_campaign_id,$assignment_titles,$assignment_paths);
            _scoga_add_polls_to_output('Poll','Question',t('Active questions'),'field_campaign','field_poll_team',$user_team,$current_campaign_id,$assignment_titles,$assignment_paths);
            _scoga_add_assignments_to_output('geo_challenge','GeoChallenge','Active GeoChallenges','field_geochallenge_ref_campaign',NULL,NULL, $current_campaign_id,$assignment_titles,$assignment_paths);
            _scoga_add_POI_confirmations_to_output($assignment_titles,$assignment_paths);
            _scoga_add_assignments_to_output('nodetype_wished_item','Wish','Posted wishes','field_wisheditem_campaign',NULL,NULL,$current_campaign_id,$assignment_titles,$assignment_paths);
            $output .= theme('get_points',array('assignment_titles' => $assignment_titles,'assignment_paths' => $assignment_paths));
        }
        else
        {
            $output .= '<div class="no_active"">'.t('No campaign is currently active').'</div>';
        }
        return $output;
    }

    /**
     * Loads nodes from DB and adds them to the output, preceded by a header
     * @param $content_type
     * @param $label
     * @param $header
     * @param $campaign_ref_field
     * @param $titles
     * @param $paths
     */
    function _scoga_add_assignments_to_output($content_type,$label,$header,$campaign_ref_field,$team_ref_field,$user_team,$current_campaign_id,&$titles,&$paths)
    {
        $nodes_properties = _scoga_get_assignments_by_type($team_ref_field, $content_type, $campaign_ref_field, $current_campaign_id, $user_team,$titles,$paths);
        $nodes = node_load_multiple(array_keys($nodes_properties['node']));
        _scoga_process_assignment_query_results($header,$label,$nodes,$titles,$paths);
    }


    /**
     * @param $content_type
     * @param $label
     * @param $header
     * @param $campaign_ref_field
     * @param $team_ref_field
     * @param $user_team
     * @param $current_campaign_id
     * @param $titles
     * @param $paths
     */
    function _scoga_add_polls_to_output($content_type,$label,$header,$campaign_ref_field,$team_ref_field,$user_team,$current_campaign_id,&$titles,&$paths)
    {
        module_load_include( 'api.team.inc', 'scoga', 'api/scoga' );
        $opposing_teams = scoga_get_opposing_teams_nid($user_team,$current_campaign_id);
        $nodes_properties_opposing_team = _scoga_get_assignments_by_type($team_ref_field, $content_type, $campaign_ref_field, $current_campaign_id, $opposing_teams[0],$titles,$paths);
        $nodes_properties_all_teams = _scoga_get_assignments_by_type(NULL, $content_type, $campaign_ref_field, $current_campaign_id,NULL,$titles,$paths);
        $nodes_properties = array_diff_key($nodes_properties_all_teams['node'],$nodes_properties_opposing_team['node']);
        $nodes = node_load_multiple(array_keys($nodes_properties));
        _scoga_process_assignment_query_results($header,$label,$nodes,$titles,$paths);
    }

    /**
     * @param $team_ref_field
     * @param $content_type
     * @param $campaign_ref_field
     * @param $current_campaign_id
     * @param $user_team
     * @param $titles
     * @param $paths
     * @return mixed
     */
    function _scoga_get_assignments_by_type($team_ref_field, $content_type, $campaign_ref_field, $current_campaign_id, $user_team,&$titles,&$paths)
    {
        $nodeQuery = new EntityFieldQuery;
        if ($team_ref_field != NULL) {
            $nodes_properties = $nodeQuery->entityCondition('entity_type', 'node')
                ->entityCondition('bundle', $content_type)
                ->fieldCondition($campaign_ref_field, 'target_id', $current_campaign_id, '=')
                ->fieldCondition($team_ref_field, 'target_id', $user_team, '=')
                ->propertyCondition('status', '1')
                ->execute();
            return $nodes_properties;
        }
        else {
            $nodes_properties = $nodeQuery->entityCondition('entity_type', 'node')
                ->entityCondition('bundle', $content_type)
                ->fieldCondition($campaign_ref_field, 'target_id', $current_campaign_id, '=')
                ->propertyCondition('status', '1')
                ->execute();
            return $nodes_properties;
        }
    }

    /**
     * @param $header
     * @param $label
     * @param $nodes
     * @param $titles
     * @param $paths
     */
    function _scoga_process_assignment_query_results($header,$label,$nodes,&$titles,&$paths)
    {
        if (sizeOf($nodes)!=0)
        {
            $titles[] = t($header);
            $paths[] = '';
            _scoga_set_assignment_titles_and_paths($nodes,$titles,$paths,$label);
        }
    }


    /**
     * @param $nodes
     * @param $titles
     * @param $paths
     * @param $label
     */
    function _scoga_set_assignment_titles_and_paths($nodes,&$titles,&$paths,$label)
    {
        foreach($nodes as $node_item)
        {
            $titles[] = t($label).': '.$node_item->title;
            $paths[] = 'node/'.$node_item->nid;
        }
    }

    /**
     * @param $titles
     * @param $paths
     */
    function _scoga_add_POI_confirmations_to_output(&$titles,&$paths)
    {
        global $user;
        $current_campaign_id = scoga_get_campaign_nid_for_time(time());
        $nodeQuery = new EntityFieldQuery;
        $nodes_properties = $nodeQuery->entityCondition('entity_type', 'node')
            ->entityCondition('bundle', 'poi_confirmation')
            ->fieldCondition('field_status', 'value', '0' )
            ->fieldCondition('field_poi_confirm_ref_user', 'target_id', $user->uid )
            ->fieldCondition('field_geochallenge_ref_campaign', 'target_id', $current_campaign_id )
            ->execute();
        if (isset($nodes_properties['node']))
        {
        $nodes = node_load_multiple(array_keys($nodes_properties['node']));
            if (sizeOf($nodes)!=0)
            {
                $titles[] = t('POIs to confirm');
                $paths[] = '';
                _scoga_set_assignment_titles_and_paths($nodes,$titles,$paths,t('POI confirmation'));
            }
        }
    }

    /**
     * @return array
     */
    function scoga_team_score_graph() {
        $returnvalues = array();
        $zerodatapoint = array('date'=>'start','points1'=>0,'points2'=>0);
        $returnvalues['start'] = $zerodatapoint;
        module_load_include( 'api.campaign.inc', 'scoga', 'api/scoga' );
        module_load_include( 'api.team.inc', 'scoga', 'api/scoga' );
        $current_campaign_id = scoga_get_campaign_nid_for_time(time());
        $teams = scoga_get_team_vos_by_campaign_nid($current_campaign_id);
        //load data for team1
        $nid_team1 = scoga_get_campaignteam_nids_by_references($current_campaign_id,$teams[0]->nid);
        $nid_team1 = array_reverse($nid_team1);
        $colour_team1 = '#'.$teams[0]->colour;
        $colour_team2 = '#'.$teams[1]->colour;
        $nodes_team1 = node_load_multiple($nid_team1);
        foreach($nodes_team1 as $node)
        {
            $points = $node->field_campaignteam_totalpoints['und'][0]['value'];
            $date =  date('d/m', $node->created);
            $datapoint = array('date'=>$date,'points1'=>$points);
            $returnvalues[$date]= $datapoint;
        }
        //load data for team2
        //merge data of team1 with team 2
        $nid_team2 = scoga_get_campaignteam_nids_by_references($current_campaign_id,$teams[1]->nid);
        $nid_team2 = array_reverse($nid_team2);
        $nodes_team2 = node_load_multiple($nid_team2);
        foreach($nodes_team2 as $node)
        {
            $points = $node->field_campaignteam_totalpoints['und'][0]['value'];
            $date =  date('d/m', $node->created);

            if (isset($returnvalues[$date]))
            {
                $returnvalues[$date]['points2']=$points;
            }
            else
            {
                $datapoint = array('date'=>$date,'points1'=>$points);
                $returnvalues[$date]= $datapoint;
            }
        }
        //configure graph
        $options_line = array(
            'title' => 'Score per team',
            'backgroundColor' => 'black',
            'fields' => array(
                'points1' => array(
                    'label' => t($teams[0]->title),
                    'colour' => $colour_team1,
                    'enabled' => TRUE,
                ),
                'points2' => array(
                    'label' => t($teams[1]->title),
                    'colour' => $colour_team2,
                    'enabled' => TRUE,
                ),
            ),
            'xAxis' => array(
                'labelField' => 'date',
            ),
            'yAxis' => array(
                'title' => ' ',
            ),
            'data' => $returnvalues,
            'type' => 'line',
        );

        $build['line'] =  array(
            '#theme' => 'visualization',
            '#options' => $options_line,
        );

        return $build;
    }
?>