<?php
/**
 * Created by JetBrains PhpStorm.
 * User: tanguycoenen
 * Date: 12/02/13
 * Time: 19:28
 * To change this template use File | Settings | File Templates.
 */
    print ('<div id="dialog" title="Het speel venster">');
    print ('Verzin een wens. Je krijgt er punten voor, maar je hebt ook maar een aantal "credits" waar je wensen mee kan aanmaken.
            Stel het aantal punten in die een speler van het andere team kan verdienen door je wens in vervulling te laten gaan. ');
    print('</div>');
    print('<div class="help"><a >?</a></div>');
    print drupal_render_children($form);

?>