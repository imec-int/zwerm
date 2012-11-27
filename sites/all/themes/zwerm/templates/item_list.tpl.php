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
                //paths are for /get_points
                if (isset($paths))
                {
                    if ($paths != '')
                    {
                        $path = $paths[$i];
                        print("<li  onmousedown=\"li_mousedown('".$path."',this);\"> <div class=\"link_truncated\">".$item."</div></li>");
                    }
                }
                //if there are no pathsm the case for /not_partner applies
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
