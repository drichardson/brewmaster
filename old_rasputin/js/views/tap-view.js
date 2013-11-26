define(['jquery', 'backbone', 'handlebars', 'collections'], 
function($, Backbone, Handlebars, Collections) {
	'use strict';

	var tapView = Backbone.View.extend({
				
		template: Handlebars.compile( $("#tap-entry-template").html() ),
		
		render: function() {
			this.$el.html(this.template(this.model.toJSON()));
			return this;
		}
		
	});
	
	return tapView;
});