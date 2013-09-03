/*global Backbone */
var app = app || {};

(function () {
	'use strict';

	// Beverage Type Model
	// ----------
	app.BeverageType = Backbone.RelationalModel.extend({
		
		relations: [{
			type: Backbone.HasMany,
			key: 'beverages',
			relatedModel: 'app.Beverage',
			collectionType: 'app.Beverages',
			reverseRelation: {
				key: 'beverage_type',
				includeInJSON: 'id'
			}
		}],
		
		defaults: {
			name: '',
			image: '',
		},
				
		initialize: function() {
			this.schema = {
				name:		'Text',
				image: 	'Image'
			};
		}
		
	});
})();
