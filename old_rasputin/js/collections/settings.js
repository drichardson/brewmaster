/*global Backbone */
var app = app || {};

(function () {
	'use strict';

	// Tap Entry Collection
	// ---------------

	var Settings = Backbone.Collection.extend({
		// Reference to this collection's model.
		model: app.Settings,

		localStorage: new Backbone.LocalStorage('settings-backbone')

	});

	// Create our global collection of **Settings* (there should only be one).
	app.settings = new Settings();
})();
