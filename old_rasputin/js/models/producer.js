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
			collectionType: 'app.Beverages',
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
		},
				
		initialize: function() {
			this.schema = {
				name:				'Text',
				image: 			'Image', 
				location:		'Text',
				established:'Date'
			}
		}
	});
})();
