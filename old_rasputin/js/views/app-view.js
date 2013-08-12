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
			'click #toggle-all': 'toggleAllComplete'
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
			
			app.beverages.fetch();
			
			var testBeverage = new app.Beverage({ title: "Beverage 1"});
			var view = new app.EditBeverageView({ model: testBeverage });
			$('#edit-beverage').append(view.render().el);
		},

		// Add a single beverage item to the list by creating a view for it, and
		// appending its element to the `<ul>`.
		addOne: function (beverage) {
			var view = new app.BeverageItemView({ model: beverage });
			$('#beverage-list').append(view.render().el);
		}
	});
})(jQuery);
