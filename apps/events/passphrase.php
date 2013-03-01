<?php
    require_once( 'includes/shared.inc' );
?>
<body>
<div data-role="page" id="page-passphrase">

  <div data-role="header">
        <h1>Zwerm</h1>
  </div>
  <div data-role="content">
      <form action="index.php" method="post">
          <div id="div-nid" data-role="fieldcontain">
            <label for="field-nid">Event ID</label>
            <input type="text" name="event_nid" id="field-nid" value="<?= session_has_key( KEY_EVENT_NID ) ? get_from_session( KEY_EVENT_NID ) : ''; ?>"  />
          </div>
          <div id="div-passphrase" data-role="fieldcontain">
            <label for="field-passphrase">Toegangscode</label>
            <input type="password" name="passphrase" id="field-passphrase" value="<?= session_has_key( KEY_PASSPHRASE ) ? get_from_session( KEY_PASSPHRASE ) : ''; ?>"  />
          </div>
          <div id="div-passphrase-toggle" data-role="fieldcontain">
            <label for="field-passphrase-toggle">Toon toegangscode</label>
            <select id="field-passphrase-toggle" name="field-passphrase-toggle" data-role="slider" >
                <option value="off">Uit</option>
                <option value="on">Aan</option>
            </select>
          </div>
          <div>
              <input type="submit" value="Bewaren" data-icon="edit"/>
          </div>
      </form>
  </div>
</div>
