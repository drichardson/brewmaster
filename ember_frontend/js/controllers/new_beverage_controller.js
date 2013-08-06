var BeverageController = require('./beverage_controller');

// inherit from edit controller
var NewBeverageController = BeverageController.extend({
	init: function() {
	  this._super();
		this.set('isEditing', true);
	}
});

module.exports = NewBeverageController;

