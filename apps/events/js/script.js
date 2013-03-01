/**
 * Camille Reynders, http://www.creynders.be
 * 28/02/13 - 10:57
 */

$.mobile.page.prototype.options.domCache = false;


function submitCardIDForm() {
    $('#form-card-id').submit(function() {
        alert( 'oho' );
        alert($(this).serialize());
        return false;
    });
}


/**
 * Camille Reynders, http://www.creynders.be
 * 28/02/13 - 12:17
 */

//$('#Switch2').val('on').slider("refresh");

/*
$(function(){
    $(".showpassword").each(function(index,input) {
        var $input = $(input);
        $('<label class="showpasswordlabel"/>').append(
            $("<input type='checkbox' class='showpasswordcheckbox' />").click(function() {
                var change = $(this).is(":checked") ? "text" : "password";
                var rep = $("<input type='" + change + "' />")
                    .attr("id", $input.attr("id"))
                    .attr("name", $input.attr("name"))
                    .attr('class', $input.attr('class'))
                    .val($input.val())
                    .insertBefore($input);
                $input.remove();
                $input = rep;
             })
        ).append($("<span/>").text("Show password")).insertAfter($input);
    });
});
*/

function togglePasswordVisibility(){
    var passphraseField = $( '#field-passphrase' );
    var toggleField = $( '#field-passphrase-toggle' );
    var fieldType = ( toggleField.val() == 'on' ) ? "text" : "password";
    var newField = $("<input type='" + fieldType + "' />")
                        .attr("id", passphraseField.attr("id"))
                        .attr("name", passphraseField.attr("name"))
                        .attr('class', passphraseField.attr('class'))
                        .val(passphraseField.val())
                        .insertBefore(passphraseField);
    passphraseField.remove();
}

function showFocusWarning() {
    $( '#warning-cant-scan' ).show();
}

function hideFocusWarning(){
    $( '#warning-cant-scan' ).hide();
}

function setFocusOnCardIDField(){
    //hack, hack, hacking crappy code
    //see: http://stackoverflow.com/questions/7179098/focus-problem-with-jquery-mobile
    setTimeout(function(){
        $( '#field-card-id' ).focus();
    },0);
}

function submitEventsRequest(  ){

    var uri = '/rest/scoga_events'; //'/rest/scoga_events';

    var data = {
   		cardID : $( '#field-card-id' ).val(),
   		s : $( '#field-s' ).val(),
        h : $( '#field-h' ).val(),
        eventNID : $( '#field-event-nid' ).val(),
        p : $( '#field-passphrase' ).val()
   	}

    $( '#field-card-id' ).val( '' );

   	//send POST urlencoded, receive JSON
   	var params = {
           //context : this,
   		type : "POST",
   		url : uri,
   		data : data,
   		contentType : 'application/x-www-form-urlencoded',
   		dataType : 'json',
       beforeSend: function() {
           $( '#result' ).html( '<h4>&nbsp;</h4>' );
           $("#submit-button").button("disable");
           $.mobile.loading( 'show' );
           //$.mobile.changePage('#page-loading' );
       },
       complete: function() {
           $.mobile.changePage('#page-blank', { transition : '' } );
           $.mobile.loading( 'hide' );
           $("#submit-button").button("enable");
       }
   	}
       //console.log( params );
   	var jqxhr = $.ajax( params )
           .done(function(data, textStatus, jqXHR){
                //setFocusOnCardIDField();
                //alert( data.message );

                $( '#result' ).html( '<h4>' + data.message + '</h4>' );
           })
           .fail(function(jqXHR, textStatus, errorThrown){
                //setFocusOnCardIDField();
                $( '#result' ).html( '<h4>' + data.message + '</h4>' );
           });
       ;
}

$(document).on('pageshow', '#page-front',  function(){
    setFocusOnCardIDField();
});
$(document).on('pageshow', '#page-passphrase',  function(){
    $( "#field-passphrase-toggle" ).on( "slidestop", togglePasswordVisibility );
});
