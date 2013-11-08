define(['jquery', 'backbone', 'backbone-associations', 'backbone.localStorage', 'views/image'], 
function($, Backbone, Associations, Store, Image) {
	'use strict';

	// --- Model ---
	var BeverageType = Associations.AssociatedModel.extend({
		// For backbone-forms
		schema: {
			name:		'Text',
			image: 	'Image'
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
			image: ''
		}
	});

	// --- Collection ---
	var BeverageTypes = Backbone.Collection.extend({
		model: BeverageType,
		localStorage: new Store('beverage-types-backbone'),
	});

	return {
		model: BeverageType,
		collection: BeverageTypes
	};
});
