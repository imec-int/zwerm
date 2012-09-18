<?php
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

    function scoga_overview_of_assignments_to_get_point()
    {
        print('test');
    }
?>