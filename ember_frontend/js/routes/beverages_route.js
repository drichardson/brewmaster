var Beverage = require('../models/beverage');

var BeverageRoute = Ember.Route.extend({

  model: function() {
    return Beverage.find();
  },

	renderTemplate: function() {
		// this._super();
		// 
		var producersController = this.controllerFor('producers');
		var producerController = this.controllerFor('producer');
		
		this.render('beverages');
		this.render('producers', {
			into: 'beverages',
			outlet: 'producers', 
			controller: producersController 
			});
		// this.render('beverages', {
		//       outlet: 'beverages',
		//       // controller: beveragesController
		//     });
	},

  setupController: function(controller, beverage) {
    this._super(controller, beverage);
		// this.controllerFor('producers')
    // this.controllerFor('posts').set('currentPost', post);
  }

});

module.exports = BeverageRoute;

