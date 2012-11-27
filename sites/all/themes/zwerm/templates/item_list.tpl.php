<?php
/**
 * Formats $items as an html list
 */
    print ('<div id="select_list" class="clearfix">');
        print ('<ul>');
            $items = $variables['items'];

            //assignment paths are for /get_points
            if(isset($variables['assignment_paths']))
            {
                $paths = '';
                $paths = $variables['assignment_paths'];
            }
            $i = 0;
            foreach ($items as $key=>$item)
            {
                $classes;
                //paths are for /get_points
                if (isset($paths))
                {
                    $id='';
                    if ($paths != '')
                    {
                        $path = $paths[$i];

                        if ($path==false)
                        {
                            $classes .= ' list_header';
                            print("<li class='".$classes."''>".$item."</li>");
                        }
                        else
                        {
                            if (strpos($item,t('Wish'))!=false)
                                $classes .= ' wish';
                            //print("<li  onmousedown=\"li_mousedown('".$path."',this);\"> <div class=\"".$classes."\">".$item."</div></li>");
                            print("<li class=\"".$classes."\" onmousedown=\"li_mousedown('".$path."',this);\"><div class=link_truncated>".$item."</div></li>");
                        }
                    }
                }
                //if there are no paths the case for /not_partner applies
                //todo split the template files in one for /not_partner and one for /get_points
                else
                {
                    $user_profile_path = base_path().'user/'.$variables['uids'][$key];
                    print("<li onmousedown=\"li_mousedown('".$user_profile_path."',this);\">".$item."</li>");

                }
                $i = $i+1;
            }
        print ('</ul>');
    print ('</div>');
