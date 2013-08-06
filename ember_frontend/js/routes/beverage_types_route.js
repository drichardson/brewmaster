var BeverageType = require('../models/beverage_type');

var BeverageTypeRoute = Ember.Route.extend({

  model: function() {
    return BeverageType.find();
  }

});

module.exports = BeverageTypeRoute;

