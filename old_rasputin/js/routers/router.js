/*global Backbone */
var app = app || {};

(function () {
	// 'use strict';

	// ----------
	var BrewmasterRouter = Backbone.Router.extend({
		routes: {
			"beverage/new"						: "newModelInstance",
			"beverage/:id"						: "getModelInstance",
			"beverage/:id/edit"				: "editModelInstance",
			"beverages"								: "listCollection",
			
			"beverage-style/new"			: "newModelInstance",
			"beverage-style/:id"			: "getModelInstance",
			"beverage-style/:id/edit" : "editModelInstance",
			"beverage-styles"					: "listCollection",
			
			"beverage-type/new"				: "newModelInstance",
			"beverage-type/:id"	      : "getModelInstance",
			"beverage-type/:id/edit"	: "editModelInstance",
			"beverage-types"          : "listCollection",
			
			"keg-type/new"						: "newModelInstance",
			"keg-type/:id"	          : "getModelInstance",
			"keg-type/:id/edit"				: "editModelInstance",
			"keg-types"               : "listCollection",

			"producer/new"						: "newModelInstance",
			"producer/:id"						: "getModelInstance",
			"producer/:id/edit"				: "editModelInstance",
			"producers"     					: "listCollection",
			
			"tap-entry/new"						: "newModelInstance",  	
			"tap-entry/:id"						: "getModelInstance",
			"tap-entry/:id/edit"			: "editModelInstance",
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
		
		// *** Relational handlers ***
		newModelInstance: function() {
			var base = Backbone.history.fragment.split('/')[0];
			var collection = this._collectionForRouteName[base];
			var model = collection.model;
			var modelInstance = new model();	
			
			app.currentState = {
				'collection' 		: collection,
				'instance'			: modelInstance,
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
				'isEditing'			: false,
				'isCollection'	: true
			};
		}

	});

	app.BrewmasterRouter = new BrewmasterRouter();
	Backbone.history.start();
})();
