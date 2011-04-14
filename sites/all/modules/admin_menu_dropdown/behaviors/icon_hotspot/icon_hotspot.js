// $Id: icon_hotspot.js,v 1.1.2.3 2009/04/06 02:46:16 deciphered Exp $

/**
 * Icon Hotspot visibility tweak.
 */
Drupal.admin.visibility.amd_icon_hotspot = {
  init: function() {
    $('#admin-menu').css({height: '21px'});
    $('#admin-menu ul:first li.admin-menu-icon:first a:first')
      .css({padding: '1px 4px 4px'})
      .attr({href: '#', title: 'Click here to toggle administration menu visibility!'})
      .click(function() {
        if (Drupal.settings.admin_menu.visibility.hidden) {
          Drupal.admin.visibility.show();
        }
        else {
          Drupal.admin.visibility.hide();
        }

        return false;
      });
  },

  hide: function() {
    $('#admin-menu')
      .width('24px').css({overflow: 'hidden'})
      .children('ul:first').children('li:gt(0)').hide();
  },

  show: function() {
    $('#admin-menu')
      .width('100%').css({overflow: 'visible'})
      .children('ul:first').children('li:gt(0)').show();
  }
}
