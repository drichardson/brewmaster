/*global Backbone */
var app = app || {};

(function () {
	'use strict';

	// Tap Entry Model
	// ----------
	app.TapEntry = Backbone.RelationalModel.extend({
		
		defaults: {
			name: '',
			active: NO,
			date_added: new Date(0),
			date_removed: new Date(0)
		}
	});
})();
