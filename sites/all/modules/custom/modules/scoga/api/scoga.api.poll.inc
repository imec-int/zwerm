<?php
/**
 * Camille Reynders, http://www.creynders.be
 * 10/01/13 - 10:01
 */

    function scoga_close_all_active_polls_of_campaign( $campaign_nid ){
        $poll_nodes = scoga_get_poll_nodes_for_campaign( $campaign_nid );
        foreach( $poll_nodes as $poll_node ){
            $poll_node->active = 0;
            node_save( $poll_node );
        }
    }

    /**
     * @param $campaign_nid
     *
     * @return array returns empty array when none found
     */
    function scoga_get_poll_nodes_for_campaign( $campaign_nid ){
        $poll_nids = scoga_get_poll_nids_for_campaign( $campaign_nid );
        $poll_nodes = array();
        foreach( $poll_nids as $poll_nid ){
            $poll_nodes[] = node_load( $poll_nid );
        }

        return $poll_nodes;
    }

    /**
     * Retrieves all active and published poll nids for a given campaign nid
     * @param $campaign_nid
     *
     * @return array when none found returns empty array
     */

    function scoga_get_poll_nids_for_campaign( $campaign_nid ){
        $entity_type = 'node';
        $query = new EntityFieldQuery();

        /*
         * retrieves all poll nids fulfilling following conditions
         * - published (status=1)
         * - open (active=1)
         * - linked to the campaign with id <code>campaign_nid</code> (field_campaign_target_id=$campaign_nid)
         *
         * see poll.module#poll_block_view for DB access code
         */

        $select = db_select('node', 'n');
        $select->join('poll', 'p', 'p.nid = n.nid');
        $select->join( 'field_data_field_campaign', 'campaign_field', 'campaign_field.entity_id = n.nid' );
        $select->fields('n', array('nid'))
          ->condition('n.status', 1)
          ->condition('p.active', 1)
          ->condition( 'campaign_field.field_campaign_target_id', $campaign_nid )
          ->orderBy('n.created', 'DESC')
        ;
        $records = $select->execute()->fetchAllAssoc('nid');
        $nids = array_keys( $records );
        return $nids;
    }