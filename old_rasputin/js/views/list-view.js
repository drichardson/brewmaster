define(['jquery', 'backbone', 'handlebars', ], 
function($, Backbone, Handlebars) {
	'use strict';

	// Generic List Item View
	// --------------
	var listItemView = Backbone.View.extend({

		tagName: 'tr',

		template: null,

		render: function() {
			this.$el.html(this.template(this.model.toJSON()));
			return this;
		}

	});

	// Generic List View
	// --------------
	var listView = Backbone.View.extend({

		initialize: function(options) {
			options = options || {};

			Backbone.View.prototype.initialize.call(this, options);

			// Adapted from: http://rickquantz.com/2012/02/rendering-backbone-collections-in-a-view/
			// Add/Remove subviews as needed to avoid extra work on re-rendering
			this._itemViews = {};

			var that = this;
			this.collection.each(function(model) {
				that.addOne(model);
			});

			this.collection.on('add', function(model) {
				this.addOne(model);
				this.render();
			}, this);

			this.collection.on('remove', this.removeOne, this);
		},

		template: Handlebars.compile($("#model-list-template").html()),

		fields: [],

		itemView: listItemView,

		_itemViews: {},

		renderItemViews: function() {
			var els = _.map(this._itemViews, function(view) {
				return view.el;
			});
			return $(els);
		},

		addOne: function(model) {
			var view = new this.itemView({
				model: model
			});
			this._itemViews[model.cid] = view;
			view.render();
		},

		removeOne: function(model) {
			this._itemViews[model.cid].remove();
			delete this._itemViews[model.cid];
		},

		render: function() {
			this.$el.html(this.template(this.fields));
			this.$("#table-body").html(this.renderItemViews());

			return this;
		}

	});

	return {
		ListView: listView,
		ListItemView: listItemView
	};

});
