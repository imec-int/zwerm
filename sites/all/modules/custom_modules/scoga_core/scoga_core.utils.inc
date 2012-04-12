<?php
/**
 * Created by JetBrains PhpStorm.
 * User: creynder
 * Date: 12/04/12
 * Time: 10:20
 * To change this template use File | Settings | File Templates.
 */

function scoga_get_eid_by_uuid( $uuid, $entity_type = 'node' ){
    $query = new EntityFieldQuery();
    $result = $query
        ->entityCondition( 'entity_type', $entity_type )
        ->propertyCondition( 'uuid', $uuid )
        ->range( 0, 1 )
        ->execute();

    $eids = array_keys($result[ $entity_type ]);
    if( $eids ){
        return $eids[ 0 ];
    }

    return FALSE;
}


function scoga_get_output( $param, $callback ){
    if( is_array( $param ) ){
        $output = array();
        foreach( $param as $payload ){
            $output[] = $callback( $payload );
        }
        return $output;
    }else{
        return $callback( $param );
    }

    return FALSE;
}