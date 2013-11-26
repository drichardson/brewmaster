define([
  'jquery', 
  'backbone',
	'handlebars',
	'views/list-view',
], function($, Backbone, Handlebars, List) {
	'use strict';

	var producersItemView = List.ListItemView.extend({
		
		template: Handlebars.compile( $("#producer-row-template").html() ),
		
	});

	var producersView = List.ListView.extend({
		
		title: "Producers",
		
		newItemRoute: '#producer/new',
		
		fields: ['Image', 'Name', 'Location', 'Established'],
		
		itemView: producersItemView
		
	});
	
	return producersView;
});
