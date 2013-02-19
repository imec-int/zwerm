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

    /**
     * @param $entity
     *
     * @return Relationship
     */
    function scoga_create_relationship_vo( $entity ){
        $output = new Relationship();
        $output->rid = $entity->rid;
        $output->requestee_id = $entity->requestee_id;
        $output->requester_id = $entity->requester_id;
        return $output;
    }

    function scoga_get_relationship_vos_after_rid( $last_rid = 0 ){
        if( $last_rid >= 0 ){
            $query =
                " SELECT rid, requester_id, requestee_id "
                    . "FROM {user_relationships} "
                    . "WHERE rtid = :rtid "
                    . "AND rid > :rid "
                    . "GROUP BY rid"
            ;
            $rows = db_query( $query, array(
                ':rtid' => scoga_get_current_combocheckin_rtid(),
                ':rid'  => $last_rid
            ));
            $result = array();
            foreach( $rows as $row ){
                $relationships = user_relationships_load( array( 'rid' => $row->rid ) );
                $result[] = scoga_create_relationship_vo( $relationships[ $row->rid ] );
            }

            return $result;
        }

        return array();

    }
