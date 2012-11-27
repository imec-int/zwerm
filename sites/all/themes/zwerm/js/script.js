/**
 * @file
 * A JavaScript file for the theme.
 *
 * In order for this JavaScript to be loaded on pages, see the instructions in
 * the README.txt next to this file.
 */

// JavaScript should be made compatible with libraries other than jQuery by
// wrapping it with an "anonymous closure". See:
// - http://drupal.org/node/1446420
// - http://www.adequatelygood.com/2010/3/JavaScript-Module-Pattern-In-Depth
(function ($, Drupal, window, document, undefined) {

    //for hiding the labels in the login screen username and password fields
    //based on http://blog.stannard.net.au/2011/01/07/creating-a-form-with-labels-inside-text-fields-using-jquery/
    $(document).ready(function(){

        // Find each of our input fields
        var fields = $("form#user-login input");
        //alert(fields);

        // If a field gets focus then hide the label
        // (which is the previous element in the DOM).
        fields.focus(function(){
            $(this).prev().hide();
        });

        // If a field loses focus and nothing has
        // been entered in the field then show the label.
        fields.blur(function(){
            if (!this.value) {
                $(this).prev().show();
            }
        });

        jQuery(".wish").hide();
        jQuery(".list_header_wish").click(function()
        {
            jQuery(".wish").slideToggle(500);
        });

        jQuery(".event").hide();
        jQuery(".list_header_event").click(function()
        {
            jQuery(".event").slideToggle(500);
        });


    });

})(jQuery, Drupal, this, this.document);

function li_mousedown(url,element)
{
    element.className="selectedItem";
    document.location = url;
}



