/*global Backbone */
var app = app || {};

(function () {
	'use strict';

	// Todo Router
	// ----------
	var BrewmasterRouter = Backbone.Router.extend({
		routes: {
			"beverages" : "listAllBeverages",
			"beverage/new" : "newBeverage",
			"beverage/:id" : "getBeverage"
			},
			
			listAllBeverages: function() {
				console.log("List all beverages");
			},
			
			getBeverage: function(id) {
				console.log("Getting beverage for id " + id);
			},
			
			newBeverage: function() {
				var newModel = new app.Beverage({
					title: "New Beverage"
				});
				app.current_beverage = newModel;
				console.log("Create new beverage");
			}
	});

	app.BrewmasterRouter = new BrewmasterRouter();
	Backbone.history.start();
})();
