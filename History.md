
0.4.16 / 2012-05-14 
==================

  * see #64, fixed #61

0.4.15 / 2012-05-10 
==================

  * fixed #52, fixed #50

0.4.14 / 2012-05-09 
==================

  * added watchdog calls to all services

0.4.13 / 2012-05-08 
==================

  * moved scoga_aggregates feature to scoga package

0.4.12 / 2012-05-08 
==================

  * added scoga_aggregates feature

0.4.11 / 2012-05-08 
==================

  * added scoga_aggregated module

0.4.10 / 2012-05-07 
==================

  * fixed incorrect transaction retrieval by using last transaction id instead of begintime

0.4.9 / 2012-05-07 
==================

  * fixed issue with points not being transferred to team
  * fixed bug with empty user images

0.4.8 / 2012-05-06 
==================

  * check for empty user image

0.4.7 / 2012-05-06 
==================

  * hashed newly created users password

0.4.6 / 2012-05-06 
==================

  * added markdown feture
  * added contact feature
  * updated scoga_core_feature to v1.3
  * added module_filter module
  * added markdown module

0.4.5 / 2012-05-04 
==================

  * removed incorrect required picture field upon user registration

0.4.4 / 2012-05-04 
==================

  * added security review module

0.4.3 / 2012-05-03 
==================

  * added automatic username and password generation for user creation
  * Merge branch 'updatecore' into staging
  * updated core to v7.14

0.4.2 / 2012-05-03 
==================

  * updated core feature
  * added pages feature
  * added wishlist feature
  * added RFID feature
  * added core feature

0.4.1 / 2012-05-03 
==================

  * changed hardcoded credits tid references to UUID lookup
  * moved RFID specific constant to right module;
  * added changelog

0.4.0 / 2012-05-03 
==================

  * bunch of changes
  * removed userpoints_reset patch file
  * patched userpoints_reset module
  * created patch for fixing various userpoints_reset module bugs
  * added userpoints_contrib module
  * bunch of modifications
  * added current campaign selection in REST serverices
  * added reg_with_pic module
  * dotting the eye
  * further cron jobbing
  * rules and cron jobs
  * added current campaign as setting and rule handling for setting it
  * modified settings and added wrapper meths to them
  * replaced custom points methods with userpoints module methods
  * fixed code smells: added return NULL to inconsistently returning methods
  * reformatted
  * addded display suite module
  * added flag module
  * added rules callbacks file
  * fixed incorrect combo checkin creation
  * fixed incorrect time filtering of transactions
  * added scoga_get_campaignteam_entity_by_team_nid to scoga_core.api.capaign
  * added optional parameter handling for transaction_resource_index
  * added module_load api.team in api.campaign
  * renamed scoga_core.service.inc to scoga_core.services.inc
  * added scoga_rfid module
  * removed too generic scoga_resources module
  * removed unclear "scoga" module
  * removed custom features
  * removed patch file
  * patched includes/session.inc
  * restructured scoga_core
  * added user relationships module
  * added transaction REST service resource
  * updated scoga_visualizer to stable version
  * added scoga_core module
  * stable version of scoga_visualizer w/o team points
  * added incomplete scoga_visualizer module
  * updated gitignore
  * deleted obsolete files in uuid module (SQUASH NEEDED)
  * deleted references module
  * updated features module
  * updated rules module
  * added subform module
  * added privatemsg module
  * added oauth module
  * added notifications module
  * added messaging module
  * added efq_views module
  * added entityreference_view_widget
  * added entityreference module
  * added wysiwyg module
  * deleted ckeditor lib from ckeditor module
  * added ckeditor lib to libraries
  * updated uuid
  * updated ctools
  * updated views module
  * updated token module
  * updated field-permissions module
  * WIP on modules scoga and scoga_resource
  * updated ckeditor module
  * updated core to v7.12
  * WIP on scoga and scoga_resources.module
  * added modules context, userpoints, userpoints_nc
  * added register_card REST service resource
  * scoga_users_feature v1.2: updated permissions
  * modified user_field_team_reference widget type
  * added module uuid_features
  * changed const definitions
  * updated dependencies of SCOGA modules
  * added scoga_users_feature v1.0
  * addded scoga_presentation_feature v1.0
  * added scoga_model_feature v1.0
  * removed badly structured features
  * bug fixes in modules scoga and scoga_resources
  * removed scoga_settings module and added module scoga v1.0
  * added module scoga_settings v1.0
  * added module content_type_groups
  * added team node retrieval
  * scoga_rest_service v1.2: added register_reader=>create and removed reader_checkin=>index
  * scoga_resources v1.2: fixed #31 and some permission finetuning and general refactoring
  * scoga_kliek_team_feature non-versioned change: prettification of info file
  * scoga_kliek_user_feature v1.6: added user_registered field
  * module features updated to v1.0-beta6
  * scoga_checkin_feature v1.4: removed incorrectly included field
  * scoga_checkin_feature v1.3, see #11, see #12
  * module scoga_resource v1.0, fixed #7, fixed #12
  * modifying module scoga_resources, see #7, see #10, see#12
  * grouped scoga resources to one module: scoga_resource_checkin v1.0, removed automatic reader and user account creations, see #10
  * scoga_kliek_user_feature v1.5: fixed #11, added "assign kliek role" rule
  * scoga_checkin_feature v1.2: fixed #23, added valid field to checkin content type
  * scoga_kliek_user_feature v1.4: made separate user_score field
  * scoga_kliek_team_feature v1.4: made sepaarte team_score field
  * scoga_checkin_feature v1.1: added score field
  * module scoga_kliek_team_feature v1.3: added score multiplier field and descriptions
  * feature scoga_kliek_user_feature v1.3: added "unassigned" as default team
  * updated module references to 2.x-dev to solve bug: http://drupal.org/node/1145766
  * feature scoga_kliek_team_feature v1.2: added "unassigned" team node
  * added module node_export
  * fixed #25, updated feature scoga_kliek_user_feature to v1.2, made team and score fields readonly for user profiles
  * fixed #27, updated feature scoga_kliek_team_feature to v1.1, score field made read-only
  * added module field_permissions, fixed #25
  * fixed #24, added team node ref to user
  * updated scoga_resource_checkin modules dependencies to reflect newly grouped features
  * added feature scoga_rfid_reader_feature v1.0
  * added feature scoga_kliek_user_feature v1.0
  * added feature scoga_kliek_team_feature v1.0
  * added scoga_checkin_feature v1.0
  * removed obsolete features
  * fixed #8, added scoga_team_content_type_feature v1.0
  * feature scoga_checkins_view v1.3: added to menu and changed access
  * module scoga_resource_checkin v1.1.2: fixed incorrect checkin time formatting
  * module scoga_resource_checkin v1.1.1: formatted checkin time and added comments
  * added checkin time field to feature scoga_checkins_view, bumped to v1.2
