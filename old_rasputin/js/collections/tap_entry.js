/*global Backbone */
var app = app || {};

(function () {
	'use strict';

	// Tap Entry Collection
	// ---------------
	app.TapEntries = Backbone.Collection.extend({
		// Reference to this collection's model.
		model: app.TapEntry,

		localStorage: new Backbone.LocalStorage('tap-entries-backbone')

	});

	// Create our global collection of **Tap Entries**.
	app.tapEntries = new app.TapEntries();
})();
