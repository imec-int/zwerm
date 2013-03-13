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
                _handle_wisheditem_inserted( $node );
                break;
            case SCOGA_WISHFULFILLED_NODETYPE:
                _handle_wishfulfilled_inserted( $node );
                break;
            case SCOGA_EVENT_NODETYPE:
                _handle_event_inserted( $node );
                break;
        }
    }

    function scoga_handle_node_delete( $node ){
        switch( $node->type ){
            case SCOGA_WISHEDITEM_NODETYPE :
                _handle_wisheditem_deleted( $node );
                break;
            case SCOGA_CAMPAIGN_NODETYPE:
                _handle_campaign_deleted( $node );
                break;
        }
    }

    function scoga_handle_node_update( $node ){ //dsm( $node );
        switch( $node->type ){
            case SCOGA_WISHEDITEM_NODETYPE :
                _handle_wisheditem_updated( $node );
                break;
            case SCOGA_EVENT_NODETYPE:
                _handle_event_updated( $node );
                break;
            case SCOGA_ANSWER_NODETYPE:
                _handle_answer_updated( $node );
                break;
        }
    }


    function _handle_wishfulfilled_inserted( $node ){
        module_load_include( 'api.wishlist.inc', 'scoga', 'api/scoga' );
        $wisheditem_node = scoga_award_wishfulfilled_to_player( $node );
        scoga_set_wisheditem_state( $wisheditem_node, 'fulfilled' );
    }

    function _handle_wisheditem_inserted( $node ){
        module_load_include( 'api.wishlist.inc', 'scoga', 'api/scoga' );
        scoga_sync_credits_for_wisheditem( $node );
        scoga_set_campaign_of_wisheditem( $node );
        field_attach_update( 'node', $node ); //makes sure the changes to the node data stick
    }

    function _handle_wisheditem_updated( $node ){
        module_load_include( 'api.wishlist.inc', 'scoga', 'api/scoga' );
        $original_node = $node->original;
        $old_award = intval( scoga_get_field_value( $original_node, 'field_wisheditem_award' ) );
        scoga_sync_credits_for_wisheditem( $node, $old_award );
    }

    function _handle_wisheditem_deleted( $node ){
        module_load_include( 'api.wishlist.inc', 'scoga', 'api/scoga' );
        $old_award = scoga_get_field_value( $node, 'field_wisheditem_award' );
        scoga_sync_credits_for_wisheditem( $node, intval( $old_award ) * 2 );
    }

    function _handle_campaign_deleted( $node ){
        if( scoga_get_current_campaign_nid() == $node->nid ){
            scoga_set_current_campaign_nid( SCOGA_NULL_CAMPAIGN_NID );
        }

        module_load_include( 'api.points.inc', 'scoga', 'api/scoga' );
        scoga_delete_userpoints_category( $node->title );
        module_load_include( 'api.checkin.inc', 'scoga', 'api/scoga' );
        scoga_delete_combocheckin_relationship_type( $node->title );
    }


    function _handle_event_inserted( $node ){
        module_load_include( 'api.event.inc', 'scoga', 'api/scoga' );
        scoga_check_nonunique_passphrase( $node );
    }

    function _handle_event_updated( $node ){
        module_load_include( 'api.event.inc', 'scoga', 'api/scoga' );
        scoga_check_nonunique_passphrase( $node );
    }


    function _handle_answer_updated( $node ){
        module_load_include( 'api.answers.inc', 'scoga', 'api/scoga' );
        scoga_handle_answer_approval( $node );
    }