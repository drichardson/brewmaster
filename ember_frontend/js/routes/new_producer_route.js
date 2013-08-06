var producer = require('../models/producer');

var NewProducerRoute = Ember.Route.extend({

  renderTemplate: function() {
    this.render('producer', {controller: 'new_producer'});
  },

  model: function() {
    return producer.createRecord();
  },

  exit: function() {
    var model = this.get('controller.model');
    if (!model.get('isSaving')) {
      model.deleteRecord();
    }
  }

});

module.exports = NewProducerRoute;

