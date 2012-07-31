<?php
/**
 * Created by JetBrains PhpStorm.
 * User: creynder
 * Date: 31/07/12
 * Time: 15:31
 * To change this template use File | Settings | File Templates.
 */


    function scoga_handle_node_insert( $node ){
        switch( $node->type ){
            case SCOGA_WISHEDITEM_NODETYPE :
                module_load_include( 'api.wisheditem.inc', 'scoga', 'api' );
                scoga_sync_credits_for_wisheditem( $node );
                break;
            case SCOGA_WISHFULFILLED_NODETYPE:
                module_load_include( 'api.wisheditem.inc', 'scoga', 'api' );
                module_load_include( 'api.wishfulfilled.inc', 'scoga', 'api' );
                $wisheditem_node = scoga_award_wishfulfilled_to_player( $node );
                scoga_set_wisheditem_state( $wisheditem_node, 'fulfilled' );
                break;
        }
    }

    function scoga_handle_node_update( $node ){ //dsm( $node );
        switch( $node->type ){
            case SCOGA_WISHEDITEM_NODETYPE :
                module_load_include( 'api.wisheditem.inc', 'scoga', 'api' );
                $original_node = $node->original;
                $old_award_values = field_get_items( 'node', $original_node, 'field_wisheditem_award' );
                $old_award = intval( $old_award_values[ 0 ][ 'value' ] );
                scoga_sync_credits_for_wisheditem( $node, $old_award );
                break;
        }
    }

    function scoga_handle_node_delete( $node ){
        if( $node->type == SCOGA_WISHEDITEM_NODETYPE ){
            module_load_include( 'api.wisheditem.inc', 'scoga', 'api' );
            $old_award_values = field_get_items( 'node', $node, 'field_wisheditem_award' );
            $old_award = $old_award_values[ 0 ][ 'value' ];
            scoga_sync_credits_for_wisheditem( $node, intval( $old_award ) * 2 );
        }
    }

