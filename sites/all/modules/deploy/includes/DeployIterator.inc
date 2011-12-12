<?php

/**
 * Wrapper class around the SPL RecursiveIteratorIterator.
 */
class DeployIteratorIterator extends RecursiveIteratorIterator {}

/**
 * Iterator class which does the heavy lifting for detecting dependencies.
 *
 * This iterator is reponsible for taking in an array of entity types and ids,
 * figuring out all their dependencies, and returning an iterable object of all
 * of them in a deployable order (dependencies first). And since dependencies
 * in theory are nested and recursive, we are using a recursive iterator here.
 *
 * @todo
 *   We need to throw an exception when we detect a circular dependency.
 *
 * @todo
 *   Look into Entity Property API to see if we can do anything cool/effective
 *   with the chaining feature there.
 */
class DeployIterator implements RecursiveIterator {

  /**
   * The entities to be iterated over.
   *
   * @var array
   */
  public $entities = array();

  /**
   * An array of dependencies to the entity being parsed, keyed by the entity id
   * of the entity being parsed.
   *
   * @var array
   */
  public $dependencies = array();

  /**
   * An array of belongings to the entity being parsed, keyed by the entity id
   * of the entity being parsed.
   *
   * @var array
   */
  public $belongings = array();

  /**
   * An array of all traversed entities with information on how they were added
   * to the tree, either as a 'origin', 'dependency', or 'beloging'. If the
   * entity was added as a 'dependency' or 'beloging' information about it's
   * originator can be found.
   *
   * This property will eventually contain the same keys as $this->traversed,
   * but the difference is when the information is added, and when we need to
   * check on it.
   *
   * @var array
   */
  public $relationships = array();

  /**
   * Keeps track of the entity type currently being iterated over.
   *
   * @var string
   */
  public $entityType = NULL;

  /**
   * Keeps track of the entity ids per entity type that have already been trav-
   * ersed.
   *
   * This property will eventually contain the same key as $this->relationships,
   * but the difference is when the information is added, and when we need to
   * check on it.
   *
   * @var array
   */
  public $traversed = array();

  /**
   * Constructor.
   *
   * The $entities array should be structured as below, where all string keys
   * are entity types and the numeric keys are entity ids.
   * @code
   *   $entities = array(
   *     'node' => array(
   *       10 => TRUE,
   *       12 => TRUE,
   *     ),
   *     'taxonomy_term' => array(
   *       16 => TRUE,
   *     ),
   *   );
   * @endcode
   *
   * @param array $entities
   *   A structured array of entity ids and their entity types.
   *
   * @param array $parent
   *   The parent array of the current entity.
   */
  public function __construct($entities, &$parent = NULL) {
    $this->entities = $entities;

    if (empty($parent)) {
      foreach ($this->entities as $entity_type => $entity_ids) {
        foreach ($entity_ids as $entity_id => $somethings) {
          // Make sure the 'entities' property is in the correct format, to keep
          // things consistent.
          //$this->entities[$entity_type][$entity_id] = TRUE;
          // Since this entity has no $parent it means that this an 'origin',
          // ie. an entity that was added directly to the plan, not as a
          // 'dependency' or 'belonging'.
          $this->relationships[$entity_type][$entity_id] = array(
            'type' => ENTITY_RELATIONSHIP_ORIGIN,
            'origin' => array(),
          );
        }
      }
    }
    else {
      // We need to keep track of our relationships traversing down the tree.
      $this->relationships =& $parent->relationships;
      // We need to keep track of what the parent already traversed for us.
      $this->traversed =& $parent->traversed;
    }
  }

