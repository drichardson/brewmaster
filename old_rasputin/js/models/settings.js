/*global Backbone */
var app = app || {};

(function () {
	'use strict';

	// Settings Model
	// ----------
	app.Settings = Backbone.Model.extend({
		defaults: {
			tapCount: 4,
			target_temp: 58
		}		
	});
})();
