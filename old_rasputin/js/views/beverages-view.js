define([
  'jquery', 
  'backbone',
	'handlebars',
	'/views/list-view',
], function($, Backbone, Handlebars, List) {
	'use strict';

	var beveragesItemView = List.ListItemView.extend({
		
		template: Handlebars.compile( $("#beverage-row-template").html() ),
		
	});

	// Beverages List View
	// --------------
	var beveragesView = List.ListView.extend({
		
		fields: ['Image', 'Name', 'Brewery', 'ABV', 'IBU'],
		
		itemView: beveragesItemView
		
	});
	
	return beveragesView;
});
