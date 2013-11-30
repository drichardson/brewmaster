define(['jquery', 'underscore', 'backbone', 'collections', 'views/app-view', 'views/main-view', 'views/home-screen-view', 'views/edit-tap-entry-view', 'views/beverage-builder-view', 'views/form-view', 'views/beverages-view', 'views/beverage-styles-view', 'views/beverage-types-view', 'views/keg-types-view', 'views/producers-view', 'views/tap-entries-view', 'views/tap-view', 'models/beverage', 'models/producer', 'models/beverage_style', 'models/beverage_type', 'models/keg_type', 'models/settings', 'models/tap_entry'], 
function($, _, Backbone, Collections, AppView, MainView, HomeScreenView, EditTapEntryView, BeverageBuilderView, FormView, BeveragesView, BeverageStylesView, BeverageTypesView, KegTypesView, ProducersView, TapEntriesView, TapView, Beverage, Producer, BeverageStyle, BeverageType, KegType, Settings, TapEntry) {
	// ----------
	var BrewmasterRouter = Backbone.Router.extend({
		routes: {
			
			"": "index",
			
			"beverage/new": "newModelInstance",
			"beverage/:id": "getModelInstance",
			"beverages": "listCollection",

			"beverage-style/new": "newModelInstance",
			"beverage-style/:id": "getModelInstance",
			"beverage-styles": "listCollection",

			"beverage-type/new": "newModelInstance",
			"beverage-type/:id": "getModelInstance",
			"beverage-types": "listCollection",

			"keg-type/new": "newModelInstance",
			"keg-type/:id": "getModelInstance",
			"keg-types": "listCollection",

			"producer/new": "newModelInstance",
			"producer/:id": "getModelInstance",
			"producers": "listCollection",

			"tap-entry/new": "newModelInstance",
			"tap-entry/:id/edit": "editTapEntry",
			"tap-entry/:id": "getModelInstance",
			"tap-entries": "listCollection",
			
			// beverage builder
			"tap-entry/:id/edit/beverage": "editTapEntryBeverage", // include type on here
			"tap-entry/:id/edit/producer": "editTapEntryProducer",
			"tap-entry/:id/edit/beverageStyle": "editTapEntryBeverageStyle",			

			"settings": "getModelInstance",
		},

		initialize: function() {
			this.appView = new AppView();

			this._initializeCollections();
		},

		_collectionForRouteName: {},

		_initializeCollections: function() {

			Collections.fetchAll();
			
			this._collectionForRouteName = {
				'beverage': Collections.beverage,
				'beverages': Collections.beverage,
				'producer': Collections.producer,
				'producers': Collections.producer,
				'beverage-style': Collections.beverageStyle,
				'beverage-styles': Collections.beverageStyle,
				'beverage-type': Collections.beverageType,
				'beverage-types': Collections.beverageType,
				'keg-type': Collections.kegType,
				'keg-types': Collections.kegType,
				'settings': Collections.settings,
				'tap-entry': Collections.tapEntry,
				'tap-entries': Collections.tapEntry,
			};		
		},

		_getCurrentCollection: function() {
			var base = Backbone.history.fragment.split('/')[0];
			var collection = this._collectionForRouteName[base];
			return collection;
		},
		
		// *** Handlers ***
		index: function() {
			// var tapModel = Collections.tapEntry.create({beverage:'5c6837b8-d36b-bede-6fb7-10bc0ba196c3'});
			var homeScreen = new HomeScreenView({});
			this.appView.contentView = homeScreen;
			this.appView.render();
		},

		// *** Relational handlers ***
		newModelInstance: function() {
			var collection = this._getCurrentCollection();
			var model = collection.model;
			var modelInstance = new model();

			var options = {
				'collection': collection,
				'model': modelInstance,
				'isEditing': true,
			};
			var formView = new FormView(options);
			this.appView.contentView = formView;
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
			this.appView.contentView = formView;
			this.appView.render();
		},

		listCollection: function() {
			var collection = this._getCurrentCollection();

			var options = {
				'collection': collection,
				'instance': collection,
				'isEditing': false,
			};
			
			var listView = null;
			if (collection instanceof Beverage.collection) {
				listView = new BeveragesView(options);
			} else if (collection instanceof BeverageType.collection) {
				listView = new BeverageTypesView(options);
			} else if (collection instanceof BeverageStyle.collection) {
				listView = new BeverageStylesView(options);
			} else if (collection instanceof KegType.collection) {
				listView = new KegTypesView(options);
			} else if (collection instanceof Producer.collection) {
				listView = new ProducersView(options);
			} else if (collection instanceof TapEntry.collection) {
				listView = new TapEntriesView(options);
			}	
			this.appView.contentView = listView;
			this.appView.render();
		},
		
		editTapEntry: function(id) {
			var collection = this._getCurrentCollection();
			var modelInstance = collection.get(id);
			var editView = new EditTapEntryView({model: modelInstance});
			this.appView.contentView = editView;
			this.appView.render();
		},
		
		editTapEntryBeverage: function(id) {
			var collection = this._getCurrentCollection();
			var modelInstance = collection.get(id);
			var editView = new BeverageBuilder({model: modelInstance});
			this.appView.contentView = editView;
			this.appView.render();
		},

	});

	var initialize = function() {
			var router = new BrewmasterRouter();
			Backbone.history.start();
		};

	return {
		initialize: initialize
	};
});
