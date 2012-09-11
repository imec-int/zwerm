<?php
/**
 * User: tanguycoenen
 * Date: 05/09/12
 * Time: 21:40
 */
    print ('<ul data-role="listview" data-theme="c">');
    $items = $variables['items'];
    foreach ($items as $item)
    {
        print('<li>'.$item.'</li>');
    }
    print ('</ul>');