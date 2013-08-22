/*global Backbone, jQuery, _, ENTER_KEY */
var app = app || {};

(function ($) {
	'use strict';

	// The Application
	// ---------------

	// Our overall **AppView** is the top-level piece of UI.
	app.AppView = Backbone.View.extend({

		// Instead of generating a new element, bind to the existing skeleton of
		// the App already present in the HTML.
		el: '#brewmasterapp',

		// Delegated events for creating new items, and clearing completed ones.
		events: {
			'keypress #new-todo': 'createOnEnter',
			'click #clear-completed': 'clearCompleted',
			'click #toggle-all': 'toggleAllComplete',
		},

		// At initialization we bind to the relevant events on the `Todos`
		// collection, when items are added or changed. Kick things off by
		// loading any preexisting todos that might be saved in *localStorage*.
		initialize: function () {
			// this.allCheckbox = this.$('#toggle-all')[0];
			// this.$input = this.$('#new-beverage');
			// this.$footer = this.$('#footer');
			// this.$main = this.$('#main');

			this.listenTo(app.beverages, 'add', this.addOne);		
			this.listenTo(app.BrewmasterRouter, 'route', this.routeChanged);
			
			// TODO: load the initial state here and redraw. The router is initialized before this so we don't get the event
			
			app.beverages.fetch();
			
			// var testBeverage = new app.Beverage({ title: "Beverage 1"});
			// var view = new app.EditBeverageView({ model: testBeverage });
			// $('#edit-beverage').append(view.render().el);
			
			// Set the initial route
			this._updateRoute();
		},
		
		_viewForModelName: {
			'beverage'				: app.BeverageView,
			'beverages' 			: app.BeveragesView,
			'beverage-style' 	: 'beverage-style-view',
			'beverage-styles' : 'beverage-styles-view',
			'beverage-type'		: 'beverage-type-view',
			'beverage-types'	: 'beverage-types-view',
			'keg-type'				: 'keg-type-view',
			'keg-types'				: 'keg-types-view',
			'producer'				: 'producer-view',
			'producers'				: 'producers-view',
			'tap-entry'				: 'tap-entry-view',
			'tap-entries'			: 'tap-entries-view'
		},
		
		routeChanged: function(route) {
			console.log("Route changed: " + route);
			this._updateRoute();
		},
		
		_updateRoute: function() {
				var viewProto = this._viewForModelName[app.currentState['modelName']];
				var view = new viewProto({ model : app.currentState['instance'] });
				// TODO: remove current view
				$('#main').empty();
				$('#main').append(view.render().el);
				console.log("Updated Main View");
		},

		// Add a single beverage item to the list by creating a view for it, and
		// appending its element to the `<ul>`.
		addOne: function (beverage) {
			var view = new app.BeverageItemView({ model: beverage });
			$('#beverage-list').append(view.render().el);
		}
	});
})(jQuery);
