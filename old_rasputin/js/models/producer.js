define(['jquery', 'backbone', 'backbone-associations', 'backbone.localStorage', 'views/image'], 
function($, Backbone, Associations, Store, Image) {
	'use strict';

	// --- Model ---
	var Producer = Associations.AssociatedModel.extend({
		// For backbone-forms
		schema: {
			name:				'Text',
			image: 			'Image', 
			location:		'Text',
			established:'Date'
		},

		// For backbone-associations
		relations: [{
			type: Backbone.Many,
			key: 'beverages',
			collectionType: function() {
				return require('models/beverage').collection;
			}
		}],

		defaults: {
			name: '',
			image: '',
			location: '',
			established: new Date(0) //1970
		}
	});

	// --- Collection ---
	var Producers = Backbone.Collection.extend({
		model: Producer,
		localStorage: new Store('producers-backbone'),
	});

	return {
		model: Producer,
		collection: Producers
	};
});
