define(['jquery', 'backbone', 'backbone-associations', 'backbone.localStorage'], 
function($, Backbone, Associations, Store) {
	'use strict';

	// --- Model ---
	var TapEntry = Associations.AssociatedModel.extend({
		// For backbone-forms
		schema: {
			name: 'Text',
			active: 'Checkbox',
			date_added: 'Date',
			date_removed: 'Date'
		},

		// For backbone-associations
		relations: [{
			type: Backbone.One,
			key: 'beverage',
			relatedModel: function() {
				return require('models/beverage').model;
			}
		}],

		defaults: {
			name: '',
			active: false,
			date_added: new Date(0),
			date_removed: new Date(0),
			beverage: undefined
		}
	});

	// --- Collection ---
	var TapEntries = Backbone.Collection.extend({
		model: TapEntry,
		localStorage: new Store('tap-entries-backbone'),
	});

	return {
		model: TapEntry,
		collection: TapEntries
	};
});
