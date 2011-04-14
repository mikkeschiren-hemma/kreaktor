// $Id: key_combo.js,v 1.1.2.4 2009/04/06 02:46:17 deciphered Exp $

/**
 * Key Combo visibility tweak.
 */
Drupal.admin.visibility.amd_key_combo = {
  init: function() {
    amdPosition = 0;

    $(document).keydown(function(e) {
      evt = (e) ? e : window.event;
      // Workaround for altKey bug in jQuery >= 1.2.5
      evt = evt.originalEvent ? evt.originalEvent : evt;

      visibilityCombo = eval(Drupal.settings.admin_menu.visibility.visibilityCombo.replace(/\+/g, '&&').replace(/([a-z]+)/g, "evt.$1Key").replace(/([0-9]+)/g, "evt.keyCode == $1"));
      positionCombo = eval(Drupal.settings.admin_menu.visibility.positionCombo.replace(/\+/g, '&&').replace(/([a-z]+)/g, "evt.$1Key").replace(/([0-9]+)/g, "evt.keyCode == $1"));


      // Toggle admin menu visibility.
      if (visibilityCombo && Drupal.settings.admin_menu.visibility.hidden) {
        Drupal.admin.visibility.show();
      }

      else if (visibilityCombo) {
        Drupal.admin.visibility.hide();
      }


      // Toggle admin menu position.
      if (positionCombo) {
        if (amdPosition == 0) {
          if (Drupal.settings.admin_menu.position_fixed == 1) {
            $('#admin-menu').css('position', '');
            window.scrollTo(0, 0);
          }
        }

        else {
          if (Drupal.settings.admin_menu.position_fixed == 1) {
            $('#admin-menu').css('position', 'fixed');
          }
        }

        amdPosition = amdPosition == 0 ? 1 : 0;
      }
    });
  },

  hide: function() {
    $('#admin-menu').hide();
  },

  show: function() {
    $('#admin-menu').show();
  }
}
