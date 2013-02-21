<?php

//Sensetale Configuration
$token = '5c365c38-da07-413c-8861-c61253dc6f5c';
$sensetale_url = 'http://demo1.sensetale.com/server/';
$sensetale_push_url = 'http://demo1.sensetale.com/server/';

$birds = array();

//We run the update script twice per CRON run
//scoga_birds_update();
sleep(30);
//scoga_birds_update();

function scoga_birds_update() {
  error_log('Running SCOGA Birds update');
}

?>
