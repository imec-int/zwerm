<?php
/**
 * Formats $items as an html list
 */
    print ('<div id="dialog" title="Checkin partners">');
    print ('In dit scherm vind je de spelers uit je team waar je nog nooit mee hebt ingechecked en dus punten kunt verdienen door samen in te checken aan de Holle boom. Click op de naam van een speler om meer gegevens te krijgen of een bericht te sturen.');
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

