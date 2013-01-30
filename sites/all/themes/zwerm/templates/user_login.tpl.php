<?php
/**
 * Created by JetBrains PhpStorm.
 * User: tanguycoenen
 * Date: 29/11/12
 * Time: 11:14
 * To change this template use File | Settings | File Templates.
 */
?>
<div class="my-form-wrapper">
    <?php print drupal_render_children($variables['form']); ?>
</div>
<div class="get-new-password">
    <a href="user/password">Password vergeten</a>
</div>