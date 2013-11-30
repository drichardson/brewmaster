define(['jquery', 'backbone', 'handlebars', 'collections', 'views/tap-view' ], 
function($, Backbone, Handlebars, Collections, TapView) {
	'use strict';

	var homeScreen = Backbone.View.extend({
		
		template: Handlebars.compile($("#home-screen-view-template").html()),
		
		tapViews: {},
		
		tapViewGridAttributes: "col-xs-6 col-md-3",
		
		renderTapViews: function() {
			var taps = Collections.tapEntry.activeTaps();
			this.tapViews = _.map(taps, function(tap) {
				return new TapView({model: tap});
			});
			var that = this;
			var els = _.map(this.tapViews, function(view) {
				var el = view.render().el;
				$(el).addClass(that.tapViewGridAttributes);
				return el;
			});
			return $(els);
		},
		
		render: function() {
			this.$el.html(this.template());
			this.$("#tap-entry-grid-row").html(this.renderTapViews());
			return this;
		}
	});
	
	return homeScreen;
});