// Main.js
require.config({
	
	// clear the cache on reload so we can actually test things
	urlArgs: "bust=" + (new Date()).getTime(),
	
  paths: {
    jquery: '../vendor/jquery/jquery',
    underscore: '../vendor/underscore/underscore-amd-min',
    backbone: '../vendor/backbone/backbone-amd-min',
		handlebars: '../vendor/handlebars/handlebars',
		'backbone-forms': '../vendor/backbone-forms/distribution.amd/backbone-forms',
		'backbone.localStorage': '../vendor/backbone.localStorage/backbone.localStorage',
		'backbone-associations': '../vendor/backbone-associations/backbone-associations',
	},      
    // Define shim-config
    // For more details : http://requirejs.org/docs/api.html#config-shim
	shim: {
		underscore: {
			exports: '_'
		},
		backbone: {
			deps: ["underscore", "jquery"],
			exports: "Backbone"
		},
		'handlebars': {
			exports: "Handlebars"
		},
		'backbone.localStorage': {
			deps: ["backbone"],
			exports: "Backbone"
		},
		// Define dependency for Backbone-associations
		'backbone-associations': {
			deps: ["backbone"],
			exports: "Backbone"
		}
	}
});

require([
  // Load our app module and pass it to our definition function
  'app',

], function(App){
  // The "app" dependency is passed in as "App"
  // Again, the other dependencies passed in are not "AMD" therefore don't pass a parameter to this function
  App.initialize();
});