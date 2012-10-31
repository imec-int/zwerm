<?php
/**
 * Formats $items as an html list
 */
    print ('<div id="select_list" class="clearfix">');
        print ('<ul>');
            $items = $variables['items'];
            $paths = '';
            if(isset($variables['assignment_paths']))
            {
                $paths = $variables['assignment_paths'];
            }
            $i = 0;
            foreach ($items as $item)
            {
                if ($paths != '')
                {
                    $path = $paths[$i];
                     print("<li onmousedown=\"li_mousedown('".$path."',this);\">".$item."</li>");
                }
                $i++;
            }
        print ('</ul>');
    print ('</div>');