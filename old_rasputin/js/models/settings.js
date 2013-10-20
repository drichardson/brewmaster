define(['jquery', 'backbone', 'backbone-associations', 'backbone.localStorage', 'views/image'], 
function($, Backbone, Associations, Store, Image) {
	'use strict';

	// --- Model ---
	var Settings = Associations.AssociatedModel.extend({
		defaults: {
			tapCount: 4,
			target_temp: 58
		}
	});

	// --- Collection ---
	var SettingsCollection = Backbone.Collection.extend({
		model: Settings,
		localStorage: new Store('settings-backbone'),
	});

	return {
		model: Settings,
		collection: SettingsCollection
	};
});
