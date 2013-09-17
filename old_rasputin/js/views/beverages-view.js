var app = app || {};

(function ($) {
	'use strict';

	app.BeveragesItemView = app.ListItemView.extend({
		
		template: Handlebars.compile( $("#beverage-row-template").html() ),
		
	});

	// Beverages List View
	// --------------
	app.BeveragesView = app.ListView.extend({
		
		fields: ['Image', 'Name', 'Brewery', 'ABV', 'IBU'],
		
		itemView: app.BeveragesItemView
		
	});
	
})(jQuery);
