/*global Backbone */
var app = app || {};

(function () {
	'use strict';

	// Tap Entry Model
	// ----------
	app.TapEntry = Backbone.RelationalModel.extend({
		
		defaults: {
			name: '',
			active: false,
			date_added: new Date(0),
			date_removed: new Date(0)
		},
				
		initialize: function() {
			this.schema = {
				name:					'Text',
				active: 			'Checkbox', 
				date_added: 	'Date', 
				date_removed:	'Date'
			}
		}
	});
})();
