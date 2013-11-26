define([
  'jquery', 
  'backbone',
	'handlebars',
	'models/beverage',
	'backbone-forms'
], function($, Backbone, Handlebars, Beverage) {
	'use strict';

	// Generic Form View
	// --------------
	var formView = Backbone.View.extend({
		
		template: Handlebars.compile( $("#model-edit-template").html() ),
		
		initialize: function(options) {
			options = options || {};
	    Backbone.View.prototype.initialize.call(this, options);
	    
	    _.extend(this, _.pick(options, 'model', 'collection', 'isEditing'));
			this.formView = new Backbone.Form({ model: this.model });
		},
		
		events: {
			'click #save-button': 'saveModel'
		},
		
		saveModel: function() {
						
			this.formView.commit();
			
			// Add it to the collection so it knows to use localstorage to save
			if (this.collection) {
				this.collection.add(this.model);
				this.model.save();
				// this.collection.sync();
				console.log("Model Saved");
			}
		},
		
		render: function() {
			this.$el.html(this.template(this.model.toJSON()));
			
			// We have to replace this html rather than using set element
			// because the form does some shenanigans while rendering.
			// This may cause some issues with event handling.
			this.$("#form-container").html(this.formView.render().el);
			return this;
		}
		
	});
	
	return formView;
});
