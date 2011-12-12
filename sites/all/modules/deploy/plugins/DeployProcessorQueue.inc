<?php

/**
 * Processor class using the Batch API
 */
class DeployProcessorQueue extends DeployProcessorMemory {

  public function process($endpoint_name) {
    if ($endpoint = deploy_endpoint_load($endpoint_name)) {
      $queue = DrupalQueue::get('deploy_queue');

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
          $queue->createItem($item);
        }
      }
      drupal_set_message(t('%plan has been queued for deployment to %endpoint.', array('%plan' => $this->aggregator->plan->title, '%endpoint' => $endpoint->title)));
    }
  }

  public function configForm(&$form_state) {
    // We have no settings for this processor.
    return array();
  }
}
