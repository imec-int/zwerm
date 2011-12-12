<?php

/**
 * Returns the items for a given plan.
 *
 * @param $plan_name
 *   Name of the managed plan to fetch entities from.
 */
function deploy_manager_get_entities($plan_name) {
  $collection = array();
  $result = db_query("SELECT * FROM {deploy_manager_entities} WHERE plan_name = :plan_name", array(':plan_name' => $plan_name));
  foreach ($result as $record) {
    $collection[$record->entity_type][$record->entity_id] = TRUE;
  }
  // If the plan fetched from the database is empty, try fetch default UUID
  // entities (keyed with the name of this plan).
  if (empty($collection)) {
    $collections = module_invoke_all('uuid_default_entities');
    foreach ($collections as $collection_name => $entities) {
      if ($collection_name == $plan_name) {
        foreach ($entities as $data) {
          // We're not adding dependencies when writing to the plan. They'll be
          // looked up and added when we read from the plan.
          if ($data['relationship']['type'] == ENTITY_RELATIONSHIP_ORIGIN) {
            // We can't do a multi load/insert per entity type here, since they
            // need to be added in the order the come.
            $entity_id = reset(entity_get_id_by_uuid($data['entity_type'], array($data['entity_uuid'])));
            if (!empty($entity_id)) {
              $collection[$data['entity_type']][$entity_id] = TRUE;
            }
          }
        }
      }
    }
  }
  return $collection;
}

/**
 * Loads a managed plan with the given name, returns false if no such plan
 * exists.
 */
function deploy_manager_plan_load($name) {
  $result = deploy_plan_load_all(array('aggregator_plugin' => 'DeployAggregatorManaged'));
  if (isset($result[$name])) {
    return $result[$name];
  }
  return FALSE;
}

/**
 * Returns a list of all managed plans, i.e. all plans that use the
 * DeployAggregatorManager aggregator plugin.
 */
function deploy_manager_plan_load_all() {
  return deploy_plan_load_all(array('aggregator_plugin' => 'DeployAggregatorManaged'));
}

/**
 * Options callback for the deploy_plan data type.
 */
function deploy_manager_plan_get_options($args = array()) {
  $default_args = array(
    'aggregator_plugin' => 'DeployAggregatorManaged',
  );
  $args = array_merge($default_args, $args);

  $plans = deploy_plan_load_all($args);
  $options = array();
  foreach ($plans as $plan_name => $info) {
    $options[$plan_name] = $info->title;
  }
  return $options;
}

/**
 * Adds an entity to a managed deployment plan.
 *
 * @param $plan_name
 *   The machine name of the plan to add to.
 * @param $entity_type
 *   The entity type to be deployed.
 * @param $entity
 *   The entity to be deployed.
 */
function deploy_manager_add_to_plan($plan_name, $entity_type, $entity) {
  list($entity_id, $revision_id) = entity_extract_ids($entity_type, $entity);
  $revision_id = ($revision_id === NULL) ? 0 : $revision_id;

  try {
    db_insert('deploy_manager_entities')
      ->fields(array(
        'plan_name' => $plan_name,
        'entity_type' => $entity_type,
        'entity_id' => $entity_id,
        'revision_id' => $revision_id,
        'timestamp' => time(),
      ))
      ->execute();
  }
  // The query failed, most probably because of duplicate primary keys.
  catch (Exception $e) {
    watchdog('deploy', 'Adding !entity_type !entity_id of revision !revision_id to deployment plan @plan failed. Only one entity per revision is allowed.', array('!entity_type' => $entity_type, '!entity_id' => $entity_id, '!revision_id' => $revision_id, '@plan' => $plan_name), WATCHDOG_NOTICE);
  }
}

/**
 * Delete an entity from a managed deployment plan.
 *
 * @param $plan_name
 *   The machine name of the plan to remove from.
 *
 * @param $entity_id
 *   The id of the entity to be removed from the plan.
 */
function deploy_manager_delete_from_plan($plan_name, $entity_type, $entity) {
  list($entity_id, $revision_id) = entity_extract_ids($entity_type, $entity);
  db_delete('deploy_manager_entities')
    ->condition('entity_type', $entity_type)
    ->condition('entity_id', $entity_id)
    ->execute();
}
