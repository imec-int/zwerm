<?php
/**
 * Camille Reynders, http://www.creynders.be
 * 13/03/13 - 10:30
 */

function scoga_handle_answer_approval( $updated_node ){
    $original_node = $updated_node->original;
    if( $updated_node->status == 1){
        //a toggle of publication state has been made
        $question_nids = field_get_items( 'node', $original_node, 'field_answer_question');//use field_get_item, since language can vary
        $question_node = node_load( $question_nids[0]['nid']);
        $answer_nids = scoga_retrieve_published_answer_nids_by_references( $original_node->uid, $question_node->nid );
        if( count( $answer_nids ) == 1 && $answer_nids[0]==$updated_node->nid ){
            $reward = scoga_get_field_value( $question_node, 'field_question_reward' );
            $user_account = user_load( $original_node->uid );
            $reason_params = array( '@user' => $user_account->name, '@question' => $question_node->title );
            module_load_include( 'api.points.inc', 'scoga', 'api/scoga' );
            //answer "approved"
            $reason= t('Antwoord goedgekeurd', $reason_params );
            scoga_award_points_to_user( $user_account->uid, $reward, $reason );
        }

    }
}

function scoga_retrieve_published_answer_nids_by_references( $uid, $question_nid ){
    $entity_type = 'node';
    $query = new EntityFieldQuery();
    $result = $query
        ->entityCondition( 'entity_type', $entity_type )
        ->entityCondition( 'bundle', SCOGA_ANSWER_NODETYPE )
        ->propertyCondition( 'status', 1 )
        ->propertyCondition( 'uid', $uid )
        ->fieldCondition( 'field_answer_question', 'nid', $question_nid )
        ->execute();
    if( isset( $result[ $entity_type ] ) ){
        return array_keys( $result['node'] );
    }

    return array();
}