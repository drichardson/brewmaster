define(['jquery', 'backbone', 'backbone-associations', 'backbone.localStorage', 'views/image'], 
function($, Backbone, Associations, Store, Image) {
	'use strict';

	// --- Model ---
	var BeverageStyle = Associations.AssociatedModel.extend({
		// For backbone-forms
		schema: {
			name: 'Text',
			image: 'Image',
			description: 'TextArea'
		},

		// For backbone-associations
		relations: [{
			type: Backbone.Many,
			key: 'beverages',
			collectionType: function() {
				return require('models/beverage').collection;
			},
			map:function () {
				return require('collections').beverage.where({'beverage':this.id});
			}
		}],

		defaults: {
			name: '',
			image: '',
			description: '',
		}
	});

	// --- Collection ---
	var BeverageStyles = Backbone.Collection.extend({
		model: BeverageStyle,
		localStorage: new Store('beverage-styles-backbone'),
	});

	return {
		model: BeverageStyle,
		collection: BeverageStyles
	};
});
