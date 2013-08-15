/*global Backbone */
var app = app || {};

(function () {
	'use strict';

	// Producer Model
	// ----------
	app.Producer = Backbone.RelationalModel.extend({
		
		relations: [{
			type: Backbone.HasMany,
			key: 'beverages',
			relatedModel: 'app.Beverage',
			collectionType: 'app.beverages',
			reverseRelation: {
				key: 'producer',
				includeInJSON: 'id'
			}
		}],
		
		defaults: {
			name: '',
			image: '',
			location: '',
			established: new Date(0) //1970
		}
	});
})();
