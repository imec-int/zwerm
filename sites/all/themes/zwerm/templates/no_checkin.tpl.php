<?php
    $names = $variables['names'];
    $uids = $variables['uids'];
    $formatted_names = array();
    foreach($names as $name)
    {
       $element_position = array_search($name, $names);
       $formatted_name = l($name,'user/'.$uids[$element_position ]);
       $formatted_names[] = $formatted_name;
    }
    $rows = array_chunk ( $formatted_names , 5 );
    $table_variables = array(
        'rows' => $rows
    );
    print theme('table',$table_variables);
?>