<?php
/**
 * @file
 * scoga_checkins_view.features.inc
 */

/**
 * Implements hook_views_api().
 */
function scoga_checkins_view_views_api() {
  list($module, $api) = func_get_args();
  if ($module == "views" && $api == "views_default") {
    return array("version" => "3.0");
  }
}
