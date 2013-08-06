var beverage_type = require('../models/beverage_type');

var NewBeverageTypeRoute = Ember.Route.extend({

  renderTemplate: function() {
    this.render('beverage_type', {controller: 'new_beverage_type'});
  },

  model: function() {
    return beverage_type.createRecord();
  },

  exit: function() {
    var model = this.get('controller.model');
    if (!model.get('isSaving')) {
      model.deleteRecord();
    }
  }

});

module.exports = NewBeverageTypeRoute;

