<?php
/**
 * Created by JetBrains PhpStorm.
 * User: creynder
 * Date: 06/02/12
 * Time: 15:00
 * To change this template use File | Settings | File Templates.
 */


function _retrieve_terms_by_machinename( $machine_name )
{
    $vocab = taxonomy_vocabulary_machine_name_load( $machine_name );
    $terms = taxonomy_get_tree($vocab->vid, 0, NULL, TRUE);
    return $terms;
}
