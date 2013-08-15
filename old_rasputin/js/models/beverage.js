/*global Backbone */
var app = app || {};

(function () {
	'use strict';

	// Beverage Model
	// ----------
	app.Beverage = Backbone.RelationalModel.extend({
		
		relations: [{
			type: Backbone.HasMany,
			key: 'tap_entries',
			relatedModel: 'app.TapEntry',
			collectionType: 'app.tapEntries',
			reverseRelation: {
				key: 'beverage',
				includeInJSON: 'id'
			}
		}],
		
		defaults: {
			name: '',
			image: '',
			abv: -1,
			ibu: -1
		}
	});
})();
