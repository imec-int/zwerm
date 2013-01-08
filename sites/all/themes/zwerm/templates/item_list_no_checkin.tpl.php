<?php
/**
 * Formats $items as an html list
 */

    print ('<div id="select_list" class="clearfix">');
        print ('<ul>');
            $items = $variables['items'];
            $i = 0;
            foreach ($items as $key=>$item)
            {
                $user_profile_path = base_path().'user/'.$variables['uids'][$key];
                //print("<li onmousedown=\"li_mousedown('".$user_profile_path."',this);\">".$item."</li>");
                print("<li>".$item."</li>");
                $i = $i+1;
            }
        print ('</ul>');
    print ('</div>');

