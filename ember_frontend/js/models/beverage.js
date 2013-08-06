var Beverage = DS.Model.extend({

  name: DS.attr('string'),

  image: DS.attr('string'),

  abv: DS.attr('number'),

  ibu: DS.attr('number')

});

module.exports = Beverage;

