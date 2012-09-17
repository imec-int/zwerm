<?php
/**
 * User: tanguycoenen
 * Date: 05/09/12
 * Time: 21:40
 */
    print ('<div id="not-checkin-list" class="clearfix">');
        print ('<ul>');
            $items = $variables['items'];
            foreach ($items as $item)
            {
                print('<li>'.$item.'</li>');
            }
        print ('</ul>');
    print ('</div>');