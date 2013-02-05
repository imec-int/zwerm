<?php
/**
 * Camille Reynders, http://www.creynders.be
 * 05/02/13 - 09:58
 */

    function scoga_devel_handle_node_delete( $node ){
        scoga_devel_delete_referencing_nodes( $node->nid );
    }

