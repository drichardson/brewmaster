define(['jquery', 'backbone', 'backbone-associations', 'backbone.localStorage', 'views/image'], 
function($, Backbone, Associations, Store, Image) {
	'use strict';

	// --- Model ---
	var KegType = Associations.AssociatedModel.extend({
		// For backbone-forms
		schema: {
			name: 'Text',
			image: 'Image',
			capacity: 'Number'
		},

		defaults: {
			name: '',
			image: '',
			capacity: 0
		}
	});

	// --- Collection ---
	var KegTypes = Backbone.Collection.extend({
		model: KegType,
		localStorage: new Store('keg-types-backbone'),
	});

	return {
		model: KegType,
		collection: KegTypes
	};
});
