<?php
    $rows = array_chunk ( $variables['content'] , 5 );
    $table_variables = array(
        'rows' => $rows
    );
    print theme('table',$table_variables);
?>