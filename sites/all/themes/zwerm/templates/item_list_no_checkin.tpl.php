<?php
/**
 * Formats $items as an html list
 */
    print ('<div id="dialog" title="Check-in partners">');
    print ('Hier zie je een overzicht van de spelers uit je team waar je nog nooit mee hebt ingecheckt.  Vergeet niet dat je meer punten kan verdienden door samen met teamgenoten in te checken bij de holle boom! Klik op de naam van een speler om hem of haar uit te nodigen voor een gezamenlijke check-in!');
    print('</div>');
    print ('<div id="select_list" class="clearfix">');
        print ('<ul>');
            $items = $variables['items'];
            $i = 0;
            foreach ($items as $key=>$item)
            {
                $user_profile_path = base_path().'user/'.$variables['uids'][$key];
                print("<li>".$item."</li>");
                $i = $i+1;
            }
        print ('</ul>');
    print ('</div>');

