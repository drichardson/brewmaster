define(['jquery', 'underscore', 'backbone', 'models/beverage', 'models/producer', 'models/beverage_style', 'models/beverage_type', 'models/keg_type', 'models/settings', 'models/tap_entry'],
function($, _, Backbone, Beverage, Producer, BeverageStyle, BeverageType, KegType, Settings, TapEntry) {
	
	var collections = new Object();
	collections.beverage = new Beverage.collection();			
	collections.producer = new Producer.collection();
	collections.beverageStyle = new BeverageStyle.collection();	
	collections.beverageType = new BeverageType.collection();	
	collections.kegType = new KegType.collection();	
	collections.settings = new Settings.collection();	
	collections.tapEntry = new TapEntry.collection();
	
	for (var i in collections) {
    if (collections.hasOwnProperty(i)) {
			if (i instanceof Backbone.Collection){
				i.fetch();
			}
    }
  }
	
	return collections;
});