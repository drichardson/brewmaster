/*global Backbone */
var app = app || {};

(function () {
	// 'use strict';

	// ----------
	var BrewmasterRouter = Backbone.Router.extend({
		routes: {
			"beverage/new"						: "newModelInstance",
			"beverage/:id/edit"				: "editModelInstance",
			"beverage/:id"						: "getModelInstance",
			"beverages"								: "listCollection",
			
			"beverage-style/new"			: "newModelInstance",
			"beverage-style/:id/edit" : "editModelInstance",
			"beverage-style/:id"			: "getModelInstance",
			"beverage-styles"					: "listCollection",
			
			"beverage-type/new"				: "newModelInstance",
			"beverage-type/:id/edit"	: "editModelInstance",
			"beverage-type/:id"	      : "getModelInstance",
			"beverage-types"          : "listCollection",
			
			"keg-type/new"						: "newModelInstance",
			"keg-type/:id/edit"				: "editModelInstance",
			"keg-type/:id"	          : "getModelInstance",
			"keg-types"               : "listCollection",

			"producer/new"						: "newModelInstance",
			"producer/:id/edit"				: "editModelInstance",
			"producer/:id"						: "getModelInstance",
			"producers"     					: "listCollection",
			
			"tap-entry/new"						: "newModelInstance",
			"tap-entry/:id/edit"			: "editModelInstance",
			"tap-entry/:id"						: "getModelInstance",
			"tap-entries"							: "listCollection",
			
			"settings"								: "getModelInstance",
			"settings/edit"						: "editModelInstance",
		},
		
		_collectionForRouteName: {
			"beverage"				: app.beverages,
			"beverages"				: app.beverages,
			"beverage-style"	: app.beverageStyles,
			"beverage-styles"	: app.beverageStyles,
			"beverage-type"		: app.beverageTypes,
			"beverage-types"	: app.beverageTypes,
			"keg-type"				: app.kegTypes,
			"keg-types"				: app.kegTypes,
			"producer"				: app.producers,
			"producers"				: app.producers,
			"tap-entry"				: app.tapEntries,
			"tap-entries"			: app.tapEntries,
			"settings"				: app.settings
		},
		
		initialize: function() {
			app.currentState = {};
			
			// TODO: Hack.  These should probably be lazily loaded
			for ( key in this._collectionForRouteName ) {
				this._collectionForRouteName[key].fetch();
			}
			
		},
		
		// *** Relational handlers ***
		newModelInstance: function() {
			var base = Backbone.history.fragment.split('/')[0];
			var collection = this._collectionForRouteName[base];
			var model = collection.model;
			var modelInstance = new model();	
			
			app.currentState = {
				'collection' 		: collection,
				'instance'			: modelInstance,
				'modelName'			: base,
				'isEditing'			: true,
				'isCollection'	: false
			};
		},
		
		getModelInstance: function(id) {
			var base = Backbone.history.fragment.split('/')[0];
			var collection = this._collectionForRouteName[base];
			var modelInstance = collection.get(id);
			
			app.currentState = {
				'collection' 		: collection,
				'instance'			: modelInstance,
				'modelName'			: base,
				'isEditing'			: false,
				'isCollection'	: false
			};		
		},
		
		editModelInstance: function(id) {
			var base = Backbone.history.fragment.split('/')[0];
			var collection = this._collectionForRouteName[base];
			var modelInstance = collection.get(id);
			
			app.currentState = {
				'collection' 		: collection,
				'instance'			: modelInstance,
				'modelName'			: base,
				'isEditing'			: true,
				'isCollection'	: false
			};
		},
		
		listCollection: function() {
			var base = Backbone.history.fragment.split('/')[0];
			var collection = this._collectionForRouteName[base];
			
			app.currentState = {
				'collection' 		: collection,
				'instance'			: collection,
				'modelName'			: base,
				'isEditing'			: false,
				'isCollection'	: true
			};
		}

	});

	app.BrewmasterRouter = new BrewmasterRouter();
	Backbone.history.start();
})();
