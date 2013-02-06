<?php
    /*
     * Construct the list of /not_checkin
     * @return string
     */
    function scoga_get_list_of_not_checkin_parnters()
    {
        module_load_include( 'api.inc', 'scoga', 'api/scoga' );
        $active_relationsip_tid = scoga_get_current_combocheckin_rtid();
        //get all the active users & store all the active users in an array
        $active_user_names = array();
        $active_user_uids = array();
        $query = "SELECT DISTINCT
                  users.name AS users_name,
                  users.uid AS uid
                  FROM {users} users
                  LEFT JOIN {field_data_field_user_active} = field_data_field_user_active
                  ON users.uid = field_data_field_user_active.entity_id
                  WHERE ((field_data_field_user_active.field_user_active_value=1))";
                  //WHERE (( (users.status <> '0') ))";
        $result = db_query($query);
        foreach ($result as $row)
        {
            $active_user_names[] = $row->users_name;
            $active_user_uids[] = $row->uid;
        }
        //get all the users that the logged-in user has checked in with & store all the checkin partners in an array
        global $user;
        $checkin_partner_names = array();
        $checkin_partner_uids = array();
        $query = "SELECT DISTINCT
                  users.name AS users_name,
                  users.uid AS uid
                  FROM {users} users
                  LEFT JOIN {user_relationships} user_relationships
                  ON users.uid = user_relationships.requestee_id

                  WHERE (( (users.status <> '0')
                  AND ((user_relationships.requester_id = ".$user->uid."
                  OR user_relationships.requestee_id = ".$user->uid."))
                  AND user_relationships.rtid = ".$active_relationsip_tid."))";

        $result = db_query($query);
        foreach ($result as $row)
        {
            $checkin_partner_names[] = $row->users_name;
            $checkin_partner_uids[] = $row->uid;
        }

        //substract both arrays
        $no_checkin_users_names = array_diff ($active_user_names,$checkin_partner_names);
        $no_checkin_users_uids = array_diff ( $active_user_uids, $checkin_partner_uids);
        //theme the output
        $output = theme('no_checkin',array('names' => $no_checkin_users_names,'uids' => $no_checkin_users_uids));
        return $output;

    }

    /*
     * Construct the list of /get_points
     * @return string
     */
    function scoga_overview_of_assignments_to_get_point()
    {

        global $user;
        $user_data = user_load($user->uid);
        $user_team = $user_data->field_user_team['und']['0']['target_id'];
        $output='';
        $assignment_titles = array();
        $assignment_paths = array();
        //add time interval to end of current campaign
        module_load_include( 'api.campaign.inc', 'scoga', 'api/scoga' );
        $time_interval_elements = scoga_get_current_campaign_expiration_time();
        $output .= theme('time_interval',array('interval_elements' => $time_interval_elements));
        //add link to node based on path stored in SCOGA_SETTING_CHECKIN_EXPLANATION_NID to output
        $assignment_titles[] = t('Check-in : find new partners');
        $assignment_paths[] = SCOGA_NOT_PARTNER_PAGE;
        //add link to wish creation page to output
        $assignment_titles[] = t ('Make a wish');
        $assignment_paths[] = 'node/add/nodetype-wished-item';
        //add other playable elements to output
        _scoga_add_nodes_to_output('nodetype_event','Event','Active events','field_campaign','field_event_team',$user_team,&$assignment_titles,&$assignment_paths);
        _scoga_add_nodes_to_output('Poll','Question',t('Active questions'),'field_campaign','field_poll_team',$user_team,&$assignment_titles,&$assignment_paths);
        _scoga_add_nodes_to_output('geo_challenge','GeoChallenge','Active GeoChallenges','field_geochallenge_ref_campaign',NULL,NULL,&$assignment_titles,&$assignment_paths);
        _scoga_add_POI_confirmations_to_output(&$assignment_titles,&$assignment_paths);
        _scoga_add_nodes_to_output('nodetype_wished_item','Wish','Posted wishes','field_wisheditem_campaign',NULL,NULL,&$assignment_titles,&$assignment_paths);
        $output .= theme('get_points',array('assignment_titles' => $assignment_titles,'assignment_paths' => $assignment_paths));
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
    function _scoga_add_nodes_to_output($content_type,$label,$header,$campaign_ref_field,$team_ref_field,$user_team,$titles,$paths)
    {
        //todo : $current_campaign_id should be calculated only once, in function calling this one
        $current_campaign_id = scoga_get_campaign_nid_for_time(time());
        $nodeQuery = new EntityFieldQuery;
        if($team_ref_field != NULL)
        {
            $nodes_properties = $nodeQuery->entityCondition('entity_type', 'node')
                ->entityCondition('bundle', $content_type)
                ->fieldCondition($campaign_ref_field,'target_id', $current_campaign_id, '=')
                ->fieldCondition($team_ref_field,'target_id', $user_team, '=')
                ->propertyCondition( 'status', '1' )
                ->execute();
        }
        else
        {
            $nodes_properties = $nodeQuery->entityCondition('entity_type', 'node')
                ->entityCondition('bundle', $content_type)
                ->fieldCondition($campaign_ref_field,'target_id', $current_campaign_id, '=')
                ->propertyCondition( 'status', '1' )
                ->execute();
        }
        $nodes = node_load_multiple(array_keys($nodes_properties['node']));
        if (sizeOf($nodes)!=0)
        {
            $titles[] = t($header);
            $paths[] = '';
            _scoga_fill_titles_and_path($nodes,&$titles,&$paths,$label);
        }
    }

    /**
     * @param $nodes
     * @param $titles
     * @param $paths
     * @param $label
     */
    function _scoga_fill_titles_and_path($nodes,$titles,$paths,$label)
    {
        foreach($nodes as $node_item)
        {
            $titles[] = t($label).': '.$node_item->title;
            $paths[] = 'node/'.$node_item->nid;
        }
    }

    function _scoga_add_POI_confirmations_to_output($titles,$paths)
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
                _scoga_fill_titles_and_path($nodes,&$titles,&$paths,t('POI confirmation'));
            }
        }
    }

