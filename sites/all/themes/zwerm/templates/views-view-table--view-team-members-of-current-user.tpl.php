<?php
/**
 * @file views-view-table.tpl.php
 * Template to display a view as a table.
 *
 * - $title : The title of this group of rows.  May be empty.
 * - $header: An array of header labels keyed by field id.
 * - $header_classes: An array of header classes keyed by field id.
 * - $fields: An array of CSS IDs to use for each field id.
 * - $classes: A class or classes to apply to the table, based on settings.
 * - $row_classes: An array of classes to apply to each row, indexed by row
 *   number. This matches the index in $rows.
 * - $rows: An array of row items. Each row is an array of content.
 *   $rows are keyed by row number, fields within rows are keyed by field ID.
 * - $field_classes: An array of classes to apply to each field, indexed by
 *   field id, then row number. This matches the index in $rows.
 * @ingroup views_templates
 */
?>
<?php
    //This variable was set in the views_php filter in the leaderboard view display
    $userLeaderboardPosition = variable_get('userLeaderboardPosition');
?>
<table <?php if ($classes) { print 'class="'. $classes . '" '; } ?>
    <?php print $attributes; ?>>
    <?php if (!empty($title)) : ?>
        <caption><?php print $title; ?></caption>
    <?php endif; ?>
    <?php if (!empty($header)) : ?>
    <?php endif; ?>
    <tbody>
    <?php
        $i=0;
        foreach ($rows as $row_count => $row): ?>
            <?php //dsm($row['name']); ?>
            <?php $playerRank = $row['php']; ?>
            <?php if ($playerRank == $userLeaderboardPosition-2): ?>
                <tr class="leaderboard_separator <?php print implode(' ', $row_classes[$row_count]); ?>">
                   <td colspan="3">...</td>
                </tr>
            <?php else: ?>
                <?php $loggedInUserClass = ''; ?>
                <?php if ($playerRank == $userLeaderboardPosition+1): ?>
                    <?php $loggedInUserClass = 'loggedInUser';?>    <!-- sets class when loggedIn user is being displayed-->
                <?php endif; ?>
                <tr onmousedown='li_mousedown(<?php print("\"user/".$row['uid']."\"")?>,this);'  class="<?php print (implode(' ', $row_classes[$row_count]). ' team_'.$row['field_user_team'] .' '.$loggedInUserClass); ?>">
                    <?php if ($playerRank == $userLeaderboardPosition+1): ?>
                    <?php endif; ?>
                    <!-- print the different elements in the row-->
                    <?php foreach ($row as $field => $content): ?>
                        <td <?php if ($field_classes[$field][$row_count])
                        {
                            print 'class="'. $field_classes[$field][$row_count] .' '.$loggedInUserClass.'" ';
                        } ?>
                            <?php print drupal_attributes($field_attributes[$field][$row_count]); ?>>
                            <?php print $content; ?>
                        </td>
                    <?php endforeach; ?>
                </tr>
            <?php endif; ?>
            <?php $i = $i+1; ?>
        <?php endforeach; ?>
    </tbody>
</table>