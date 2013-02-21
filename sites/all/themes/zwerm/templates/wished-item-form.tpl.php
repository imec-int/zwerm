<?php
/**
 * Created by JetBrains PhpStorm.
 * User: tanguycoenen
 * Date: 12/02/13
 * Time: 19:28
 * To change this template use File | Settings | File Templates.
 */
    print ('<div id="dialog" title="Het speel venster">');
    print ('Babysit gezocht? Klusjesman gezocht? Carpoolen? Helpen verhuizen? Bijles? … Schrijf het hier neer en verdien extra punten! Het ingaan op zoekertjes levert natuurlijk ook extra punten op! Hoeveel? Dat kan je onderaan zelf instellen. ');
    print('</div>');
    print('<div class="help"><a >?</a></div>');
    print drupal_render_children($form);

?>