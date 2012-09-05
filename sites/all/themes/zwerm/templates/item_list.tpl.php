<?php
/**
 * Created by JetBrains PhpStorm.
 * User: tanguycoenen
 * Date: 05/09/12
 * Time: 21:40
 * To change this template use File | Settings | File Templates.
 */
    //print ('<link rel="stylesheet" type="text/css" href="'.path_to_theme().'/css/vendors/jquery.mobile-1.0.1/jquery.mobile-1.0.1.css" />');
    //print ('<script type="text/javascript" src="'.path_to_theme().'/css/vendors/jquery.mobile-1.0.1/jquery.mobile-1.0.1.js"></script>');
    print ('<ul data-role="listview" data-theme="g">');
    $items = $variables['items'];
    foreach ($items as $item)
    {
        print('<li>'.$item.'</li>');
    }
    print ('</ul>');