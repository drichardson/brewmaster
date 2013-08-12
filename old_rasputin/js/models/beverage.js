/*global Backbone */
var app = app || {};

(function () {
	'use strict';

	// Beverage Model
	// ----------

	app.Beverage = Backbone.Model.extend({
		// Default attributes for the beverage
		defaults: {
			name: '',
			brewery: '',
			abv: '',
			ibu: ''
		}
	});
})();
