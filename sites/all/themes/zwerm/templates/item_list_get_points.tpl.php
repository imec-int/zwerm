<?php
/**
 * Formats $items as an html list
 */
    print ('<div id="select_list" class="clearfix">');
        print ('<ul>');
            $items = $variables['items'];
            if(isset($variables['assignment_paths']))
            {
                $paths = '';
                $paths = $variables['assignment_paths'];
            }
            $i = 0;
            foreach ($items as $key=>$item)
            {
                $classes = '';

                $id='';
                if ($paths != '')
                {
                    $path = $paths[$i];

                    if ($path==false)
                    {
                        if (strpos($item,'wish')!=false)
                        {
                            $classes .= ' list_header_wish';
                        }
                        if (strpos($item,'event')!=false)
                        {
                            $classes .= ' list_header_event';
                        }
                        if (strpos($item,'question')!=false)
                        {
                            $classes .= ' list_header_question';
                        }
                        print("<li class=\"".$classes."\"><div class=link_truncated>".$item."</div></li>");
                    }
                    else
                    {
                        if (strpos($item,t('Wish'))!=false)
                            $classes .= ' wish';
                        if (strpos($item,'Event')!=false)
                            $classes .= ' event';
                        if (strpos($item,'Question')!=false)
                            $classes .= ' question';
                        print("<li class=\"".$classes."\" onmousedown=\"li_mousedown('".$path."',this);\"><div class=link_truncated>".$item."</div></li>");
                    }

                }
                $i = $i+1;
            }
        print ('</ul>');
    print ('</div>');
