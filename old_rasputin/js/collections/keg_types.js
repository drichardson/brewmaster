/*global Backbone */
var app = app || {};

(function () {
	'use strict';

	// Keg Type Collection
	// ---------------

	var KegTypes = Backbone.Collection.extend({
		// Reference to this collection's model.
		model: app.KegType,

		localStorage: new Backbone.LocalStorage('keg-types-backbone')

	});

	// Create our global collection of **Keg Types**.
	app.kegTypes = new KegTypes();
})();
