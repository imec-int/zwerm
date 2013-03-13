<?php
/**
 * Camille Reynders, http://www.creynders.be
 * 13/03/13 - 10:30
 */

function scoga_handle_answer_approval( $updated_node ){
    $original_node = $updated_node->original;
    dsm( $updated_node );
    if( $original_node->status != $updated_node->status ){
        //a toggle of publication state has been made
        $question_nids = field_get_items( 'node', $original_node, 'field_answer_question');//use field_get_item, since language can vary
        $question_node = node_load( $question_nids[0]['nid']);
        $reward = scoga_get_field_value( $question_node, 'field_question_reward' );
        $user_account = user_load( $original_node->uid );
        $reason_params = array( '@user' => $user_account->name, '@question' => $question_node->title );
        module_load_include( 'api.points.inc', 'scoga', 'api/scoga' );
        if( $updated_node->status == 1 ){
            //answer "approved"
            $reason= t('Open question approved', $reason_params );
            scoga_award_points_to_user( $user_account->uid, $reward, $reason );
        }else{
            //answer unapproved
            $reason= t('Open question unapproved', $reason_params );
            scoga_award_points_to_user( $user_account->uid, -$reward, $reason ); //N.B. negative reward
        }
    }
}