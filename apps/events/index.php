<?php
/**
 * Camille Reynders, http://www.creynders.be
 * 27/02/13 - 15:41
 */
    require_once( 'includes/shared.inc' );

    $hash = hash( 'MD5', microtime() . SALT );

    if( ! session_has_key( KEY_PASSPHRASE ) ){
        store_in_session( KEY_PASSPHRASE, '' );
    }
    if( ! session_has_key( KEY_EVENT_NID ) ){
        store_in_session( KEY_EVENT_NID, '' );
    }

    if( $_POST ){
        transfer_from_post_to_session( KEY_PASSPHRASE );
        transfer_from_post_to_session( KEY_EVENT_NID );
    }

    function get_hash(){
        global $hash;
        return $hash;
    }

    function get_signature(){
        $unenc_signature = get_hash() . get_from_session( KEY_EVENT_NID) . SALT;
        return hash( 'sha256', $unenc_signature );
    }

    function get_passphrase(){
        $unenc_passphrase = get_from_session( KEY_PASSPHRASE ) . SALT . get_hash();
        return hash( 'sha256', $unenc_passphrase );
    }
?>
    <!DOCTYPE html>
    <html>
    <head>
        <meta charset="utf-8">
        <meta name="viewport" content="width=device-width, initial-scale=1">
        <title>Zwerm Activiteit</title>
        <link type="text/css" rel="stylesheet" href="css/styles.css" media="all" />
        <link rel="stylesheet" href="css/jquery.mobile-1.3.0.min.css">
        <script src="js/jquery-1.9.1.min.js"></script>
        <script src="js/jquery.mobile-1.3.0.min.js"></script>
        <script src="js/script.js"></script>
    </head>
    <body>
    <div data-role="page" id="page-front">

      <div data-role="header">
          <a href="passphrase.php" data-rel="dialog" data-icon="gear">Pas toegangscode aan</a>
            <h1>Zwerm</h1>
      </div>
      <div data-role="content">
          <div>
              <?php var_dump( $_SESSION ); ?>
          </div>
          <div id="div-warnings">
              <H4 id="result">&nbsp;</H4>
              <H4 class="<?= ( session_has_key( KEY_EVENT_NID ) ) ? 'hidden' : ''; ?>">Opgelet: Je hebt nog geen Event ID opgegeven.</H4>
                <H4  class="<?= ( session_has_key( KEY_PASSPHRASE ) ) ? 'hidden' : ''; ?>">Opgelet: Je hebt nog geen toegangscode opgegeven.</H4>
          </div>
          <div id="div-cardid-form">
              <input id="field-token" type="hidden" name="token" value="<?= session_name() . '=' . session_id(); ?>"
              <input id="field-passphrase" type="hidden" name="p" value="<?= get_passphrase(); ?>" />
              <input id="field-event-nid" type="hidden" name="eventNID" value="<?= get_from_session( KEY_EVENT_NID ); ?>" />
              <input id="field-h" type="hidden" name="h" value="<?= get_hash() ?>" />
              <input id="field-s" type="hidden" name="s" value="<?= get_signature() ?>" />
              <div id="div-card_id" data-role="fieldcontain">
                <label for="field-card-id">Kaart nummer</label>
                <input type="text" name="cardID" id="field-card-id" value="" data-clear-btn="true" onblur="showFocusWarning();" onfocus="hideFocusWarning();" />
              </div>
              <!--
              <a href="#" data-role="button" data-icon="forward" onclick="submitCardIDForm(); return false" rel="external">Verstuur</a>
              -->
              <div>
                  <input id="submit-button" type="button" value="Verstuur" data-icon="forward" onclick="submitEventsRequest(); return false;"/>
              </div>
          </div>
      </div>
    </div>
    </body>
    </html>