<?php
/**
 * Camille Reynders, http://www.creynders.be
 * 05/02/13 - 09:59
 */

    function scoga_devel_delete_referencing_nodes( $target_nid ){
        $conditions = array( 'type' => 'entityreference' );
        $include_additional = array( 'include_inactive' => TRUE );
        $fields = field_read_fields( $conditions, $include_additional );
        //dsm( $fields );
        foreach( $fields as $field ){
            $query = new EntityFieldQuery();
            $results = $query
                ->entityCondition( 'entity_type', 'node' )
                ->fieldCondition( $field, 'target_id', $target_nid )
                ->execute();
            if( array_key_exists( 'node', $results ) ){
                $nids = array_keys( $results[ 'node' ] );
                node_delete_multiple( $nids );
            }
        }
    }

