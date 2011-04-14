// $Id: README.txt,v 1.1.2.1 2009/07/21 15:48:18 jrockowitz Exp $

======================================================================

CONTENTS
--------

 * Overview
 * Requirements
 * Installation
 * Theming Information
 * Technical Information
 * More Information


OVERVIEW
--------

The 'Fieldset helper' module saves the state of a collapsible fieldset
in a browser cookie. Being able to save the state of a collapsible fieldset
improves the usability of a website's forms and documents because users
are able to better customize what information is being presented to them.

For site administrator on the 'Modules' page, this module will save the
state of all the collasible fieldsets and add 'expand all' and 'collapse all'
links to the top page. These two tweaks make it easier for administrators to
enable and disable their modules.


REQUIREMENTS
------------

Optional modules

 - CCK fieldgroup - CCK's fieldset widget's collapsible state will also
   be stored by the 'Fieldset helper' module.


INSTALLATION
------------

1. Copy/upload the fieldset_helper.module to the sites/all/modules directory
   of your Drupal installation.

2. Enable the fieldset_helper.module in Drupal (administer -> modules).

3. Set the 'administer fieldset state' and 'save fieldset state' user
   permissions for the 'Fieldset helper' module.


THEMING INFORMATION
-------------------

To be able to save the collapsible fieldset states the 'Fieldset helper' module
attempts to declare phptemplate_fieldset(), phptemplate_fieldgroup_fieldset(),
and phptemplate_system_modules() functions (in fieldset_helper.theme.inc)
that over-ride the existing theme functions.

If your theme or another module declares these theme functions, you can still
integrate the 'Fieldset helper' module's theme altering output functionality
by updating your code to call the fieldset_helper_alter_theme_system_modules($output)
and fieldset_helper_alter_theme_fieldset($element) functions.

Please review the API documention for more information.


TECHNICAL INFORMATION
---------------------

The cookie that stores the fieldset states expires at the end of each browser session.
(aka, the user closes their browser)

This is done for two reasons

1. Eventhough the cookie is storing a 'limited' amount of data, it can still be
   considered potentially large by most cookie usage standards.

2. An anonymous user can also save the state of any collapsible fieldset. In a
   shared computer environment any 'personalization' should always expire when the
   user closes the browser.


MORE INFORMATION
----------------

 - Homepage
	 http://thebigbluehouse.com

 - Download
   http://drupal.org/project/fieldset_helper

 - Documentation:
   http://drupal.bigbluedrop.com/api/file/contrib-jrockowitz/fieldset_helper/fieldset_helper.module/6

 - Changelog:
   http://cvs.drupal.org/viewvc.py/drupal/contributions/modules/fieldset_helper/CHANGELOG.txt?view=markup&pathrev=DRUPAL-6--1

 - CVS tree:
	 http://cvs.drupal.org/viewvc.py/drupal/contributions/modules/fieldset_helper/?pathrev=DRUPAL-6--1

 - Demo site:
   http://drupal.bigbluedrop.com/admin/settings/fieldset_helper/testL
 
 - Screencast
   http://www.screentoaster.com/watch/stUE1SRkBIR1pZSFpdW1xeU1FX/drupal_fieldset_helper_module

AUTHOR/MAINTAINER
-----------------

 - Jacob Rockowitz
   http://drupal.org/user/371407
