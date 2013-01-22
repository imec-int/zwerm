<?php
/**
 * Camille Reynders, http://www.creynders.be
 * 07/11/12 - 13:04
 */

class Page{
    public $nid;
    public $machine_name;
    public $title;
    public $body;
}

function scoga_get_page_vos(){
    $nids = scoga_get_page_nids();
    $vos = scoga_get_page_vos_by_nids( $nids );
    return $vos;
}

function scoga_get_page_nids(){
    $entity_type = 'node';
    $query = new EntityFieldQuery();
    $query
        ->entityCondition( 'entity_type', $entity_type )
        ->entityCondition( 'bundle', SCOGA_PAGE_NODETYPE )
        ->propertyCondition( 'status', '1', '=' )
        ->propertyOrderBy( 'nid' );
    $result = $query->execute();


    if( $result && array_key_exists( $entity_type, $result ) ){
        return array_keys( $result[ $entity_type ] );
    }

    return array();
}

function scoga_get_page_vos_by_nids( $nids ){
    return scoga_get_output( $nids, 'scoga_get_page_vo_by_nid' );
}

function scoga_get_page_vo_by_nid( $nid ){
    $entity_type = 'node';
    $page_entity = node_load( $nid );

    return scoga_create_page_vo( $page_entity );
}

function scoga_create_page_vo( $page_entity ){
    $output = new Page();
    $output->nid = $page_entity->nid;
    $output->machine_name = scoga_get_field_value( $page_entity, 'field_servicepage_machine_name' );
    $output->body = check_markup( scoga_get_field_value( $page_entity, 'body' ), FLASH_HTML_FORMAT, '', TRUE );
    $output->title = $page_entity->title;

    return $output;
}


function scoga_get_page_vo_by_machine_name( $machine_name ){
    $entity = scoga_get_page_entity_by_machine_name( $machine_name );
    if( $entity ){
        return scoga_create_page_vo( $entity );
    }

    return FALSE;
}

function scoga_get_page_entity_by_machine_name( $machine_name ){
    $page_nids = scoga_get_page_nids_by_machine_name( $machine_name );

    switch( count( $page_nids ) ){
        case 1 :
            //exactly one match, as it should
            return node_load( $page_nids[ 0 ] );
        case 0 :
            return FALSE;
        default :
            throw new Exception( 'RFID reader registered multiple times' );
    }
}

function scoga_get_page_nids_by_machine_name( $machine_name ){
    $entity_type = 'node';
    $query = new EntityFieldQuery();
    $query
        ->entityCondition( 'entity_type', $entity_type )
        ->entityCondition( 'bundle', SCOGA_PAGE_NODETYPE )
        ->fieldCondition( 'field_servicepage_machine_name', 'value', $machine_name, '=' )
    ;
    $result = $query->execute();
    if( $result && array_key_exists( $entity_type, $result ) ){
        return array_keys( $result[ $entity_type ] );
    }

    return array();

}