/* $Id: README.txt,v 1.1 2009/12/08 03:22:14 sun Exp $ */

-- SUMMARY --

Form module closes a gap in Drupal's module framework.  While we have CCK
and Views for contents, Blocks and Panels for regions, and similarly
configurable solutions for other things, we haven't had a module to configure
and control forms.

The primary purpose of this module was to have a "Form Spy"-alike helper that
aids in retrieving and selecting form ids for modules like Journal [1],
#translatable [2], Fivestar [3], Compact forms [4], aso.  However, it quickly
turned out that Form module is basically able to be a general purpose helper
for most modules that implement hook_form_alter().

For this reason, Form module does (almost) nothing on its own.  It allows
other modules to implement hook_form_info() to allow administrative users
to define settings for any FAPI-based form in Drupal.  Form module loads
those settings and returns the form values back to the hook_form_info()
implementation (for now, that is).  Modules can use this valuable information to
alter/don't alter a form, or for whatever they like.

Form module is very lightweight.  Admittedly, the included JavaScript needs
some love, however, it works for now.


For a full description visit the project page:
  http://drupal.org/project/form
Bug reports, feature suggestions and latest developments:
  http://drupal.org/project/issues/form


[1] http://drupal.org/project/journal
[2] http://drupal.org/project/translatable
[3] http://drupal.org/project/fivestar
[4] http://drupal.org/project/compact_forms


-- INSTALLATION --

* Install as usual, see http://drupal.org/node/70151 for further information.


-- CONFIGURATION --

* Configure user permissions in Administer >> Permissions >> Form.

* There are no module settings yet.


-- CONTACT --

Current maintainers:
* Daniel F. Kudwien (sun) <http://drupal.org/user/54136>

This project has been sponsored by:
* UNLEASHED MIND
  Specialized in consulting and planning of Drupal powered sites, UNLEASHED
  MIND offers installation, development, theming, customization, and hosting
  to get you started. Visit http://www.unleashedmind.com for more information.

