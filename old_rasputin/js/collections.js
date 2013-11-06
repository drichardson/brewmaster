define(['jquery', 'underscore', 'backbone', 'models/beverage', 'models/producer', 'models/beverage_style', 'models/beverage_type', 'models/keg_type', 'models/settings', 'models/tap_entry'],
function($, _, Backbone, Beverage, Producer, BeverageStyle, BeverageType, KegType, Settings, TapEntry) {
	
	var collections = {
		fetchAll: function() {
			for (var i in this) {		
	    	if (this.hasOwnProperty(i)) {
					if (this[i] instanceof Backbone.Collection){
						this[i].fetch();
					}
	    	}
			}
	  }
	};
	
	collections.beverage = new Beverage.collection();			
	collections.producer = new Producer.collection();
	collections.beverageStyle = new BeverageStyle.collection();	
	collections.beverageType = new BeverageType.collection();	
	collections.kegType = new KegType.collection();	
	collections.settings = new Settings.collection();	
	collections.tapEntry = new TapEntry.collection();

	return collections;
});