<?php
    /*
     * Format the incoming assignment links as links and send the output to item_list.tpl.php
     */
    $assignment_titles = $variables['assignment_titles'];
    $assignment_paths = $variables['assignment_paths'];
    $i=0;
    $assignment_links = array();
    foreach ($assignment_titles as $title)
    {
        $path = $assignment_paths[$i];
        //if there's a path set, then it is not a header
        if ($path!=false)
            $assignment_link = l($title,$path);
        else
            $assignment_link = "<div class='list_header'>".t($title)."</div>";
        $assignment_links[] = $assignment_link;
        $i = $i +1;
    }
    $variables ['items'] = $assignment_links;
    print theme('item_list_get_points',$variables);
?>