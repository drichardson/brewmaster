/*global Backbone */
var app = app || {};

(function () {
	'use strict';

	// Producers Collection
	// ---------------

	var Producers = Backbone.Collection.extend({
		// Reference to this collection's model.
		model: app.Producers,

		localStorage: new Backbone.LocalStorage('producers-backbone')

	});

	// Create our global collection of **Producers**.
	app.producers = new Producers();
})();
