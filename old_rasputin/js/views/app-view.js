define([
  'jquery', 
  'backbone',
], function($, Backbone) {
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
			this.mainView = null;
			this.on('change:mainView', function() {
				this.render();
			});
		},		
		render: function() {			
			// Render our subview
			var mainView = this.mainView;
			if (mainView) {
				$('#main').html(mainView.render().el);
			}
			return this;
		},

		// Add a single beverage item to the list by creating a view for it, and
		// appending its element to the `<ul>`.
		// addOne: function (beverage) {
		// 	var view = new app.BeverageItemView({ model: beverage });
		// 	$('#beverage-list').append(view.render().el);
		// }
	});
	
	return appView;
});
