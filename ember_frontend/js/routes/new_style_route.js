var style = require('../models/style');

var NewStyleRoute = Ember.Route.extend({

  renderTemplate: function() {
    this.render('style', {controller: 'new_style'});
  },

  model: function() {
    return style.createRecord();
  },

  exit: function() {
    var model = this.get('controller.model');
    if (!model.get('isSaving')) {
      model.deleteRecord();
    }
  }

});

module.exports = NewStyleRoute;

