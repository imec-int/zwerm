<?php
/**
 * User: tanguycoenen
 * Date: 10/01/13
 * Time: 09:24
 */

    //print('accessing template file');
    $time_interval_elements = $variables ["interval_elements"];
    print(t('Campaigns ends in: '));
    $formatted_time = ($time_interval_elements[0].' '.t("days").' '.
                       $time_interval_elements[1].' '.t("hours").' '.
                       $time_interval_elements[2].' '.t("minutes").' '.
                       $time_interval_elements[3].' '.t("seconds"));
    print($formatted_time);