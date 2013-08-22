/*global Backbone, jQuery, _, ENTER_KEY */
var app = app || {};

(function ($) {
	'use strict';

	// Beverage View
	// --------------

	// The DOM element for a todo item...
	app.BeverageView = Backbone.View.extend({

		tagName:  'div',

		// Cache the template function for a single item.
		template: Handlebars.compile( $("#beverage-template").html() ),
		
		bindings: {
			'#beverage-name': 'name',
			'#beverage-ibu': 'ibu',
			'#beverage-abv': 'abv'
		},

		// Re-render the titles of the todo item.
		render: function () {
			this.$el.html(this.template(this.model.toJSON()));
			return this;
		}
		
	});
})(jQuery);
