<?php
/**
 * Wouter Van den Bosch, http://twitter.com/mindwraps
 * 12/03/13 - 15:25
 */


/**
 * Checks if the player has reached his max. allowed POI for this Geochallenge
 * triggers form_set_error if this is the case
 * form_set_error handles graceful redirect to form
 *
 * @param $node
 *
 */
function scoga_validate_poi_limit( $node, $form, &$form_state ){
  //Fetch the Geochallenge node limit
  //In SCOGA we fetch the Geochallenge nid from the URL arguments
  $geochallenge_node_nid = arg(1);

  if ($geochallenge_node_nid > 0) {
    $geochallenge_node_limit = scoga_fetch_geochallenge_poi_limit($geochallenge_node_nid);
    if (!$geochallenge_node_limit) {
      //there is no limit, so we can happily continue
      return;
    }
  } else {
    // Something is wrong with the Geochallenge ref within the POI node
    watchdog('SCOGA','Unable to save POI due to invalid Geochallenge Reference in POI node.');
    drupal_set_message(t('Uh oh. We were unable to save your contribution due to an error. Support has been notified of this.'));
    form_set_error('geochallenge',t('Error occurred. Unable to save POI due to invalid geochallenge reference in POI'));
  }

  //fetch the user's POI count for this Geochallenge
  $user_geochallenge_poi_count = scoga_fetch_user_poi_count($geochallenge_node_nid);

  //From here on we can assume that there is a valid value for $geochallenge_node_limit and
  //$user_geochallenge_poi_count to compare

  if ($user_geochallenge_poi_count >= $geochallenge_node_limit) {
    //The user has reached his max allowed POI limit for this geochallenge
    drupal_set_message(t('You have reached the maximum allowed amount of points you can add to this Geochallenge. You will not be able to add any more points to this challenge. Thanks for your contributions so far!'));
    form_set_error('geochallenge',t('You have reached the maximum allowed amount of points you can add to this Geochallnge. Thanks for that!'));
  } else {
    //The user can happily continue adding POI's for now
    return;
  }
}


/**
 * Checks the max poi allowed for a given geochallenge
 * returns the amound of POI allowed or false for unlimited values
 *
 * @param $nid
 *
 * @return integer or false
 */
function scoga_fetch_geochallenge_poi_limit( $nid ) {
  $geochallenge_node = node_load($nid);
  if ($geochallenge_node && $geochallenge_node->type==SCOGA_GEOCHALLENGE_NODETYPE) {
    if ($geochallenge_node->field_max_poi_per_player && count($geochallenge_node->field_max_poi_per_player) > 0) {
      return $geochallenge_node->field_max_poi_per_player['und'][0]['value'];
    } else {
      return false;
    }
  } else {
    return false;
  }
}

/**
 * Checks the amount of POI the user has entered for a given Geochallenge
 * returns the amount of POI the user already added
 *
 * @param $geochallenge_nid,$uid
 *
 * @return integer
 */
function scoga_fetch_user_poi_count($geochallenge_nid,$uid = NULL) {
  if(!$uid) {
    global $user;
    $uid = $user->uid;
  }

  // Query the amount of POI for given Geochallenge for given uid
  $query = new EntityFieldQuery();
  $result = $query
    ->entityCondition( 'entity_type', 'node' )
    ->entityCondition( 'bundle', SCOGA_POI_NODETYPE )
    ->propertyCondition( 'uid', $uid )
    ->fieldCondition( 'field_ref_geo_challenge', 'target_id', $geochallenge_nid )
    ->count()
    ->execute()
  ;

  if ($result) {
    return $result;
  } else {
    return 0;
  }
}

/**
 * Checks the amount of POI that have been entered for a geochallenge, split by team
 * returns an array with amount of POI added per team
 *
 * @param $geochallenge_nid
 *
 * @return array
 */
/*
function scoga_fetch_poi_count($geochallenge_nid) {
  // Query the amount of POI for given Geochallenge
  $query = new EntityFieldQuery();
  $result = $query
    ->entityCondition( 'entity_type', 'node' )
    ->entityCondition( 'bundle', SCOGA_POI_NODETYPE )
    ->fieldCondition( 'field_ref_geo_challenge', 'target_id', $geochallenge_nid )
    ->execute()
  ;

  dsm($result);

  if ($result) {
    foreach ($result as $poi) {
      drupal_set_message('foo');
    }
  }

  return('bar');
}
*/
