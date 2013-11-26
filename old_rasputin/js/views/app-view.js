define([
  'jquery', 
  'backbone',
	'views/main-view'
], function($, Backbone, MainView) {
	'use strict';

	// The Application
	// ---------------

	// Our overall **AppView** is the top-level piece of UI.
	var appView = Backbone.View.extend({

		// Instead of generating a new element, bind to the existing skeleton of
		// the App already present in the HTML.
		el: '#brewmasterapp',

		// At initialization we bind to the relevant events on the `Todos`
		// collection, when items are added or changed. Kick things off by
		// loading any preexisting todos that might be saved in *localStorage*.
		initialize: function () {
			this.contentView = null;
			this.on('change:contentView', function() {
				this.render();
			});
		},		
		render: function() {			
			// Render our subview
			var mainView = new MainView();
			if (mainView) {
				$('#main').html(mainView.render().el);
			}
			var contentView = this.contentView;
			if (contentView) {
				$('#content').html(contentView.render().el);
			}
			
			return this;
		}
	});
	
	return appView;
});
