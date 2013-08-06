var tap = require('../models/tap');

var NewTapRoute = Ember.Route.extend({

  renderTemplate: function() {
    this.render('edit_tap', {controller: 'new_tap'});
  },

  model: function() {
    return tap.createRecord();
  },

  exit: function() {
    var model = this.get('controller.model');
    if (!model.get('isSaving')) {
      model.deleteRecord();
    }
  }

});

module.exports = NewTapRoute;

