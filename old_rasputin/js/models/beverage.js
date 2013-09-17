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
			collectionType: 'app.TapEntries',
			reverseRelation: {
				key: 'beverage',
				includeInJSON: 'id'
			}
		}],
		
		defaults: {
			name: '',
			image: '',
			abv: 0,
			ibu: 0
		},
		
		initialize: function() {
			this.schema = {
				image: 	'Image', 
				name:		{ type: 'Text' } ,
				producer: { type: 'NestedModel', model: app.Producer },
				beverageType: { type: 'NestedModel', model: app.BeverageType },
				beverageStyle: { type: 'NestedModel', model: app.BeverageStyle },
				abv:		'Number',
				ibu:		'Number'
			};
		}
	});
})();
