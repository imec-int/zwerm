<?php
function scoga_handle_theme($existing, $type, $theme, $path)
{
    return array(
        'no_checkin' => array(
            'variables' => array('names' => NULL,'uids' => NULL) ,
            'path' =>'sites/all/themes/zwerm/templates',
            'template' => 'no_checkin'
        ),
        'get_points' => array(
            'variables' => array('assignment_titles' => NULL) ,
            'path' =>'sites/all/themes/zwerm/templates',
            'template' => 'get_points'
        ),
        'item_list_get_points' => array(
            'variables' => array('assignment_titles' => NULL) ,
            'path' =>'sites/all/themes/zwerm/templates',
            'template' => 'get_points'
        ),
        'item_list_no_checkin' => array(
            //'variables' => array('assignment_titles' => NULL) ,
            'path' =>'sites/all/themes/zwerm/templates',
            'template' => 'get_points'
        ),
        'user_login' => array(
            'path' =>'sites/all/themes/zwerm/templates',
            'template' => 'user_login',
            'render element' => 'form'
        ),
        'time_interval' => array(
            'variables' => array('interval_elements' => NULL) ,
            'path' => 'sites/all/themes/zwerm/templates',
            'template' => 'time_interval'
        )
    );
}



