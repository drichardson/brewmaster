define([
  'jquery', 
  'backbone',
	'handlebars',
	'views/list-view',
], function($, Backbone, Handlebars, List) {
	'use strict';

	var beverageTypesItemView = List.ListItemView.extend({
		
		template: Handlebars.compile( $("#beverage-type-row-template").html() ),
		
	});

	var beverageTypesView = List.ListView.extend({
		
		fields: ['Image', 'Name'],
		
		itemView: beverageTypesItemView
		
	});
	
	return beverageTypesView;
});
