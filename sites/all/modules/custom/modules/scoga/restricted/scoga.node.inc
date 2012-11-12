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
                module_load_include( 'api.wishlist.inc', 'scoga', 'api/scoga' );
                scoga_sync_credits_for_wisheditem( $node );
                scoga_set_campaign_of_wisheditem( $node );
                field_attach_update('node', $node); //makes sure the changes to the node data stick
                break;
            case SCOGA_WISHFULFILLED_NODETYPE:
                module_load_include( 'api.wishlist.inc', 'scoga', 'api/scoga' );
                $wisheditem_node = scoga_award_wishfulfilled_to_player( $node );
                scoga_set_wisheditem_state( $wisheditem_node, 'fulfilled' );
                break;
            case SCOGA_CAMPAIGN_NODETYPE:
                module_load_include( 'api.team.inc', 'scoga', 'api/scoga' );
                scoga_create_campaignteam_entities_for_campaign( $node );
                break;
        }
    }

    function scoga_handle_node_update( $node ){ //dsm( $node );
        switch( $node->type ){
            case SCOGA_WISHEDITEM_NODETYPE :
                module_load_include( 'api.wishlist.inc', 'scoga', 'api/scoga' );
                $original_node = $node->original;
                $old_award = intval( scoga_get_field_value( $original_node, 'field_wisheditem_award' ) );
                scoga_sync_credits_for_wisheditem( $node, $old_award );
                break;
        }
    }

    function scoga_handle_node_delete( $node ){
        switch( $node->type ){
            case SCOGA_WISHEDITEM_NODETYPE :
                module_load_include( 'api.wishlist.inc', 'scoga', 'api/scoga' );
                $old_award = scoga_get_field_value( $node, 'field_wisheditem_award' );
                scoga_sync_credits_for_wisheditem( $node, intval( $old_award ) * 2 );
                break;
            case SCOGA_CAMPAIGN_NODETYPE:
                module_load_include( 'api.team.inc', 'scoga', 'api/scoga' );
                scoga_delete_campaignteam_entities_for_campaign( $node );
                break;
        }
    }

