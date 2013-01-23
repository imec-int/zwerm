<?php
function scoga_handle_theme($existing, $type, $theme, $path)
{
    return array(
        'no_checkin' => array(
            'variables' => array('names' => NULL,'uids' => NULL) ,
            'path' =>'templates',
            'template' => 'no_checkin'
        ),
        'get_points' => array(
            'variables' => array('assignment_titles' => NULL) ,
            'path' =>'templates',
            'template' => 'get_points'
        ),
        'item_list_get_points' => array(
            'variables' => array('assignment_titles' => NULL) ,
            'path' =>'templates',
            'template' => 'get_points'
        ),
        'item_list_no_checkin' => array(
            //'variables' => array('assignment_titles' => NULL) ,
            'path' =>'templates',
            'template' => 'get_points'
        ),
        'user_login' => array(
            'path' =>'templates',
            'template' => 'templates/user_login',
            'render element' => 'form'
        ),
        'time_interval' => array(
            'variables' => array('interval_elements' => NULL) ,
            'path' => 'templates',
            'template' => 'templates/time_interval'
        )
    );
}



