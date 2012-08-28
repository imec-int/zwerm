<?php

function scoga_theme_info($existing, $type, $theme, $path)
{
    return array(
        'no_checkin' => array(
            'variables' => array('content' => NULL)      ,
            'path' =>'templates',
            'template' => 'no_checkin'
        ),
    );
}