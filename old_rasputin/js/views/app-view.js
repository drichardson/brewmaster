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

			this.listenTo(app.BrewmasterRouter, 'route', this.routeChanged);
			
			// TODO: load the initial state here and redraw. The router is initialized before this so we don't get the event
			
			app.beverages.fetch();
			
			// var testBeverage = new app.Beverage({ title: "Beverage 1"});
			// var view = new app.EditBeverageView({ model: testBeverage });
			// $('#edit-beverage').append(view.render().el);
			
			// Set the initial route
			this._updateRoute();
		},
		
		routeChanged: function(route) {
			console.log("Route changed: " + route);
			this._updateRoute();
		},
		
		_updateRoute: function() {
				
				if (app.currentState['isCollection']) {
					var options = { 
						model: app.currentState['instance'],
						collection: app.currentState['collection'],
						isEditing: app.currentState['isEditing']
					};
					var view = new app.BeveragesView(options);
					
					$('#main').html(view.render().el)
				} else {
					var view = new app.FormView({ 
						model: app.currentState['instance'],
						collection: app.currentState['collection'],
						isEditing: app.currentState['isEditing']
					});
					
					$('#main').html(view.render().el)
				}
								
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
