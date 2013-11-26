define(['jquery', 'backbone', 'backbone-associations', 'backbone.localStorage'], 
function($, Backbone, Associations, Store) {
	'use strict';

	// --- Model ---
	var TapEntry = Associations.AssociatedModel.extend({
		// For backbone-forms
		schema: {
			name: 'Text',
			active: 'Checkbox',
			number: 'Number'
			date_added: 'Date',
			date_removed: 'Date'
		},

		// For backbone-associations
		relations: [{
			type: Backbone.One,
			key: 'beverage',
			relatedModel: function() {
				return require('models/beverage').model;
			},
			map:function (beverage_id) {
				return require('collections').beverage.get(beverage_id);
			}
		}, {
			type: Backbone.One,
			key: 'keg_type',
			relatedModel: function() {
				return require('models/keg_type').model;
			},
			map:function (keg_type_id) {
				return require('collections').kegType.get(keg_type_id);
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
		
		activeTaps: function() {
			return this.where({active: true});
		}
	});

	return {
		model: TapEntry,
		collection: TapEntries
	};
});
