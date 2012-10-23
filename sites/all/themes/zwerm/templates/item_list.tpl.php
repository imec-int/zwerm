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
                //print("<li onmousedown='this.className=\"selectedItem\"' onmousedown='this.className=\"selectedItem\"'>".$item."</li>");
                print("<li onmousedown=\"li_mousedown('".$path."',this);\">".$item."</li>");
                //print("<li onmousedown='document.li_mousedown()'>".$item."</li>");
            }
        print ('</ul>');
    print ('</div>');