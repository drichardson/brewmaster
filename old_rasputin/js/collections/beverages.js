/*global Backbone */
var app = app || {};

(function () {
	'use strict';

	// Beverage Collection
	// ---------------

	var Beverages = Backbone.Collection.extend({
		// Reference to this collection's model.
		model: app.Beverage,
		
		localStorage: new Backbone.LocalStorage('beverages-backbone'),

		// // We keep the Todos in sequential order, despite being saved by unordered
		// // GUID in the database. This generates the next order number for new items.
		// nextOrder: function () {
		//	if (!this.length) {
		//		return 1;
		//	}
		//	return this.last().get('order') + 1;
		// },
		// 
		// // Todos are sorted by their original insertion order.
		// comparator: function (todo) {
		//	return todo.get('order');
		// }
	});

	// Create our global collection of **Beverages**.
	app.beverages = new Beverages();
})();
