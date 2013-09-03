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
			collectionType: 'app.Beverages',
			reverseRelation: {
				key: 'beverage_style',
				includeInJSON: 'id'
			}
		}],
		
		defaults: {
			name: '',
			image: '',
			description: ''
		},
				
		initialize: function() {
			this.schema = {
				name:				'Text',
				image: 			'Image',
				description:'TextArea',
			};
		}
	});
})();
