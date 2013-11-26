define([
  'jquery', 
  'backbone',
	'handlebars',
	'views/list-view',
], function($, Backbone, Handlebars, List) {
	'use strict';

	var beverageStylesItemView = List.ListItemView.extend({
		
		template: Handlebars.compile( $("#beverage-style-row-template").html() ),
		
	});

	var beverageStylesView = List.ListView.extend({
		
		title: "Beverage Styles",
		
		fields: ['Image', 'Name', 'Description'],
		
		itemView: beverageStylesItemView,
		
		newItemRoute: '#beverage-style/new'
		
	});
	
	return beverageStylesView;
});
