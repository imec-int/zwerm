<?php

/**
 * Class for deploying to a REST server using JSON
 */
class DeployServiceRestJSON extends DeployServiceRest {

  public function deploy(Traversable $iterator) {
    foreach ($iterator as $data) {
      $json_data = drupal_json_encode($data);
      $this->config['headers']['Content-Type'] = 'application/json';
      $response = $this->httpPut($data['entity']->uuid, $json_data, 'json');
      $context = array('response' => $response);
      module_invoke_all('deploy_entity_deployed', $this->plan, $data['entity_type'], $data['entity'], $context);
    }
  }
}