  /**
   * Returns TRUE if an iterator can be created for the current item in the
   * entities array.
   *
   * @return boolean
   */
  public function hasChildren() {
    $key = $this->key();
    $current = $this->current();
    if (is_array($current) && !isset($current['entity'])) {
      $this->entityType = $key;
      return TRUE;
    }

    // Don't check for dependencies twice. They should already have been taken
    // into account for if it was traversed before.
    if (!isset($this->traversed[$this->entityType][$key])) {
      if (!empty($current['entity'])) {
        // Since the current entity is a UUID entity (with all properties and
        // field references as UUIDs) we need to re-load it as a standard entity
        // to make life easier for implementors of the following hooks. This
        // should have minor performance implications since the entity should
        // be cached at this point.
        $entity = reset(entity_load($this->entityType, array($current['entity_id'])));

        // Fetch dependencies and belongings to the entity being traversed.
        $this->dependencies[$key] = module_invoke_all('deploy_entity_dependencies', $entity, $this->entityType);
        $this->belongings[$key] = module_invoke_all('deploy_entity_belongings', $entity, $this->entityType);

        // Don't add dependencies that were already traversed.
        // TODO: Do the same for belongings?
        foreach ($this->dependencies[$key] as $entity_type => $dependencies) {
          foreach ($dependencies as $entity_id => $something) {
            if (isset($this->traversed[$entity_type][$entity_id])) {
              unset($this->dependencies[$key][$entity_type][$entity_id]);
            }
            else {
              // Make sure the 'dependencies' property holds the correct format.
              //$this->dependencies[$key][$entity_type][$entity_id] = TRUE;
              // Record this entity as a dependency to the tree.
              $this->relationships[$entity_type][$entity_id] = array(
                'type' => ENTITY_RELATIONSHIP_DEPENDENCY,
                'origin' => array(
                  'entity_type' => $this->entityType,
                  'entity_uuid' => reset(entity_get_uuid_by_id($this->entityType, array($key))),
                ),
              );
            }
          }
        }

        // Let other modules have their say.
        drupal_alter('deploy_entity_dependencies', $this->dependencies[$key], $entity, $this->entityType);
        drupal_alter('deploy_entity_belongings', $this->belongings[$key], $entity, $this->entityType);
      }

      // Now mark this current entity as traversed.
      $this->traversed[$this->entityType][$key] = TRUE;

      if (!empty($this->dependencies[$key])) {
        return TRUE;
      }
    }
    return FALSE;
  }

  /**
   * Returns an iterator for the current entry.
   *
   * @return DeployIterator
   */
  public function getChildren() {
    $key = $this->key();
    $current = $this->current();

    $entities = array();
    // Check if we have dependencies directly in the tree in the form of a
    // nested array.
    if (is_array($current) && !isset($current['entity'])) {
      $entities = $current;
    }

    if (!empty($this->dependencies[$key]) || !empty($this->belongings[$key])) {
      // TODO: We need to merge with $entities from above in some smart way.
      $entities = $this->dependencies[$key];
      // In an iterator, having children means that the current key itself
      // isn't a part of the entities. However, this isn't the case when doing
      // deployments. So we add the parent as a part of the entities.
      // And since children always should go first, we add the parent last.
      $entities[$this->entityType][$key] = TRUE;

      // TODO: Merge in $this->belongings[$key] to entities.

    }

    $iterator = new DeployIterator($entities, $this);
    $iterator->entityType = $this->entityType;
    return $iterator;
  }

  /**
   * Get the current value (entity).
   *
   * @todo Implement static caching to avoid multiple entity loads.
   *
   * @return array
   */
  public function current() {
    $current = current($this->entities);
    if (is_array($current)) {
      return $current;
    }
    // Sort out some keys.
    $key = $this->key();
    $uuid = reset(entity_get_uuid_by_id($this->entityType, array($key)));
    // Load the current entity with UUID.
    $entity = reset(entity_uuid_load($this->entityType, array($uuid)));

    // Let other modules have their say.
    drupal_alter('deploy_entity', $entity, $this->entityType);

    $data = array(
      'relationship' => $this->relationships[$this->entityType][$key],
      'entity_type' => $this->entityType,
      'entity_id' => $key,
      'entity_uuid' => $uuid,
      'entity' => $entity,
    );
    return $data;
  }

  /**
   * Returns the key of the current element.
   */
  public function key() {
    return key($this->entities);
  }

  /**
   * Moves the current position to the next element.
   */
  public function next() {
    return next($this->entities);
  }

  /**
   * Rewinds the Iterator to the first element.
   */
  public function rewind() {
    reset($this->entities);
  }

  /**
   * Checks if current position is valid.
   *
   * @todo
   *   Should we maybe check here if the entity has been traversed already?
   * @return boolean
   */
  public function valid() {
    $key = key($this->entities);
    return ($key !== NULL && $key !== FALSE);
  }
}
