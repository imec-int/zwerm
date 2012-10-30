<?php
/**
 * Formats $items as an html list
 */
    print ('<div id="select_list" class="clearfix">');
        print ('<ul>');
            $items = $variables['items'];
            $paths = $variables['assignment_paths'];
            $i = 0;
            foreach ($items as $item)
            {
                $path = $paths[$i];
                print("<li onmousedown=\"li_mousedown('".$path."',this);\">".$item."</li>");
                $i++;
            }
        print ('</ul>');
    print ('</div>');