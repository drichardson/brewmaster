/*global Backbone */
var app = app || {};

(function () {
	'use strict';

	// Style Model
	// ----------
	app.BeverageStyle = Backbone.RelationalModel.extend({
		
		relations: [{
			type: Backbone.HasMany,
			key: 'beverages',
			relatedModel: 'app.Beverage',
			collectionType: 'app.beverages',
			reverseRelation: {
				key: 'beverage_style',
				includeInJSON: 'id'
			}
		}],
		
		defaults: {
			name: '',
			image: '',
			description: ''
		}
	});
})();
