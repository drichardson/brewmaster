var beverage = require('../models/beverage');

var NewBeverageRoute = Ember.Route.extend({

  renderTemplate: function() {
    this.render('beverage', {controller: 'new_beverage'});
  },

  model: function() {
    return beverage.createRecord();
  },

  exit: function() {
    var model = this.get('controller.model');
    if (!model.get('isSaving')) {
      model.deleteRecord();
    }
  }

});

module.exports = NewBeverageRoute;

