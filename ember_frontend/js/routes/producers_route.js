var Producer = require('../models/producer');

var ProducerRoute = Ember.Route.extend({

  model: function() {
    return Producer.find();
  }

});

module.exports = ProducerRoute;

