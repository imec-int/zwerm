<?php
/**
 * @file
 * deploy_example.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function deploy_example_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "deploy" && $api == "deploy_endpoints") {
    return array("version" => "1");
  }
  list($module, $api) = func_get_args();
  if ($module == "deploy" && $api == "deploy_plans") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function deploy_example_views_api() {
  list($module, $api) = func_get_args();
  if ($module == "views" && $api == "views_default") {
    return array("version" => "3.0");
  }
}
