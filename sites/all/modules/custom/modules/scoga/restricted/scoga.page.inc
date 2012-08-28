<?php
    function scoga_get_list_of_not_checkin_parnters()
    {
        //get all the active users & store all the active users in an array
        $active_users = array();
        $query = "SELECT DISTINCT users.name AS users_name, users.uid AS uid FROM users users WHERE (( (users.status <> '0') ))";
        $result = db_query($query);
        foreach ($result as $row)
        {
            $active_users[] = $row->users_name;
        }
        //get all the users that the logged-in user has checked in with & store all the checkin partners in an array
        global $user;
        $checkin_partners = array();
        $query = "SELECT DISTINCT users.name AS
                  users_name, users.uid AS uid FROM {users} users
                  LEFT JOIN {user_relationships} user_relationships ON users.uid = user_relationships.requestee_id
                  WHERE (( (users.status <> '0')
                  AND ((user_relationships.requester_id = ".$user->uid."
                  OR user_relationships.requestee_id = ".$user->uid.")) ))";
        $result = db_query($query);
        foreach ($result as $row)
        {
            $checkin_partners[] = $row->users_name;
        }

        //substract both arrays
        $no_checkin_users = array_diff ($active_users,$checkin_partners);
        var_dump($no_checkin_users);
        foreach ($no_checkin_users as $user)
        {
            print($user.'<br/>');
        }

        //theme the output
        $output= 'test';
        print theme('no_checkin',array('content' => $output));
    }
?>