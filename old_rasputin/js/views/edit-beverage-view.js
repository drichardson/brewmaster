/*global Backbone, jQuery, _, ENTER_KEY */
var app = app || {};

(function ($) {
	'use strict';

	// Todo Item View
	// --------------

	// The DOM element for a beverage item beign edited
	app.EditBeverageView = Backbone.View.extend({
		tagName:  'div', 

		// Cache the template function for a single item.
		template: Handlebars.compile( $("#edit-beverage-template").html() ),

		bindings: {
	    '#beverage-name': 'name',
			'#brewery-name': 'brewery',
	    '#beverage-name': 'name',
	    '#beverage-name': 'name',
	    '#beverage-name': 'name',
		},
		
		events: {
			'click .save': 'saveModel',
		},
		
		initialize: function () {
			this.listenTo(this.model, 'destroy', this.remove);
			this.listenTo(this.model, 'visible', this.toggleVisible);
		},
		
		saveModel: function() {
			app.beverages.add(this.model);
		},

		// Re-render the titles of the todo item.
		render: function () {
			this.$el.html(this.template(this.model.toJSON()));
			this.stickit();
			return this;
		}
		
	});
})(jQuery);
