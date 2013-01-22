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

                    //when there is not path, it should be treated as a heading
                    if ($path==false)
                    {
                        if (strpos($item,t('Active GeoChallenges'))!=false)
                        {
                            $classes .= ' list_header_geochallenge';
                        }
                        if (strpos($item,t('Posted wishes'))!=false)
                        {
                            $classes .= ' list_header_wish';
                        }
                        if (strpos($item,t('Active events'))!=false)
                        {
                            $classes .= ' list_header_event';
                        }
                        if (strpos($item,t('Active questions'))!=false)
                        {
                            $classes .= ' list_header_question';
                        }
                        print("<li class=\"".$classes."\"><div class=link_truncated>".$item."</div></li>");
                    }
                    //when there is a path, it should be treated as a an actual selectable item
                    else
                    {
                        if (strpos($item,t('GeoChallenge'))!=false)
                            $classes .= ' geochallenge collapsible';
                        if (strpos($item,t('Wish'))!=false)
                            $classes .= ' wish collapsible';
                        if (strpos($item,t('Event'))!=false)
                            $classes .= ' event collapsible';
                        if (strpos($item,t('Question'))!=false)
                            $classes .= ' question collapsible';
                        print("<li class=\"".$classes."\" onmousedown=\"li_mousedown('".$path."',this);\"><div class=link_truncated>".$item."</div></li>");
                    }

                }
                $i = $i+1;
            }
        print ('</ul>');
    print ('</div>');
