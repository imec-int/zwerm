<?php
/**
 * Created by JetBrains PhpStorm.
 * User: creynder
 * Date: 06/02/12
 * Time: 15:00
 * To change this template use File | Settings | File Templates.
 */

function scoga_save_scores_for_player_action( $node ){
    //TODO check whether it's insert or update and act accordingly

    $user_account = user_load( $node->uid );
    $team_nid = $user_account->field_team_reference[ LANGUAGE_NONE ][ 0 ][ 'nid' ];
    $team_node = node_load( $team_nid );
    $playeraction_tid = $node->field_term_playeraction[ LANGUAGE_NONE ][ 0 ][ 'tid' ];
    $playeraction_term = taxonomy_term_load( $playeraction_tid );
    $score = $team_node->field_team_score_multiplier[ LANGUAGE_NONE ][ 0 ][ 'value' ] * variable_get( 'scoga_settings_' . strtolower($playeraction_term->name) . '_score' );
    $team_node->field_team_score[ LANGUAGE_NONE ][ 0 ][ 'value' ] += $score;

    //update team node
    node_save( $team_node );

    //TODO: add score to user points
}