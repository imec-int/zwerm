<?php
    /*
     * Construct the list of /not_checkin
     */
    function scoga_get_list_of_not_checkin_parnters()
    {
        //get all the active users & store all the active users in an array
        $active_user_names = array();
        $active_user_uids = array();
        $query = "SELECT DISTINCT
                  users.name AS users_name,
                  users.uid AS uid
                  FROM {users} users
                  WHERE (( (users.status <> '0') ))";
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
                  OR user_relationships.requestee_id = ".$user->uid.")) ))";
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
     */
    function scoga_overview_of_assignments_to_get_point()
    {
        $output='';
        //add time interval to end of current campaign
        module_load_include( 'api.campaign.inc', 'scoga', 'api/scoga' );
        $time_interval_elements = scoga_get_current_campaign_expitaration_time();
        //dsm($time_interval_elements);
        $output .= theme('time_interval',array('interval_elements' => $time_interval_elements));


        $assignment_titles = array();
        $assignment_paths = array();
        //add link to node based on path stored in SCOGA_SETTING_CHECKIN_EXPLANATION_NID to output
        $assignment_titles[] = 'Check-in : find new partners';
        $assignment_paths[] = SCOGA_NOT_PARTNER_PAGE;
        //add link to wish creation page to output
        $assignment_titles[] = t ('Make a wish');
        $assignment_paths[] = 'node/add/nodetype-wished-item';
        //todo : add link to active geo challenges
        $assignment_titles[] = t('Active events');
        $assignment_paths[] = '';
        //add links to active events
        _scoga_add_content_type_to_output('nodetype_event','Event',&$assignment_titles,&$assignment_paths);
        $assignment_titles[] = t('Active questions');
        $assignment_paths[] = '';
        //add links to active questions
        _scoga_add_content_type_to_output('poll','Question',&$assignment_titles,&$assignment_paths);
        $assignment_titles[] = t('Active GeoChallenges');
        $assignment_paths[] = '';
        //add links to active questions
        _scoga_add_content_type_to_output('geo_challenge','GeoChallenge',&$assignment_titles,&$assignment_paths);
        //add wishes header
        $assignment_titles[] = t('Posted Wishes');
        $assignment_paths[] = '';
        //add links to active wishes
        _scoga_add_content_type_to_output('nodetype_wished_item','Wish',&$assignment_titles,&$assignment_paths);
        $output .= theme('get_points',array('assignment_titles' => $assignment_titles,'assignment_paths' => $assignment_paths));
        return $output;
    }

    /*
     * Adds a div to the title
     */
    /*function scoga_overview_of_assignments_title()
    {
        $output = "<div class='play_title'>".t(Play)."</div>";
        return $output;
    } */

    /*
     * Load node of a given content type and adds it to the output
     */
    function _scoga_add_content_type_to_output($content_type,$label,$titles,$paths)
    {
        $nodes = node_load_multiple(array(), array('type' => $content_type));
        foreach($nodes as $node_item)
        {
            $titles[] = $label.': '.$node_item->title;
            $paths[] = 'node/'.$node_item->nid;
        }
    }
?>