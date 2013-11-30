define(['jquery', 'backbone', 'handlebars', ], 
function($, Backbone, Handlebars) {
	'use strict';

	var beverageBuilderView = Backbone.View.extend({
		
		template: Handlebars.compile( $("#beverage-builder-template").html() ),
		
		render: function() {
			this.$el.html(this.template(this.model.toJSON()));
			return this;
		}
	});
	
	
	return beverageBuilderView;
});