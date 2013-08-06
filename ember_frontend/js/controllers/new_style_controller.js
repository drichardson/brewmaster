var StyleController = require('./style_controller');

// inherit from edit controller
var NewStyleController = StyleController.extend({
	init: function() {
	  this._super();
		this.set('isEditing', true);
	}
});

module.exports = NewStyleController;

