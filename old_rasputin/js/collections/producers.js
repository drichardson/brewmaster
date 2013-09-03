/*global Backbone */
var app = app || {};

(function () {
	'use strict';

	// Producers Collection
	// ---------------

	app.Producers = Backbone.Collection.extend({
		// Reference to this collection's model.
		model: app.Producer,

		localStorage: new Backbone.LocalStorage('producers-backbone')

	});

	// Create our global collection of **Producers**.
	app.producers = new app.Producers();
})();
