/*global Backbone */
var app = app || {};

(function () {
	'use strict';

	// Styles Collection
	// ---------------

	app.BeverageStyles = Backbone.Collection.extend({
		// Reference to this collection's model.
		model: app.BeverageStyle,

		localStorage: new Backbone.LocalStorage('styles-backbone')

	});

	// Create our global collection of **Beverage Styles**.
	app.beverageStyles = new app.BeverageStyles();
})();
