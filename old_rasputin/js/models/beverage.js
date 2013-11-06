define(['jquery', 'backbone', 'backbone-associations', 'backbone.localStorage', 'models/beverage_style', 'models/beverage_type', 'models/producer', 'models/tap_entry', 'views/image'], 
function($, Backbone, Associations, Store, BeverageStyle, BeverageType, Producer, TapEntry, Image) {
	'use strict';

	// --- Model ---
	var Beverage = Associations.AssociatedModel.extend({
		// For backbone-forms
		schema: {
			image: 'Image',
			name: {
				type: 'Text'
			},
			producer: {
				type: 'NestedModel',
				model: Producer.model
			},
			beverage_type: {
				type: 'NestedModel',
				model: BeverageType.model
			},
			beverage_style: {
				type: 'NestedModel',
				model: BeverageStyle.model
			},
			abv: 'Number',
			ibu: 'Number'
		},

		// For backbone-associations
		relations: [{
			type: Backbone.One,
			key: 'producer',
			relatedModel: Producer.model,
			map:function (producer_id) {
				return require('collections').producer.get(producer_id);
			}
		}, {
			type: Backbone.One,
			key: 'beverageType',
			relatedModel: BeverageType.model,
			map:function (type_id) {
				return require('collections').beverageType.get(type_id);
			}
		}, {
			type: Backbone.One,
			key: 'beverageStyle',
			relatedModel: BeverageStyle.model,
			map:function (style_id) {
				return require('collections').beverageStyle.get(style_id);
			}
		}, {
			type: Backbone.Many,
			key: 'tapEntries',
			collectionType: TapEntry.collection,
			map:function () {
				return require('collections').tapEntry.where({'beverage':this.id});
			}
		}],

		defaults: {
			name: '',
			image: '',
			abv: 0,
			ibu: 0,
			beverageStyle: undefined,
			beverageType: undefined,
			producer: undefined,
		},
	});

	// --- Collection ---
	var Beverages = Backbone.Collection.extend({
		model: Beverage,
		localStorage: new Store('beverages-backbone'),
	});

	return {
		model: Beverage,
		collection: Beverages
	};
});
