define([
  'jquery', 
  'backbone',
	'handlebars',
	'views/list-view',
], function($, Backbone, Handlebars, List) {
	'use strict';

	var tapEntriesItemView = List.ListItemView.extend({
		
		template: Handlebars.compile( $("#tap-entry-row-template").html() ),
		
	});

	var tapEntriesView = List.ListView.extend({
		
		title: "Tap Log",
		
		newItemRoute: '#tap-entry/new',
		
		fields: ['Image', 'Name', 'Brewery', 'ABV', 'IBU'],
		
		itemView: tapEntriesItemView
		
	});
	
	return tapEntriesView;
});
