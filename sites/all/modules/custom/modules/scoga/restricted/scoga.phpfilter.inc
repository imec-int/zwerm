<?php

function scoga_filter_points_in_current_campaign($current_campaign_tid,$result_tid)
{
    if ($current_campaign_tid==$result_tid)
        return false;
    else
        return true;

}

//find the position of the logged in user on the leaderboard
//store the position in the $static variable for reference in later calls
function scoga_filter_leaderboard($userPosition,$counter,$point_taxo_id,$campaign_taxo_id,$view)
{
    //dsm($point_taxo_id);
    //dsm($campaign_taxo_id);
   /* if($point_taxo_id!=$campaign_taxo_id)
    {
        $counter = $counter+1;
        return true;
    }
    else
    {*/
        if ($userPosition == 0)
        {
            global $user;
            $results = $view->result;
            for ($i = 0; $i <= count($results); $i++)
            {
                if (isset($results[$i]))
                {
                    $result = $results[$i];
                    $user_name = $result->users_name;
                    if ($user_name==$user->name)
                    {
                        dsm('user found at leaderboard position: '.$i);
                        $userPosition = $i;
                        dsm('current user position:'.$userPosition);
                        //set a variable for later use in the theme
                        variable_set('userLeaderboardPosition',$i);
                        break;
                    }
                }

            }
            //increment, to reflect real user rank, not zero-based array positions
            $userPosition = $userPosition+1;
        }
        else
        {
            $counter = $counter+1;
            $numberOnLeaderboard =$counter;
            $loggedInUserPosition = $userPosition;

            //if $static->userPosition ==1 , this means that user was not in $view result and has no points
            //in that case, only show top 10 results
            if ($userPosition == 1)
            {
                if ($numberOnLeaderboard>9)
                {
                    dsm('exit 48');
                    return true;
                }
                else
                {
                    dsm('exit 52');
                    return false;
                }
            }
            else
            {
                if (($numberOnLeaderboard < 3) || ($loggedInUserPosition-5 < $numberOnLeaderboard && $numberOnLeaderboard < $loggedInUserPosition+3))
                {
                    dsm('exit 84');
                    return false;
                }
                else
                {
                    dsm('exit 88');
                    return true;
                }
            }
        }
    //}
}


