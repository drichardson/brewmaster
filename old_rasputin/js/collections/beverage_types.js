/*global Backbone */
var app = app || {};

(function () {
	'use strict';

	// Beverage Type Collection
	// ---------------
	var BeverageTypes = Backbone.Collection.extend({
		// Reference to this collection's model.
		model: app.BeverageType,

		localStorage: new Backbone.LocalStorage('beverage-types-backbone')

	});

	// Create our global collection of **Beverage Types**.
	app.beverageTypes = new BeverageTypes();
})();
