<?php
/**
 * Camille Reynders, http://www.creynders.be
 * 11/09/12 - 16:44
 */
    class Network{
        public $relationships;
        public $types;
    }

    class Relationship{
        public $rid;
        public $rtid;
        public $requester_id;
        public $requestee_id;
    }

    class RelationshipType{
        public $rtid;
        public $name;
        public $plural_name;
    }

    function scoga_create_network_vo(){
        $output = new Network();
        $output->relationships = scoga_get_all_relationships();
        $output->types = scoga_get_all_relationship_types();
        return $output;
    }

    function scoga_get_all_relationship_types(){
        $force_refresh = true;
        $rtype_entities = user_relationships_types_load( $force_refresh );
        $output = array();
        foreach( $rtype_entities as $rtype_entity ){
            $output[] = scoga_create_relationship_type_vo( $rtype_entity );
        }
        return $output;
    }

    function scoga_create_relationship_type_vo( $entity ){
        $output = new RelationshipType();
        $output->rtid = $entity->rtid;
        $output->name = $entity->name;
        $output->plural_name = $entity->plural_name;
        return $output;
    }

    function scoga_get_all_relationships(){
        $force_refresh = true;
        $rtype_nodes = user_relationships_types_load( $force_refresh );
        $rtids = array_keys( $rtype_nodes );
        $relationships = user_relationships_load( array('rtid' => $rtids ) );

        $output = array();
        foreach( $relationships as $relationship ){
            $output[] = scoga_create_relationship_vo( $relationship );
        }

        return $output;
    }

    function scoga_create_relationship_vo( $entity ){
        $output = new Relationship();
        $output->rid = $entity->rid;
        $output->rtid = $entity->rtid;
        $output->requestee_id = $entity->requestee_id;
        $output->requester_id = $entity->requester_id;
        return $output;
    }

    function scoga_create_random_relationships( $n = 20 ){
        module_load_include( 'api.player.inc', 'scoga', 'api/scoga' );
        $uids = scoga_get_all_player_uids();
        $force_refresh = true;
        $rtype_nodes = user_relationships_types_load( $force_refresh );
        $rtids = array_keys( $rtype_nodes );
        $num_rtypes = count( $rtids );
        $num_uids = count( $uids );
        for( $i=0; $i<$n; $i++ ){
            $rtype_index = rand( 0, $num_rtypes -1 );
            $rtid = $rtids[ $rtype_index ];
            $requester_index = rand( 0, $num_uids -1 );
            $requestee_index = rand( 0, $num_uids -1 );
            if( $requestee_index != $requester_index ){
                $requester = $uids[ $requester_index ];
                $requestee = $uids[ $requestee_index ];
                dsm( $requester . ',' . $requestee );
                $request = user_relationships_request_relationship( $requester, $requestee, $rtid, TRUE );
                dsm( $request );
            }
        }
    }