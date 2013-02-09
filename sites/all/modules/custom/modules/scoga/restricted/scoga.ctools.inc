<?php

    function scoga_handle_ctools_plugin_directory($module, $plugin)
    {
        watchdog('scoga','scoga_handle_ctools_plugin_directory');
        if (($module == 'visualization') && ($plugin == 'library')) {
            return 'includes/plugins';
        }
    }
?>