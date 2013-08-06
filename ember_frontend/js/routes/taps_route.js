var Tap = require('../models/tap');

var TapRoute = Ember.Route.extend({

  model: function() {
    return Tap.find();
  }

});

module.exports = TapRoute;