/**
 * Implements hook_menu().
 */
function example_menu() {
    $items['example-charts'] = array(
        'title' => 'Example',
        'page callback' => 'example_page',
        'access arguments' => array('access content'),
        'type' => MENU_CALLBACK,
    );

    return $items;
}

/**
 * Callback function for menu item.
 */
function example_page() {
    $returnvalues = array();
    module_load_include( 'api.campaign.inc', 'scoga', 'api/scoga' );
    module_load_include( 'api.team.inc', 'scoga', 'api/scoga' );
    $current_campaign_id = scoga_get_campaign_nid_for_time(time());
    $nid_team1 = scoga_get_campaignteam_nids_by_references($current_campaign_id,1);
    $nodes_team1 = node_load_multiple($nid_team1);
    //dsm($nodes_team1);
    foreach($nodes_team1 as $node)
    {
        $points = $node->field_campaignteam_totalpoints[und][0][value];
        $date =  $node->created;
        //todo : change points1 label to name of team
        $datapoint = array('date'=>$date,'points1'=>$points);
        $returnvalues[$date]= $datapoint;
    }
    $nid_team2 = scoga_get_campaignteam_nids_by_references($current_campaign_id,2);
    $nodes_team2 = node_load_multiple($nid_team2);
    foreach($nodes_team2 as $node)
    {
        $points = $node->field_campaignteam_totalpoints[und][0][value];
        $date =  $node->created;
        if (isset($returnvalues[$date]))
        {
            $returnvalues[$date]['points2']=$points;
        }
        else
        {
            //todo : change points1 label to name of team
            $datapoint = array('date'=>$date,'points1'=>$points);
            $returnvalues[$date]= $datapoint;
        }
    }
    //make sure there are point values for each data point, otherwise, these values will be assumed to be 0
    $previous_point1 = 0;
    $previous_point2 = 0;
    foreach ($returnvalues as $date=>$datapoint)
    {
        dsm('foreach ($returnvalues as $date=>$datapoint)');
        if (!isset($datapoint['points1']))
        {
            $datapoint['points1'] = $previous_point1;
        }
        else
        {
            $previous_point1 = $datapoint['points1'];
        }
        if (!isset($datapoint['points2']))
        {
            $datapoint['points2'] = $previous_point2;
        }
        else
        {
            $previous_point2 = $datapoint['points2'];
        }
        $returnvalues[$date] = $datapoint;
    }
    dsm($returnvalues);



    $data = array(
        array('fruit' => 'apple', 'votes1' => 16, 'votes2' => 18,'team' =>1),
        array('fruit' => 'mango', 'votes1' => 10, 'votes2' => 15, 'team' =>1),
        array('fruit' => 'banana', 'votes1' => 34,'votes2' => 36,'team' =>1),
        array('fruit' => 'peach', 'votes1' => 20,'votes2' => 28, 'team' =>1),
        array('fruit' => 'orange', 'votes1' => 15,'votes2' => 19, 'team' =>1),

    );



    $options_line = array(
        'title' => 'Score per team',
        'fields' => array(
            'points1' => array(
                'label' => t('points1'),
                'enabled' => TRUE,
            ),
            'points2' => array(
                'label' => t('points2'),
                'enabled' => TRUE,
            ),
        ),
        'xAxis' => array(
            'labelField' => 'date',
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