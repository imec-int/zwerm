ABOUT ZWERM
-----------
The ZWERM server can be used to create gamified web-based systems. For now, the main emphasis is on the consolidation and activation of social capital. However, other purposes would be possible. More information on how ZWERM has been applied can be found at zwermgent.be
This code allows you to set up the server on which:  

* Teams can be defined.
* Campaigns can be defined.
* Assignments types can be defined and concrete assignments can be filled out based on these assignment types.
* Scores can be incremented and read by third party code by means of a REST API.

INSTALLING
----------
The ZWERM server is built in Drupal 7. 
To install it, you need two things: a DB and the code. 
Both are available in this repo. 
To get things going, you need to : 

1. Import zwerm_release.sql in the DB of your choice
2. Configure DB access at /sites/default/settings.php
3. Do all the things you need to do to het a Drupal site to run

FUTURE DEVELOPMENT
------------------
* Create a Drupal installation profile for easier installation





