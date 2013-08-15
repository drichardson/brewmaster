/*global Backbone */
var app = app || {};

(function () {
	'use strict';

	// Keg Type Model
	// ----------
	app.KegType = Backbone.RelationalModel.extend({
		
		relations: [{
			type: Backbone.HasMany,
			key: 'tap_entry',
			relatedModel: 'app.TapEntry',
			collectionType: 'app.tapEntries',
			reverseRelation: {
				key: 'keg_type',
				includeInJSON: 'id'
			}
		}],
		
		defaults: {
			name: '',
			image: '',
			capacity: -1
		}
	});
})();
