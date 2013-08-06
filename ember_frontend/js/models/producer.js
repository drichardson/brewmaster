var Producer = DS.Model.extend({

  name: DS.attr('string'),

  location: DS.attr('string'),

  image: DS.attr('string'),

  established: DS.attr('date')

});

module.exports = Producer;

