<?php
/**
 * User: tanguycoenen
 * Date: 10/01/13
 * Time: 09:24
 */

    //print('accessing template file');
    $time_interval_elements = $variables ["interval_elements"];
    print('<div class="time_interval_label">'.t('Campaign end: ').'</div>');
    $formatted_time = ($time_interval_elements[0].' '.t("d").' '.
                       $time_interval_elements[1].' '.t("h").' '.
                       $time_interval_elements[2].' '.t("m").' '.
                       $time_interval_elements[3].' '.t("s"));
    print('<div class="time_interval">'.$formatted_time.'</div>');