define(['jquery', 'backbone', 'handlebars', ], 
function($, Backbone, Handlebars) {
	'use strict';

	var editTapEntryView = Backbone.View.extend({
		
		template: Handlebars.compile( $("#edit-tap-entry-template").html() ),
		
		render: function() {
			this.$el.html(this.template(this.model.toJSON()));
			return this;
		}
		
	});
	
	return editTapEntryView;
});