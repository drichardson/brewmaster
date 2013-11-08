define([
  'jquery', 
  'backbone',
	'handlebars',
	'views/list-view',
], function($, Backbone, Handlebars, List) {
	'use strict';

	var kegTypesItemView = List.ListItemView.extend({
		
		template: Handlebars.compile( $("#keg-type-row-template").html() ),
		
	});

	var kegTypesView = List.ListView.extend({
		
		fields: ['Image', 'Name', 'Capacity'],
		
		itemView: kegTypesItemView
		
	});
	
	return kegTypesView;
});
