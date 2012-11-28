<?php
/**
 * Camille Reynders, http://www.creynders.be
 * 11/09/12 - 16:44
 */
    class Relationship{
        public $rid;
        public $requester_id;
        public $requestee_id;
    }

    function scoga_get_current_relationships(){
        /*
        $force_refresh = true;
        $rtype_nodes = user_relationships_types_load( $force_refresh );
        $rtids = array_keys( $rtype_nodes );
        */
        $rtid = scoga_get_current_combocheckin_rtid();
        $relationships = user_relationships_load( array('rtid' => $rtid ) );

        $output = array();
        foreach( $relationships as $relationship ){
            $output[] = scoga_create_relationship_vo( $relationship );
        }

        return $output;
    }

    function scoga_create_relationship_vo( $entity ){
        $output = new Relationship();
        $output->rid = $entity->rid;
        $output->requestee_id = $entity->requestee_id;
        $output->requester_id = $entity->requester_id;
        return $output;
    }

