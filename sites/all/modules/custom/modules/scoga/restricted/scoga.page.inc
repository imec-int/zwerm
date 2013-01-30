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
        $output='';
        //add time interval to end of current campaign
        module_load_include( 'api.campaign.inc', 'scoga', 'api/scoga' );
        $time_interval_elements = scoga_get_current_campaign_expiration_time();
        $output .= theme('time_interval',array('interval_elements' => $time_interval_elements));
        $assignment_titles = array();
        $assignment_paths = array();
        //add link to node based on path stored in SCOGA_SETTING_CHECKIN_EXPLANATION_NID to output
        $assignment_titles[] = t('Check-in : find new partners');
        $assignment_paths[] = SCOGA_NOT_PARTNER_PAGE;
        //add link to wish creation page to output
        $assignment_titles[] = t ('Make a wish');
        $assignment_paths[] = 'node/add/nodetype-wished-item';
        //add other playable elements to output
        _scoga_add_nodes_to_output('nodetype_event','Event','Active events','field_campaign',&$assignment_titles,&$assignment_paths);
        _scoga_add_nodes_to_output('Poll','Question',t('Active questions'),'field_campaign',&$assignment_titles,&$assignment_paths);
        _scoga_add_nodes_to_output('geo_challenge','GeoChallenge','Active GeoChallenges','field_geochallenge_ref_campaign',&$assignment_titles,&$assignment_paths);
        _scoga_add_POI_confirmations_to_output('field_campaign',&$assignment_titles,&$assignment_paths);
        _scoga_add_nodes_to_output('nodetype_wished_item','Wish','Posted wishes','field_wisheditem_campaign',&$assignment_titles,&$assignment_paths);
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
    function _scoga_add_nodes_to_output($content_type,$label,$header,$campaign_ref_field,$titles,$paths)
    {
        $current_campaign_id = scoga_get_campaign_nid_for_time(time());
        $nodeQuery = new EntityFieldQuery;
        $nodes_properties = $nodeQuery->entityCondition('entity_type', 'node')
            ->entityCondition('bundle', $content_type)
            ->fieldCondition($campaign_ref_field,'target_id', $current_campaign_id, '=')
            ->propertyCondition( 'status', '1' )
            ->execute();
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

    function _scoga_add_POI_confirmations_to_output($campaign_ref_field,$titles,$paths)
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
        $nodes = node_load_multiple(array_keys($nodes_properties['node']));
        if (sizeOf($nodes)!=0)
        {
            $titles[] = t('POIs to confirm');
            $paths[] = '';
            _scoga_fill_titles_and_path($nodes,&$titles,&$paths,t('POI confirmation'));
        }
    }
?>