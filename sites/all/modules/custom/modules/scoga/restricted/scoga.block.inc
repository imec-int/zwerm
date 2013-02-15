<?php
    function scoga_handle_block_info()
    {
        $blocks['team_score_graph_block'] = array(
            'info' => 'Team score graph',
        );
        return $blocks;
    }

    function scoga_handle_block_view($delta = '')
    {
        module_load_include( 'page.inc', 'scoga', 'restricted/scoga' );
        $block = array();
        switch ($delta) {
            case 'team_score_graph_block':
                $block['subject'] = t('Team score graph');
                $block['content'] = scoga_team_score_graph();
                break;
        }
        return $block;
    }
?>