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
        $assignment_titles = array();
        $assignment_paths = array();
        //add link to node based on path stored in SCOGA_SETTING_CHECKIN_EXPLANATION_NID to output
        $checkin_explanation_nid = variable_get(SCOGA_SETTING_CHECKIN_EXPLANATION_NID);
        $checkin_explanation_node = node_load($checkin_explanation_nid);
        $assignment_titles[] = $checkin_explanation_node->title;
        $assignment_paths[] = 'node/'.$checkin_explanation_node->nid;
        //add link to wish creation page to output
        $assignment_titles[] = t ('Make a wish');
        $assignment_paths[] = 'node/add/nodetype-wished-item';
        //todo : add link to active geo challenges
        //add links to active events
        _scoga_add_content_type_to_output('nodetype_event','Event',&$assignment_titles,&$assignment_paths);
        //add links to active questions
        _scoga_add_content_type_to_output('poll','Question',&$assignment_titles,&$assignment_paths);
        //add links to active wishes
        _scoga_add_content_type_to_output('nodetype_wished_item','Wish',&$assignment_titles,&$assignment_paths);
        $output = theme('get_points',array('assignment_titles' => $assignment_titles,'assignment_paths' => $assignment_paths));
        return $output;
    }

    /*
     * Load node of a given content type and adds it to the output
     */
    function _scoga_add_content_type_to_output($content_type,$label,$titles,$paths)
    {
        $poll_nodes = node_load_multiple(array(), array('type' => $content_type));
        foreach($poll_nodes as $poll_node)
        {
            $titles[] = $label.': '.$poll_node->title;
            $paths[] = 'node/'.$poll_node->nid;
        }
    }
?>