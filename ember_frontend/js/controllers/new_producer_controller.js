var ProducerController = require('./producer_controller');

// inherit from edit controller
var NewProducerController = ProducerController.extend({
	init: function() {
	  this._super();
		this.set('isEditing', true);
	}
});

module.exports = NewProducerController;

