var App = require('./app');

App.Router.map(function() {

  // generated by ember-generate --scaffold
  this.resource('taps');
  this.resource('tap', {path: '/taps/:tap_id'});
  this.route('edit_tap', {path: '/taps/:tap_id/edit'});
  this.route('new_tap', {path: '/taps/new'});
  // end generated routes


  // generated by ember-generate --scaffold
  this.resource('beverage_types');
  this.resource('beverage_type', {path: '/beverage_types/:beverage_type_id'});
  this.route('new_beverage_type', {path: '/beverage_types/new'});
  // end generated routes


  // generated by ember-generate --scaffold
  this.resource('styles');
  this.resource('style', {path: '/styles/:style_id'});
  this.route('new_style', {path: '/styles/new'});
  // end generated routes


  // generated by ember-generate --scaffold
  this.resource('producers');
  this.resource('producer', {path: '/producers/:producer_id'});
  this.route('new_producer', {path: '/producers/new'});
  // end generated routes


  // generated by ember-generate --scaffold
  this.resource('beverages');
  this.resource('beverage', {path: '/beverages/:beverage_id'});
  this.route('edit_beverage', {path: '/beverages/:beverage_id/edit'});
  this.route('new_beverage', {path: '/beverages/new'});
  // end generated routes


});

