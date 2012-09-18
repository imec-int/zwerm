<?php
    $assignment_titles = $variables['assignment_titles'];
    $variables ['items'] = $variables['assignment_titles'];
    print theme('item_list',$variables);
?>