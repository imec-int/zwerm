<?php
/**
 * Formats $items as an html list
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