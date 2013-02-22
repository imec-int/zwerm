<?php

//Sensetale Configuration
$token = '5c365c38-da07-413c-8861-c61253dc6f5c';
$sensetale_url = 'http://demo1.sensetale.com/server/';
$sensetale_push_url = 'http://demo1-push.sensetale.com:8880/httpnonblocking/published/data/';
$sensetale_login_details = array("username" => "zwerm", "password" => "gent_zwermt",);
$scoga_login_details = array("username" => "admin", "password" => "y_iQtn+-%7_<",);

//$scoga_url = "http://localhost/smartip";
$scoga_url = "http://staging.zwermgent.be";
//$scoga_url = "http://www.zwermgent.be";

$birds = array(
  'Bird 6' => '012896008852888',
  'Bird 7' => '012896008856061',
  'Bird 8' => '012896008856533',
  'Bird 9' => '012896008851963',
  'Bird 10' => '012896008851765'
);

//We run the update script twice per CRON run
scoga_birds_update($birds);

//sleep(30);
//scoga_birds_update();

function scoga_birds_update($birds)
{
  global $scoga_url,$scoga_login_details,$sensetale_login_details,$sensetale_url;

  //Open SCOGA Session
  $response = call_api("POST", $scoga_url . "/rest/user/login", json_encode($scoga_login_details));
  $response_object = json_decode($response);
  $cookie = $response_object->session_name . '=' . $response_object->sessid;

  //Open Sensetale Session
  $response = call_api("GET", $sensetale_url . "login", $sensetale_login_details);

  //For every bird, check whether there are new values for the whistle sensor
  foreach($birds as $bird_name => $bird_id) {
    $whistle_events = scoga_sensetale_fetch_device_sensor_events($bird_id,'whistle');

    foreach ($whistle_events as $whistle_event_json){
      $whistle_event = json_decode($whistle_event_json);

      //Report whistling events to SCOGA services
      if ($whistle_event->whistle_tone) {
        scoga_sensetale_report_device_sensor_event($bird_name,'whistle',$whistle_event->whistle_tone,$whistle_event->epoch->sec,$cookie);
      }
    }

    //Disabling whistles until we have working co2 birds
    //For the birds with a whistle, check whether there is a new value for the CO2 sensor
    /*
    $co2_events = scoga_sensetale_fetch_device_sensor_events('012896008851765','co2');
    $co2_events_count = count($co2_events);
    if ($co2_events_count > 0) {
      $latest_co2_value = $co2_events[$co2_events_count-1];
    }
    */

  }

  //Session end
  $response = call_api("POST", $scoga_url . "/rest/user/logout", false, $cookie);
}

function scoga_sensetale_fetch_device_sensor_events($device_id, $sensor)
{
  global $sensetale_login_details,$sensetale_push_url;

  $sensor_responses = array();
  $sensor_response = true;

  while ($sensor_response) {
    $sensor_response = call_api("GET", $sensetale_push_url.$device_id.'/'.$sensor);
    if ($sensor_response) {
      $sensor_responses[] = $sensor_response;
    }
  }

  return $sensor_responses;
}

function scoga_sensetale_report_device_sensor_event($device_name, $sensor, $value, $value_timestamp, $cookie)
{
  global $scoga_url;
  $data = '{
"type":"scoga_sensor_device_event",
"title":"Device '.$device_name.' - '.$sensor.' event - '.$value_timestamp.'",
"language":"und",
"field_ref_sensor_device":{"und":{"0":{"target_id":"'.$device_name.'"}}},
"field_sensor_type":{"und":{"0":{"value":"'.$sensor.'"}}},
"field_sensor_val_timestamp":{"und":{"0":{"value":"'.$value_timestamp.'"}}},
"field_sensor_val":{"und":{"0":{"value":"'.$value.'"}}}
}';
  $response = call_api("POST", $scoga_url . "/rest/node", $data, $cookie);
}

function call_api($method, $url, $data = false, $cookie = false)
{
  $curl = curl_init();

  switch ($method) {
    case "POST":
      curl_setopt($curl, CURLOPT_POST, 1);
      if ($data)
        curl_setopt($curl, CURLOPT_POSTFIELDS, $data);
      break;
    case "PUT":
      curl_setopt($curl, CURLOPT_PUT, 1);
      break;
    default:
      if ($data)
        $url = sprintf("%s?%s", $url, http_build_query($data));
  }

  if ($cookie) {
    curl_setopt($curl, CURLOPT_COOKIE, $cookie);
  }

  curl_setopt($curl, CURLOPT_URL, $url);
  curl_setopt($curl, CURLOPT_HTTPHEADER, array('Content-Type: application/json'));
  curl_setopt($curl, CURLOPT_RETURNTRANSFER, 1);

  return curl_exec($curl);
}

?>
