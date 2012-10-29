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
        $title_crop_treshold = 20;
        if (strlen($title)>$title_crop_treshold)
        {
            $title = substr($title,0,$title_crop_treshold).'...';
        }
        $path = $assignment_paths[$i];
        $assignment_link = l($title,$path);
        $assignment_links[] = $assignment_link;
        $i = $i +1;
    }
    $variables ['items'] = $assignment_links;
    print theme('item_list',$variables);
?>