<?php
    /*
     * Bundles the $names and $uids as a list and sends this to item_list.tpl.php
     * for formatting as an item list
     */
    $names = $variables['names'];
    $uids = $variables['uids'];
    $formatted_names = array();
    $uids_reordered = array();
    $i=0;
    foreach($names as $key => $name)
    {
       $element_position = array_search($name, $names);
       $formatted_name = l($name,'user/'.$uids[$element_position ]);
       $formatted_names[$key] = $formatted_name;
       $i=$i+1;
    }
    $variables ['items'] =  $formatted_names;
    print theme('item_list',$variables);
?>