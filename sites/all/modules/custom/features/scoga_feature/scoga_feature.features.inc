<?php
/**
 * @file
 * scoga_feature.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function scoga_feature_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "ds" && $api == "ds") {
    return array("version" => "1");
  }
  list($module, $api) = func_get_args();
  if ($module == "openlayers" && $api == "openlayers_maps") {
    return array("version" => "1");
  }
  list($module, $api) = func_get_args();
  if ($module == "services" && $api == "services") {
    return array("version" => "3");
  }
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function scoga_feature_views_api() {
  return array("version" => "3.0");
}

/**
 * Implements hook_flag_default_flags().
 */
function scoga_feature_flag_default_flags() {
  $flags = array();
  // Exported flag: "Unredeemed wish".
  $flags['flag_unredeemed_wish'] = array(
    'content_type' => 'node',
    'title' => 'Unredeemed wish',
    'global' => '1',
    'types' => array(
      0 => 'nodetype_wished_item',
    ),
    'flag_short' => 'Wish unredeemed',
    'flag_long' => 'Flag this wish as having been solved, but unredeemed',
    'flag_message' => 'This wish has been flagged as "unredeemed"',
    'unflag_short' => 'Wish not unredeemed',
    'unflag_long' => 'Flag this wish as not being unredeemed',
    'unflag_message' => 'This wish has been unflagged as "unredeemed"',
    'unflag_denied_text' => '',
    'link_type' => 'toggle',
    'roles' => array(
      'flag' => array(
        0 => '4',
        1 => '3',
      ),
      'unflag' => array(
        0 => '4',
        1 => '3',
      ),
    ),
    'show_on_page' => 1,
    'show_on_teaser' => 1,
    'show_on_form' => 0,
    'access_author' => '',
    'i18n' => 0,
    'module' => 'scoga_feature',
    'locked' => array(
      0 => 'name',
    ),
    'api_version' => 2,
  );
  // Exported flag: "Unsolvable wish".
  $flags['flag_unsolvable_wish'] = array(
    'content_type' => 'node',
    'title' => 'Unsolvable wish',
    'global' => '1',
    'types' => array(
      0 => 'nodetype_wished_item',
    ),
    'flag_short' => 'Unsolvable wish',
    'flag_long' => 'Flag this wish as being unsolvable',
    'flag_message' => 'This wish has been flagged as "unsolvable"',
    'unflag_short' => 'Solvable wish',
    'unflag_long' => 'Unflag this wish as being unsolvable ',
    'unflag_message' => 'This wish has been unflagged as "unsolvable"',
    'unflag_denied_text' => '',
    'link_type' => 'toggle',
    'roles' => array(
      'flag' => array(
        0 => '4',
        1 => '3',
      ),
      'unflag' => array(
        0 => '4',
        1 => '3',
      ),
    ),
    'show_on_page' => 1,
    'show_on_teaser' => 1,
    'show_on_form' => 0,
    'access_author' => '',
    'i18n' => 0,
    'module' => 'scoga_feature',
    'locked' => array(
      0 => 'name',
    ),
    'api_version' => 2,
  );
  return $flags;
}

/**
 * Implements hook_image_default_styles().
 */
function scoga_feature_image_default_styles() {
  $styles = array();

  // Exported image style: avatar_pinhead.
  $styles['avatar_pinhead'] = array(
    'name' => 'avatar_pinhead',
    'effects' => array(
      4 => array(
        'label' => 'Schalen en bijsnijden',
        'help' => 'Bij het schalen blijft de breedte-hoogte verhouding van de oorspronkelijke afbeelding behouden. Bij het bijsnijden wordt de langste zijde ingekort. Hiermee kunt u bijvoorbeeld vierkante miniaturen maken.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => '32',
          'height' => '32',
        ),
        'weight' => '3',
      ),
    ),
  );

  return $styles;
}

/**
 * Implements hook_node_info().
 */
function scoga_feature_node_info() {
  $items = array(
    'article' => array(
      'name' => t('Artikel'),
      'base' => 'node_content',
      'description' => t('Gebruik <em>artikelen</em> voor tijdsgebonden inhoud zoals nieuws, persberichten of blog-berichten.'),
      'has_title' => '1',
      'title_label' => t('Titel'),
      'help' => '',
    ),
    'generic_assignment' => array(
      'name' => t('Generic assignment'),
      'base' => 'node_content',
      'description' => t('This is an assignment content type that is not linked to an automatic point awarding mechanism, but can be used to place assignments in the play list. '),
      'has_title' => '1',
      'title_label' => t('Titel'),
      'help' => '',
    ),
    'nodetype_campaign' => array(
      'name' => t('Campaign'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Titel'),
      'help' => '',
    ),
    'nodetype_campaign_team' => array(
      'name' => t('Campaign Team'),
      'base' => 'node_content',
      'description' => t('Assigns a specific team to a specific campaign, this is a separate node type, to allow for specific settings per team per campaign, like the points modifier and the total points'),
      'has_title' => '1',
      'title_label' => t('Titel'),
      'help' => '',
    ),
    'nodetype_checkin' => array(
      'name' => t('Checkin'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Titel'),
      'help' => '',
    ),
    'nodetype_event' => array(
      'name' => t('Activiteit'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Titel'),
      'help' => '',
    ),
    'nodetype_event_fulfilled' => array(
      'name' => t('Activiteit vervuld'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'nodetype_logmessages' => array(
      'name' => t('Service message'),
      'base' => 'node_content',
      'description' => t('Service messages are only consumed by service resources. They are created by the system only, for instance when a campaign change occurs.
A syndication of service messages is used by service resource consumers.
NOT MEANT FOR MANUAL CONSTRUCTION.'),
      'has_title' => '1',
      'title_label' => t('Titel'),
      'help' => '',
    ),
    'nodetype_rfid_reader' => array(
      'name' => t('RFID reader'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Titel'),
      'help' => '',
    ),
    'nodetype_service_page' => array(
      'name' => t('Service page'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Titel'),
      'help' => '',
    ),
    'nodetype_team' => array(
      'name' => t('Team'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Titel'),
      'help' => '',
    ),
    'nodetype_wish_fulfilled' => array(
      'name' => t('Wijkzoekertje vervuld'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Titel'),
      'help' => '',
    ),
    'nodetype_wished_item' => array(
      'name' => t('Wijkzoekertje'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Titel'),
      'help' => '',
    ),
  );
  return $items;
}
