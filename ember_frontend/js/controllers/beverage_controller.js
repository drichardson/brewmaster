var BeverageController = Ember.ObjectController.extend({

	init: function() {
	  this._super();
		this.set('isEditing', false);
	},

	isEditing: false,
	
	isEditingDisabled: function() {
		return !this.get('isEditing');
	}.property('isEditing'),
	
	edit: function() {
		this.set('isEditing', true);
	},
	
  save: function() {
    this.get('store').commit();
		this.set('isEditing', false);
    this.redirectToModel();
  },

  redirectToModel: function() {
    var router = this.get('target');
    var model = this.get('model');
    router.transitionTo('beverage', model);
  },
	
  destroy: function() {
    if (!confirm('Are you sure?')) return;
    this.get('model').deleteRecord();
    this.get('store').commit();
    this.get('target').transitionTo('beverages');
  }

});

module.exports = BeverageController;

