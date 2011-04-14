// $Id$

/**
 * Initialize selected visibility tweak.
 */
Drupal.admin.behaviors.visibility = function() {
  // Initialize defined visibility tweak
  jQuery.each(Drupal.admin.visibility, function(tweak) {
    if (tweak == Drupal.settings.admin_menu.visibility.behavior) {
      Drupal.settings.admin_menu.visibility.behavior = this;
      this.init();

      // Set initial visibility status
      if (Drupal.settings.admin_menu.visibility.hidden == 1) {
        this.hide();
      }

      return false;
    }
    return true;
  });
}

/**
 * Visibility tweak JS API.
 *
 * hide():
 *   Set visibility status in $_SESSION.
 *   Set visibility status in JavaScript.
 *   Return to visibility tweaks 'hide()' function.
 *
 * show():
 *   Set visibility status in $_SESSION.
 *   Set visibility status in JavaScript.
 *   Return to visibility tweaks 'show()' function.
 */
Drupal.admin.visibility = {
  hide: function() {
    $.getJSON(Drupal.settings.basePath + "admin_menu_dropdown/js/visibility/hide");
    Drupal.settings.admin_menu.visibility.hidden = 1;
    console.log(Drupal.settings.admin_menu.visibility.hidden);
    Drupal.settings.admin_menu.visibility.behavior.hide();
  },

  show: function() {
    $.getJSON(Drupal.settings.basePath + "admin_menu_dropdown/js/visibility/show");
    Drupal.settings.admin_menu.visibility.hidden = 0;
    Drupal.settings.admin_menu.visibility.behavior.show();
  }
}