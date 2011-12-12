<?php

/**
 * Processor class using the Batch API
 */
class DeployProcessorBatch extends DeployProcessorMemory {

  public function process($endpoint_name) {
    if ($endpoint = deploy_endpoint_load($endpoint_name)) {
      $operations = array();

      foreach ($this->aggregator as $data) {
        // Since we are queuing for unknown time, we only want to queue
        // originators. Their dependencies will be figured out anyhow when
        // processing later on.
        if ($data['relationship']['type'] == ENTITY_RELATIONSHIP_ORIGIN) {
          $item = array(
            'plan_name' => $this->aggregator->plan->name,
            'entity_type' => $data['entity_type'],
            'entity_id' => $data['entity_id'],
            'endpoint_name' => $endpoint_name,
          );
          $operations[] = array('deploy_queue_process_item', array($item));
        }
      }
      $batch = array(
        'title' => t('Deploying %plan to %endpoint', array('%plan' => $this->aggregator->plan->title, '%endpoint' => $endpoint->title)),
        'operations' => $operations,
      );
      batch_set($batch);
    }
  }

  public function cleanup() {
    drupal_set_message(t('%plan has been deployed to its endpoints', array('%plan' => $this->aggregator->plan->title)));
    batch_process('admin/structure/deploy');
  }

  public function configForm(&$form_state) {
    // We have no settings for this processor.
    return array();
  }
}
