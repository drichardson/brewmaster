var BeverageTypeController = require('./beverage_type_controller');

// inherit from edit controller
var NewBeverageTypeController = BeverageTypeController.extend({
	init: function() {
	  this._super();
		this.set('isEditing', true);
	}
});

module.exports = NewBeverageTypeController;

