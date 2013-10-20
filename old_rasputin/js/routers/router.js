define(['jquery', 'underscore', 'backbone', 'views/app-view', 'views/form-view', 'models/beverage'], 
function($, _, Backbone, AppView, FormView, Beverage) {
	// ----------
	var BrewmasterRouter = Backbone.Router.extend({
		routes: {
			"beverage/new": "newModelInstance",
			"beverage/:id/edit": "editModelInstance",
			"beverage/:id": "getModelInstance",
			"beverages": "listCollection",

			"beverage-style/new": "newModelInstance",
			"beverage-style/:id/edit": "editModelInstance",
			"beverage-style/:id": "getModelInstance",
			"beverage-styles": "listCollection",

			"beverage-type/new": "newModelInstance",
			"beverage-type/:id/edit": "editModelInstance",
			"beverage-type/:id": "getModelInstance",
			"beverage-types": "listCollection",

			"keg-type/new": "newModelInstance",
			"keg-type/:id/edit": "editModelInstance",
			"keg-type/:id": "getModelInstance",
			"keg-types": "listCollection",

			"producer/new": "newModelInstance",
			"producer/:id/edit": "editModelInstance",
			"producer/:id": "getModelInstance",
			"producers": "listCollection",

			"tap-entry/new": "newModelInstance",
			"tap-entry/:id/edit": "editModelInstance",
			"tap-entry/:id": "getModelInstance",
			"tap-entries": "listCollection",

			"settings": "getModelInstance",
			"settings/edit": "editModelInstance",
		},

		// _collectionForRouteName: {
		// 	"beverage"				: App.beverages,
		// 	"beverages"				: App.beverages,
		// 	// "beverage-style"	: App.beverageStyles,
		// 	// "beverage-styles"	: App.beverageStyles,
		// 	// "beverage-type"		: App.beverageTypes,
		// 	// "beverage-types"	: App.beverageTypes,
		// 	// "keg-type"				: App.kegTypes,
		// 	// "keg-types"				: App.kegTypes,
		// 	// "producer"				: App.producers,
		// 	// "producers"				: App.producers,
		// 	// "tap-entry"				: App.tapEntries,
		// 	// "tap-entries"			: App.tapEntries,
		// 	// "settings"				: App.settings
		// },
		// TODO: make it so the router does all the muxing, creates the app view
		// Then passes the subview down to the app view when we have data
		// The router should probably own the app view
		initialize: function() {
			this.appView = new AppView();

			this._initializeCollections();
		},

		_collectionForRouteName: {},

		_initializeCollections: function() {
			var beverageCollection = new Beverage.collection();

			this._collectionForRouteName = {
				'beverage': beverageCollection,
				'beverages': beverageCollection
			};
		},

		_getCurrentCollection: function() {
			var base = Backbone.history.fragment.split('/')[0];
			var collection = this._collectionForRouteName[base];
			return collection;
		},

		// *** Relational handlers ***
		newModelInstance: function() {
			var collection = this._getCurrentCollection();
			var model = collection.model;
			var modelInstance = new model();

			debugger;
			var options = {
				'collection': collection,
				'model': modelInstance,
				'isEditing': true,
			};
			var formView = new FormView(options);
			this.appView.mainView = formView;
			this.appView.render();
		},

		getModelInstance: function(id) {
			var collection = this._getCurrentCollection();
			var modelInstance = collection.get(id);

			var options = {
				'collection': collection,
				'model': modelInstance,
				'isEditing': false,
			};
			var formView = new FormView(options);
			this.appView.mainView = formView;
		},

		editModelInstance: function(id) {
			var collection = this._getCurrentCollection();
			var modelInstance = collection.get(id);

			var options = {
				'collection': collection,
				'model': modelInstance,
				'isEditing': true,
			};
			var formView = new FormView(options);
			this.appView.mainView = formView;
		},

		listCollection: function() {
			var collection = this._getCurrentCollection();

			var options = {
				'collection': collection,
				'instance': collection,
				'isEditing': false,
			};
		}

	});

	var initialize = function() {
			var router = new BrewmasterRouter();
			Backbone.history.start();
		};

	return {
		initialize: initialize
	};
});
