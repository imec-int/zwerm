<?php

    function scoga_handle_ctools_plugin_directory($module, $plugin)
    {
        if (($module == 'visualization') && ($plugin == 'library')) {
            return 'includes/plugins';
        }
    }
?>