<?php
/**
 * Camille Reynders, http://www.creynders.be
 * 10/12/12 - 13:44
 */

class Config{
    public $last_transaction_nid;
}

function scoga_get_config_vo(){
    return scoga_create_config_vo();
}

function scoga_create_config_vo(){
    module_load_include( 'api.points.inc', 'scoga', 'api/scoga' );
    $output = new Config();
    $output->last_transaction_nid = scoga_get_highest_transaction_id();

    return $output;
}