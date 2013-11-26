define(['jquery', 'backbone', 'handlebars' ], 
function($, Backbone, Handlebars) {
	'use strict';

	var mainView = Backbone.View.extend({
		
		initialize: function() {
			require(['../vendor/bootstrap-3.0/js/bootstrap.min']);
		},
		
		template: Handlebars.compile($("#main-view-template").html()),
		
		render: function() {
			this.$el.html(this.template());
			return this;
		}
	});
	
	return mainView;
});