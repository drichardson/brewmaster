var Style = require('../models/style');

var StyleRoute = Ember.Route.extend({

  model: function() {
    return Style.find();
  }

});

module.exports = StyleRoute;

