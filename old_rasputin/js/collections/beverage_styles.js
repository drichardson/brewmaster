/*global Backbone */
var app = app || {};

(function () {
	'use strict';

	// Styles Collection
	// ---------------

	var BeverageStyles = Backbone.Collection.extend({
		// Reference to this collection's model.
		model: app.BeverageStyles,

		localStorage: new Backbone.LocalStorage('styles-backbone')

	});

	// Create our global collection of **Beverage Styles**.
	app.beverageStyles = new BeverageStyles();
})();
