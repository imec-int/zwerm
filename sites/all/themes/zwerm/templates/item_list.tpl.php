<?php
/**
 * Created by JetBrains PhpStorm.
 * User: tanguycoenen
 * Date: 05/09/12
 * Time: 21:40
 * To change this template use File | Settings | File Templates.
 */
    print ('<ul data-role="listview" data-theme="g">');
    $items = $variables['items'];
    foreach ($items as $item)
    {
        print('<li>'.$item.'</li>');
    }
    print ('</ul>');