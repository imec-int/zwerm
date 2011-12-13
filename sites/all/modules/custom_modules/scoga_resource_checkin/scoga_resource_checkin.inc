<?php
/**
 * Created by JetBrains PhpStorm.
 * User: creynder
 * Date: 13/12/11
 * Time: 13:34
 * To change this template use File | Settings | File Templates.
 */

function _reader_checkin_index( $params ){
    watchdog( 'scoga_reader_checkin_index', serialize($params));
    $view = views_get_view( 'checkins' );
   	$view->execute_display( 'default' );
   	$results = $view->result;
    return $results;
}

function _reader_checkin_create( $params ){
    watchdog('scoga_reader_checkin_create', serialize( $params ) );
    return $params;
}