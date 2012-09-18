<?php
/*
 * Implements hook_theme_info
 */
function scoga_theme_info($existing, $type, $theme, $path)
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
    );
}