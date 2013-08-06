
Ember.TEMPLATES['application'] = Ember.Handlebars.template(function anonymous(Handlebars,depth0,helpers,partials,data) {
this.compilerInfo = [2,'>= 1.0.0-rc.3'];
helpers = helpers || Ember.Handlebars.helpers; data = data || {};
  var buffer = '', stack1, stack2, hashTypes, options, self=this, helperMissing=helpers.helperMissing, escapeExpression=this.escapeExpression;

function program1(depth0,data) {
  
  var buffer = '', stack1, stack2, hashTypes, options;
  data.buffer.push("\n						");
  hashTypes = {};
  options = {hash:{},inverse:self.noop,fn:self.program(2, program2, data),contexts:[depth0],types:["STRING"],hashTypes:hashTypes,data:data};
  stack2 = ((stack1 = helpers.linkTo),stack1 ? stack1.call(depth0, "index", options) : helperMissing.call(depth0, "linkTo", "index", options));
  if(stack2 || stack2 === 0) { data.buffer.push(stack2); }
  data.buffer.push("\n					");
  return buffer;
  }
function program2(depth0,data) {
  
  
  data.buffer.push("Home");
  }

function program4(depth0,data) {
  
  var buffer = '', stack1, stack2, hashTypes, options;
  data.buffer.push("\n						");
  hashTypes = {};
  options = {hash:{},inverse:self.noop,fn:self.program(5, program5, data),contexts:[depth0],types:["STRING"],hashTypes:hashTypes,data:data};
  stack2 = ((stack1 = helpers.linkTo),stack1 ? stack1.call(depth0, "taps", options) : helperMissing.call(depth0, "linkTo", "taps", options));
  if(stack2 || stack2 === 0) { data.buffer.push(stack2); }
  data.buffer.push("\n					");
  return buffer;
  }
function program5(depth0,data) {
  
  
  data.buffer.push("Taps");
  }

function program7(depth0,data) {
  
  var buffer = '', stack1, stack2, hashTypes, options;
  data.buffer.push("\n						");
  hashTypes = {};
  options = {hash:{},inverse:self.noop,fn:self.program(8, program8, data),contexts:[depth0],types:["STRING"],hashTypes:hashTypes,data:data};
  stack2 = ((stack1 = helpers.linkTo),stack1 ? stack1.call(depth0, "beverages", options) : helperMissing.call(depth0, "linkTo", "beverages", options));
  if(stack2 || stack2 === 0) { data.buffer.push(stack2); }
  data.buffer.push("\n					");
  return buffer;
  }
function program8(depth0,data) {
  
  
  data.buffer.push("Beverages");
  }

function program10(depth0,data) {
  
  var buffer = '', stack1, stack2, hashTypes, options;
  data.buffer.push("\n						");
  hashTypes = {};
  options = {hash:{},inverse:self.noop,fn:self.program(11, program11, data),contexts:[depth0],types:["STRING"],hashTypes:hashTypes,data:data};
  stack2 = ((stack1 = helpers.linkTo),stack1 ? stack1.call(depth0, "producers", options) : helperMissing.call(depth0, "linkTo", "producers", options));
  if(stack2 || stack2 === 0) { data.buffer.push(stack2); }
  data.buffer.push("\n					");
  return buffer;
  }
function program11(depth0,data) {
  
  
  data.buffer.push("Breweries");
  }

function program13(depth0,data) {
  
  var buffer = '', stack1, stack2, hashTypes, options;
  data.buffer.push("\n						");
  hashTypes = {};
  options = {hash:{},inverse:self.noop,fn:self.program(14, program14, data),contexts:[depth0],types:["STRING"],hashTypes:hashTypes,data:data};
  stack2 = ((stack1 = helpers.linkTo),stack1 ? stack1.call(depth0, "beverage_types", options) : helperMissing.call(depth0, "linkTo", "beverage_types", options));
  if(stack2 || stack2 === 0) { data.buffer.push(stack2); }
  data.buffer.push("\n					");
  return buffer;
  }
function program14(depth0,data) {
  
  
  data.buffer.push("Types");
  }

function program16(depth0,data) {
  
  var buffer = '', stack1, stack2, hashTypes, options;
  data.buffer.push("\n						");
  hashTypes = {};
  options = {hash:{},inverse:self.noop,fn:self.program(17, program17, data),contexts:[depth0],types:["STRING"],hashTypes:hashTypes,data:data};
  stack2 = ((stack1 = helpers.linkTo),stack1 ? stack1.call(depth0, "styles", options) : helperMissing.call(depth0, "linkTo", "styles", options));
  if(stack2 || stack2 === 0) { data.buffer.push(stack2); }
  data.buffer.push("\n					");
  return buffer;
  }
function program17(depth0,data) {
  
  
  data.buffer.push("Styles");
  }

function program19(depth0,data) {
  
  var buffer = '', stack1, stack2, hashTypes, options;
  data.buffer.push("\n						");
  hashTypes = {};
  options = {hash:{},inverse:self.noop,fn:self.program(20, program20, data),contexts:[depth0],types:["STRING"],hashTypes:hashTypes,data:data};
  stack2 = ((stack1 = helpers.linkTo),stack1 ? stack1.call(depth0, "index", options) : helperMissing.call(depth0, "linkTo", "index", options));
  if(stack2 || stack2 === 0) { data.buffer.push(stack2); }
  data.buffer.push("\n					");
  return buffer;
  }
function program20(depth0,data) {
  
  
  data.buffer.push("Other");
  }

  data.buffer.push("<div class=\"navbar navbar-fixed-top\">\n  <div class=\"navbar-inner\">\n    <div class=\"container\">\n      <button type=\"button\" class=\"btn btn-navbar\" data-toggle=\"collapse\" data-target=\".nav-collapse\">\n        <span class=\"icon-bar\"></span>\n        <span class=\"icon-bar\"></span>\n        <span class=\"icon-bar\"></span>\n      </button>\n      <li class=\"brand\" href=\"#\">Brewmaster</li>\n      <div class=\"nav-collapse collapse\">\n        <ul class=\"nav\">\n					");
  hashTypes = {};
  stack1 = helpers.view.call(depth0, "App.NavView", {hash:{},inverse:self.noop,fn:self.program(1, program1, data),contexts:[depth0],types:["ID"],hashTypes:hashTypes,data:data});
  if(stack1 || stack1 === 0) { data.buffer.push(stack1); }
  data.buffer.push("\n					");
  hashTypes = {};
  stack1 = helpers.view.call(depth0, "App.NavView", {hash:{},inverse:self.noop,fn:self.program(4, program4, data),contexts:[depth0],types:["ID"],hashTypes:hashTypes,data:data});
  if(stack1 || stack1 === 0) { data.buffer.push(stack1); }
  data.buffer.push("\n					");
  hashTypes = {};
  stack1 = helpers.view.call(depth0, "App.NavView", {hash:{},inverse:self.noop,fn:self.program(7, program7, data),contexts:[depth0],types:["ID"],hashTypes:hashTypes,data:data});
  if(stack1 || stack1 === 0) { data.buffer.push(stack1); }
  data.buffer.push("\n					");
  hashTypes = {};
  stack1 = helpers.view.call(depth0, "App.NavView", {hash:{},inverse:self.noop,fn:self.program(10, program10, data),contexts:[depth0],types:["ID"],hashTypes:hashTypes,data:data});
  if(stack1 || stack1 === 0) { data.buffer.push(stack1); }
  data.buffer.push("\n					");
  hashTypes = {};
  stack1 = helpers.view.call(depth0, "App.NavView", {hash:{},inverse:self.noop,fn:self.program(13, program13, data),contexts:[depth0],types:["ID"],hashTypes:hashTypes,data:data});
  if(stack1 || stack1 === 0) { data.buffer.push(stack1); }
  data.buffer.push("\n					");
  hashTypes = {};
  stack1 = helpers.view.call(depth0, "App.NavView", {hash:{},inverse:self.noop,fn:self.program(16, program16, data),contexts:[depth0],types:["ID"],hashTypes:hashTypes,data:data});
  if(stack1 || stack1 === 0) { data.buffer.push(stack1); }
  data.buffer.push("\n					");
  hashTypes = {};
  stack1 = helpers.view.call(depth0, "App.NavView", {hash:{},inverse:self.noop,fn:self.program(19, program19, data),contexts:[depth0],types:["ID"],hashTypes:hashTypes,data:data});
  if(stack1 || stack1 === 0) { data.buffer.push(stack1); }
  data.buffer.push("\n        </ul>\n      </div>\n    </div>\n  </div>\n</div>\n<div class=\"container\">\n    <!--<li>");
  hashTypes = {};
  options = {hash:{},inverse:self.noop,fn:self.program(2, program2, data),contexts:[depth0],types:["STRING"],hashTypes:hashTypes,data:data};
  stack2 = ((stack1 = helpers.linkTo),stack1 ? stack1.call(depth0, "index", options) : helperMissing.call(depth0, "linkTo", "index", options));
  if(stack2 || stack2 === 0) { data.buffer.push(stack2); }
  data.buffer.push("</li>-->\n");
  hashTypes = {};
  data.buffer.push(escapeExpression(helpers._triageMustache.call(depth0, "outlet", {hash:{},contexts:[depth0],types:["ID"],hashTypes:hashTypes,data:data})));
  data.buffer.push("\n</div\">\n\n");
  return buffer;
  
});

Ember.TEMPLATES['beverage'] = Ember.Handlebars.template(function anonymous(Handlebars,depth0,helpers,partials,data) {
this.compilerInfo = [2,'>= 1.0.0-rc.3'];
helpers = helpers || Ember.Handlebars.helpers; data = data || {};
  var buffer = '', stack1, hashTypes, options, escapeExpression=this.escapeExpression, self=this, helperMissing=helpers.helperMissing;

function program1(depth0,data) {
  
  var buffer = '', stack1, hashTypes;
  data.buffer.push("\n		");
  hashTypes = {'name': "STRING"};
  stack1 = helpers.view.call(depth0, "App.ImageUploadView", {hash:{
    'name': ("image")
  },inverse:self.noop,fn:self.program(2, program2, data),contexts:[depth0],types:["ID"],hashTypes:hashTypes,data:data});
  if(stack1 || stack1 === 0) { data.buffer.push(stack1); }
  data.buffer.push("\n	");
  return buffer;
  }
function program2(depth0,data) {
  
  var buffer = '', hashTypes;
  data.buffer.push("\n			<div class=\"controls\">\n				");
  hashTypes = {'width': "STRING",'height': "STRING",'srcBinding': "STRING",'class': "STRING"};
  data.buffer.push(escapeExpression(helpers.view.call(depth0, "view.previewImageView", {hash:{
    'width': ("200"),
    'height': ("100"),
    'srcBinding': ("image"),
    'class': ("img-polaroid")
  },contexts:[depth0],types:["ID"],hashTypes:hashTypes,data:data})));
  data.buffer.push("\n			</div>\n			<div ");
  hashTypes = {'class': "STRING"};
  data.buffer.push(escapeExpression(helpers.bindAttr.call(depth0, {hash:{
    'class': (":controls :file-wrapper isEditingDisabled:transparent:active")
  },contexts:[],types:[],hashTypes:hashTypes,data:data})));
  data.buffer.push(">\n				");
  hashTypes = {};
  data.buffer.push(escapeExpression(helpers.view.call(depth0, "view.fileField", {hash:{},contexts:[depth0],types:["ID"],hashTypes:hashTypes,data:data})));
  data.buffer.push("\n				<span class=\"btn-spacing btn btn-small\">Choose an Image</span>\n			</div>\n		");
  return buffer;
  }

function program4(depth0,data) {
  
  
  data.buffer.push("\n    	<button type=\"submit\" class=\"btn btn-primary\">Save</button>\n		");
  }

function program6(depth0,data) {
  
  var buffer = '', hashTypes;
  data.buffer.push("\n			<button ");
  hashTypes = {'on': "STRING"};
  data.buffer.push(escapeExpression(helpers.action.call(depth0, "edit", {hash:{
    'on': ("click")
  },contexts:[depth0],types:["STRING"],hashTypes:hashTypes,data:data})));
  data.buffer.push(" class=\"btn btn-primary\">Edit</button>\n		");
  return buffer;
  }

  data.buffer.push("<form class=\"form-horizontal\" ");
  hashTypes = {'on': "STRING"};
  data.buffer.push(escapeExpression(helpers.action.call(depth0, "save", {hash:{
    'on': ("submit")
  },contexts:[depth0],types:["ID"],hashTypes:hashTypes,data:data})));
  data.buffer.push(">\n	<legend>Beverage</legend>\n	");
  hashTypes = {};
  stack1 = helpers.view.call(depth0, "Ember.View", {hash:{},inverse:self.noop,fn:self.program(1, program1, data),contexts:[depth0],types:["ID"],hashTypes:hashTypes,data:data});
  if(stack1 || stack1 === 0) { data.buffer.push(stack1); }
  data.buffer.push("\n  <div class=\"control-group\">\n    <label class=\"control-label\" for=\"name-field\">\n			<strong>Name</strong>\n		</label>\n    <div class=\"controls\">\n	    ");
  hashTypes = {'valueBinding': "STRING",'id': "STRING",'disabledBinding': "STRING"};
  data.buffer.push(escapeExpression(helpers.view.call(depth0, "Ember.TextField", {hash:{
    'valueBinding': ("name"),
    'id': ("name-field"),
    'disabledBinding': ("isEditingDisabled")
  },contexts:[depth0],types:["ID"],hashTypes:hashTypes,data:data})));
  data.buffer.push("\n    </div>\n  </div>\n  <div class=\"control-group\">\n    <label class=\"control-label strong\" for=\"location-field\">\n			<strong>ABV</strong>\n		</label>\n    <div class=\"controls\">\n			");
  hashTypes = {'valueBinding': "STRING",'id': "STRING",'disabledBinding': "STRING"};
  data.buffer.push(escapeExpression(helpers.view.call(depth0, "Ember.TextField", {hash:{
    'valueBinding': ("abv"),
    'id': ("ibu-field"),
    'disabledBinding': ("isEditingDisabled")
  },contexts:[depth0],types:["ID"],hashTypes:hashTypes,data:data})));
  data.buffer.push("\n    </div>\n  </div>\n  <div class=\"control-group\">\n    <label class=\"control-label\" for=\"established-field\">\n			<strong>IBU</strong>\n		</label>\n    <div class=\"controls\">\n	    ");
  hashTypes = {'valueBinding': "STRING",'id': "STRING",'disabledBinding': "STRING"};
  data.buffer.push(escapeExpression(helpers.view.call(depth0, "Ember.TextField", {hash:{
    'valueBinding': ("ibu"),
    'id': ("abv-field"),
    'disabledBinding': ("isEditingDisabled")
  },contexts:[depth0],types:["ID"],hashTypes:hashTypes,data:data})));
  data.buffer.push("\n    </div>\n  </div>\n  <p>\n		");
  hashTypes = {};
  stack1 = helpers['if'].call(depth0, "isEditing", {hash:{},inverse:self.program(6, program6, data),fn:self.program(4, program4, data),contexts:[depth0],types:["ID"],hashTypes:hashTypes,data:data});
  if(stack1 || stack1 === 0) { data.buffer.push(stack1); }
  data.buffer.push("\n  </p>\n	");
  hashTypes = {};
  options = {hash:{},contexts:[depth0],types:["ID"],hashTypes:hashTypes,data:data};
  data.buffer.push(escapeExpression(((stack1 = helpers.outlet),stack1 ? stack1.call(depth0, "beverages", options) : helperMissing.call(depth0, "outlet", "beverages", options))));
  data.buffer.push("\n</form>\n");
  return buffer;
  
});

Ember.TEMPLATES['beverage_type'] = Ember.Handlebars.template(function anonymous(Handlebars,depth0,helpers,partials,data) {
this.compilerInfo = [2,'>= 1.0.0-rc.3'];
helpers = helpers || Ember.Handlebars.helpers; data = data || {};
  var buffer = '', stack1, hashTypes, escapeExpression=this.escapeExpression, self=this;

function program1(depth0,data) {
  
  var buffer = '', stack1, hashTypes;
  data.buffer.push("\n		");
  hashTypes = {'name': "STRING"};
  stack1 = helpers.view.call(depth0, "App.ImageUploadView", {hash:{
    'name': ("image")
  },inverse:self.noop,fn:self.program(2, program2, data),contexts:[depth0],types:["ID"],hashTypes:hashTypes,data:data});
  if(stack1 || stack1 === 0) { data.buffer.push(stack1); }
  data.buffer.push("\n	");
  return buffer;
  }
function program2(depth0,data) {
  
  var buffer = '', hashTypes;
  data.buffer.push("\n			<div class=\"controls\">\n				");
  hashTypes = {'width': "STRING",'height': "STRING",'srcBinding': "STRING",'class': "STRING"};
  data.buffer.push(escapeExpression(helpers.view.call(depth0, "view.previewImageView", {hash:{
    'width': ("200"),
    'height': ("100"),
    'srcBinding': ("image"),
    'class': ("img-polaroid")
  },contexts:[depth0],types:["ID"],hashTypes:hashTypes,data:data})));
  data.buffer.push("\n			</div>\n			<div ");
  hashTypes = {'class': "STRING"};
  data.buffer.push(escapeExpression(helpers.bindAttr.call(depth0, {hash:{
    'class': (":controls :file-wrapper isEditingDisabled:transparent:active")
  },contexts:[],types:[],hashTypes:hashTypes,data:data})));
  data.buffer.push(">\n				");
  hashTypes = {};
  data.buffer.push(escapeExpression(helpers.view.call(depth0, "view.fileField", {hash:{},contexts:[depth0],types:["ID"],hashTypes:hashTypes,data:data})));
  data.buffer.push("\n				<span class=\"btn-spacing btn btn-small\">Choose an Image</span>\n			</div>\n		");
  return buffer;
  }

function program4(depth0,data) {
  
  
  data.buffer.push("\n    	<button type=\"submit\" class=\"btn btn-primary\">Save</button>\n		");
  }

function program6(depth0,data) {
  
  var buffer = '', hashTypes;
  data.buffer.push("\n			<button ");
  hashTypes = {'on': "STRING"};
  data.buffer.push(escapeExpression(helpers.action.call(depth0, "edit", {hash:{
    'on': ("click")
  },contexts:[depth0],types:["STRING"],hashTypes:hashTypes,data:data})));
  data.buffer.push(" class=\"btn btn-primary\">Edit</button>\n		");
  return buffer;
  }

  data.buffer.push("<form class=\"form-horizontal\" ");
  hashTypes = {'on': "STRING"};
  data.buffer.push(escapeExpression(helpers.action.call(depth0, "save", {hash:{
    'on': ("submit")
  },contexts:[depth0],types:["ID"],hashTypes:hashTypes,data:data})));
  data.buffer.push(">\n	<legend>Beverage Type</legend>\n	");
  hashTypes = {};
  stack1 = helpers.view.call(depth0, "Ember.View", {hash:{},inverse:self.noop,fn:self.program(1, program1, data),contexts:[depth0],types:["ID"],hashTypes:hashTypes,data:data});
  if(stack1 || stack1 === 0) { data.buffer.push(stack1); }
  data.buffer.push("\n  <div class=\"control-group\">\n    <label class=\"control-label\" for=\"name-field\">\n			<strong>Name</strong>\n		</label>\n    <div class=\"controls\">\n	    ");
  hashTypes = {'valueBinding': "STRING",'id': "STRING",'disabledBinding': "STRING"};
  data.buffer.push(escapeExpression(helpers.view.call(depth0, "Ember.TextField", {hash:{
    'valueBinding': ("name"),
    'id': ("name-field"),
    'disabledBinding': ("isEditingDisabled")
  },contexts:[depth0],types:["ID"],hashTypes:hashTypes,data:data})));
  data.buffer.push("\n    </div>\n  </div>\n  <div class=\"control-group\">\n    <label class=\"control-label strong\" for=\"description-field\">\n			<strong>Description</strong>\n		</label>\n    <div class=\"controls\">\n			");
  hashTypes = {'valueBinding': "STRING",'id': "STRING",'disabledBinding': "STRING"};
  data.buffer.push(escapeExpression(helpers.view.call(depth0, "Ember.TextArea", {hash:{
    'valueBinding': ("description"),
    'id': ("description-field"),
    'disabledBinding': ("isEditingDisabled")
  },contexts:[depth0],types:["ID"],hashTypes:hashTypes,data:data})));
  data.buffer.push("\n    </div>\n  </div>\n  <p>\n		");
  hashTypes = {};
  stack1 = helpers['if'].call(depth0, "isEditing", {hash:{},inverse:self.program(6, program6, data),fn:self.program(4, program4, data),contexts:[depth0],types:["ID"],hashTypes:hashTypes,data:data});
  if(stack1 || stack1 === 0) { data.buffer.push(stack1); }
  data.buffer.push("\n  </p>\n</form>\n");
  return buffer;
  
});

Ember.TEMPLATES['beverage_types'] = Ember.Handlebars.template(function anonymous(Handlebars,depth0,helpers,partials,data) {
this.compilerInfo = [2,'>= 1.0.0-rc.3'];
helpers = helpers || Ember.Handlebars.helpers; data = data || {};
  var buffer = '', stack1, stack2, hashTypes, options, escapeExpression=this.escapeExpression, self=this, helperMissing=helpers.helperMissing;

function program1(depth0,data) {
  
  
  data.buffer.push("New Beverage Type");
  }

function program3(depth0,data) {
  
  var buffer = '', stack1, stack2, hashTypes, options;
  data.buffer.push("\n    <tr>\n	    <td>\n				<img ");
  hashTypes = {'src': "STRING"};
  data.buffer.push(escapeExpression(helpers.bindAttr.call(depth0, {hash:{
    'src': ("beverage_type.image")
  },contexts:[],types:[],hashTypes:hashTypes,data:data})));
  data.buffer.push(" width=48 height=48/>\n			</td>\n      <td>");
  hashTypes = {};
  data.buffer.push(escapeExpression(helpers._triageMustache.call(depth0, "beverage_type.name", {hash:{},contexts:[depth0],types:["ID"],hashTypes:hashTypes,data:data})));
  data.buffer.push("</td>\n      <td>");
  hashTypes = {};
  data.buffer.push(escapeExpression(helpers._triageMustache.call(depth0, "beverage_type.description", {hash:{},contexts:[depth0],types:["ID"],hashTypes:hashTypes,data:data})));
  data.buffer.push("</td>\n      <td>");
  hashTypes = {};
  options = {hash:{},inverse:self.noop,fn:self.program(4, program4, data),contexts:[depth0,depth0],types:["STRING","ID"],hashTypes:hashTypes,data:data};
  stack2 = ((stack1 = helpers.linkTo),stack1 ? stack1.call(depth0, "beverage_type", "beverage_type", options) : helperMissing.call(depth0, "linkTo", "beverage_type", "beverage_type", options));
  if(stack2 || stack2 === 0) { data.buffer.push(stack2); }
  data.buffer.push("</td>\n    </tr>\n    ");
  return buffer;
  }
function program4(depth0,data) {
  
  
  data.buffer.push("view");
  }

  data.buffer.push("<legend>Beverage Types</legend>\n");
  hashTypes = {'class': "STRING"};
  options = {hash:{
    'class': ("btn-spacing btn btn-small")
  },inverse:self.noop,fn:self.program(1, program1, data),contexts:[depth0],types:["STRING"],hashTypes:hashTypes,data:data};
  stack2 = ((stack1 = helpers.linkTo),stack1 ? stack1.call(depth0, "new_beverage_type", options) : helperMissing.call(depth0, "linkTo", "new_beverage_type", options));
  if(stack2 || stack2 === 0) { data.buffer.push(stack2); }
  data.buffer.push("\n<table class=\"table table-striped table-bordered\">\n	<col style=\"width:48px\">\n	<col>\n	<col>\n	<col>\n  <thead>\n	  <th>Image</th>\n    <th>Name</th>\n    <th>Description</th>\n  </thead>\n  <tbody>\n    ");
  hashTypes = {};
  stack2 = helpers.each.call(depth0, "beverage_type", "in", "controller", {hash:{},inverse:self.noop,fn:self.program(3, program3, data),contexts:[depth0,depth0,depth0],types:["ID","ID","ID"],hashTypes:hashTypes,data:data});
  if(stack2 || stack2 === 0) { data.buffer.push(stack2); }
  data.buffer.push("\n  </tbody>\n</table>\n\n\n\n");
  return buffer;
  
});

Ember.TEMPLATES['beverages'] = Ember.Handlebars.template(function anonymous(Handlebars,depth0,helpers,partials,data) {
this.compilerInfo = [2,'>= 1.0.0-rc.3'];
helpers = helpers || Ember.Handlebars.helpers; data = data || {};
  var buffer = '', stack1, stack2, hashTypes, options, escapeExpression=this.escapeExpression, self=this, helperMissing=helpers.helperMissing;

function program1(depth0,data) {
  
  
  data.buffer.push("New Beverage");
  }

function program3(depth0,data) {
  
  var buffer = '', stack1, stack2, hashTypes, options;
  data.buffer.push("\n    <tr>\n	    <td>\n				<img ");
  hashTypes = {'src': "STRING"};
  data.buffer.push(escapeExpression(helpers.bindAttr.call(depth0, {hash:{
    'src': ("beverage.image")
  },contexts:[],types:[],hashTypes:hashTypes,data:data})));
  data.buffer.push(" width=48 height=48 class=\"img-rounded\"/>\n			</td>\n      <td>");
  hashTypes = {};
  data.buffer.push(escapeExpression(helpers._triageMustache.call(depth0, "beverage.name", {hash:{},contexts:[depth0],types:["ID"],hashTypes:hashTypes,data:data})));
  data.buffer.push("</td>\n      <td>");
  hashTypes = {};
  data.buffer.push(escapeExpression(helpers._triageMustache.call(depth0, "beverage.abv", {hash:{},contexts:[depth0],types:["ID"],hashTypes:hashTypes,data:data})));
  data.buffer.push("</td>\n      <td>");
  hashTypes = {};
  data.buffer.push(escapeExpression(helpers._triageMustache.call(depth0, "beverage.ibu", {hash:{},contexts:[depth0],types:["ID"],hashTypes:hashTypes,data:data})));
  data.buffer.push("</td>\n      <td>");
  hashTypes = {};
  options = {hash:{},inverse:self.noop,fn:self.program(4, program4, data),contexts:[depth0,depth0],types:["STRING","ID"],hashTypes:hashTypes,data:data};
  stack2 = ((stack1 = helpers.linkTo),stack1 ? stack1.call(depth0, "beverage", "beverage", options) : helperMissing.call(depth0, "linkTo", "beverage", "beverage", options));
  if(stack2 || stack2 === 0) { data.buffer.push(stack2); }
  data.buffer.push("</td>\n    </tr>\n    ");
  return buffer;
  }
function program4(depth0,data) {
  
  
  data.buffer.push("view");
  }

  data.buffer.push("<h2>Beverages</h2>\n");
  hashTypes = {'class': "STRING"};
  options = {hash:{
    'class': ("btn-spacing btn btn-small")
  },inverse:self.noop,fn:self.program(1, program1, data),contexts:[depth0],types:["STRING"],hashTypes:hashTypes,data:data};
  stack2 = ((stack1 = helpers.linkTo),stack1 ? stack1.call(depth0, "new_beverage", options) : helperMissing.call(depth0, "linkTo", "new_beverage", options));
  if(stack2 || stack2 === 0) { data.buffer.push(stack2); }
  data.buffer.push("\n<table class=\"table table-striped table-bordered\">\n	<col style=\"width:48px\">\n	<col>\n	<col>\n	<col>\n  <thead>\n    <th>Image</th>\n    <th>Name</th>\n    <th>ABV</th>\n    <th>IBU</th>\n  </thead>\n  <tbody>\n    ");
  hashTypes = {};
  stack2 = helpers.each.call(depth0, "beverage", "in", "controller", {hash:{},inverse:self.noop,fn:self.program(3, program3, data),contexts:[depth0,depth0,depth0],types:["ID","ID","ID"],hashTypes:hashTypes,data:data});
  if(stack2 || stack2 === 0) { data.buffer.push(stack2); }
  data.buffer.push("\n  </tbody>\n</table>\n");
  hashTypes = {};
  options = {hash:{},contexts:[depth0],types:["ID"],hashTypes:hashTypes,data:data};
  data.buffer.push(escapeExpression(((stack1 = helpers.outlet),stack1 ? stack1.call(depth0, "beverages", options) : helperMissing.call(depth0, "outlet", "beverages", options))));
  data.buffer.push("\n\n\n");
  return buffer;
  
});

Ember.TEMPLATES['edit_tap'] = Ember.Handlebars.template(function anonymous(Handlebars,depth0,helpers,partials,data) {
this.compilerInfo = [2,'>= 1.0.0-rc.3'];
helpers = helpers || Ember.Handlebars.helpers; data = data || {};
  var buffer = '', hashTypes, escapeExpression=this.escapeExpression;


  data.buffer.push("<h2>Tap</h2>\n\n<form ");
  hashTypes = {'on': "STRING"};
  data.buffer.push(escapeExpression(helpers.action.call(depth0, "save", {hash:{
    'on': ("submit")
  },contexts:[depth0],types:["ID"],hashTypes:hashTypes,data:data})));
  data.buffer.push(">\n  \n  <p>\n    <label for=\"position\">Position</label><br>\n    ");
  hashTypes = {'valueBinding': "STRING",'id': "STRING"};
  data.buffer.push(escapeExpression(helpers.view.call(depth0, "Ember.TextField", {hash:{
    'valueBinding': ("position"),
    'id': ("position")
  },contexts:[depth0],types:["ID"],hashTypes:hashTypes,data:data})));
  data.buffer.push("\n  </p>\n  \n  <p>\n    <button type=\"submit\">Save</button>\n  </p>\n\n</form>\n\n");
  return buffer;
  
});

Ember.TEMPLATES['index'] = Ember.Handlebars.template(function anonymous(Handlebars,depth0,helpers,partials,data) {
this.compilerInfo = [2,'>= 1.0.0-rc.3'];
helpers = helpers || Ember.Handlebars.helpers; data = data || {};
  


  data.buffer.push("<div class=\"container\">\n<h2>Index</h2>\n</div>\n");
  
});

Ember.TEMPLATES['producer'] = Ember.Handlebars.template(function anonymous(Handlebars,depth0,helpers,partials,data) {
this.compilerInfo = [2,'>= 1.0.0-rc.3'];
helpers = helpers || Ember.Handlebars.helpers; data = data || {};
  var buffer = '', stack1, hashTypes, escapeExpression=this.escapeExpression, self=this;

function program1(depth0,data) {
  
  var buffer = '', stack1, hashTypes;
  data.buffer.push("\n		");
  hashTypes = {'name': "STRING"};
  stack1 = helpers.view.call(depth0, "App.ImageUploadView", {hash:{
    'name': ("image")
  },inverse:self.noop,fn:self.program(2, program2, data),contexts:[depth0],types:["ID"],hashTypes:hashTypes,data:data});
  if(stack1 || stack1 === 0) { data.buffer.push(stack1); }
  data.buffer.push("\n	");
  return buffer;
  }
function program2(depth0,data) {
  
  var buffer = '', hashTypes;
  data.buffer.push("\n			<div class=\"controls\">\n				");
  hashTypes = {'width': "STRING",'height': "STRING",'srcBinding': "STRING",'class': "STRING"};
  data.buffer.push(escapeExpression(helpers.view.call(depth0, "view.previewImageView", {hash:{
    'width': ("200"),
    'height': ("100"),
    'srcBinding': ("image"),
    'class': ("img-polaroid")
  },contexts:[depth0],types:["ID"],hashTypes:hashTypes,data:data})));
  data.buffer.push("\n			</div>\n			<div ");
  hashTypes = {'class': "STRING"};
  data.buffer.push(escapeExpression(helpers.bindAttr.call(depth0, {hash:{
    'class': (":controls :file-wrapper isEditingDisabled:transparent:active")
  },contexts:[],types:[],hashTypes:hashTypes,data:data})));
  data.buffer.push(">\n				");
  hashTypes = {};
  data.buffer.push(escapeExpression(helpers.view.call(depth0, "view.fileField", {hash:{},contexts:[depth0],types:["ID"],hashTypes:hashTypes,data:data})));
  data.buffer.push("\n				<span class=\"btn-spacing btn btn-small\">Choose an Image</span>\n			</div>\n		");
  return buffer;
  }

function program4(depth0,data) {
  
  
  data.buffer.push("\n    	<button type=\"submit\" class=\"btn btn-primary\">Save</button>\n		");
  }

function program6(depth0,data) {
  
  var buffer = '', hashTypes;
  data.buffer.push("\n			<button ");
  hashTypes = {'on': "STRING"};
  data.buffer.push(escapeExpression(helpers.action.call(depth0, "edit", {hash:{
    'on': ("click")
  },contexts:[depth0],types:["STRING"],hashTypes:hashTypes,data:data})));
  data.buffer.push(" class=\"btn btn-primary\">Edit</button>\n		");
  return buffer;
  }

  data.buffer.push("<form class=\"form-horizontal\" ");
  hashTypes = {'on': "STRING"};
  data.buffer.push(escapeExpression(helpers.action.call(depth0, "save", {hash:{
    'on': ("submit")
  },contexts:[depth0],types:["ID"],hashTypes:hashTypes,data:data})));
  data.buffer.push(">\n	<legend>Brewery</legend>\n	");
  hashTypes = {};
  stack1 = helpers.view.call(depth0, "Ember.View", {hash:{},inverse:self.noop,fn:self.program(1, program1, data),contexts:[depth0],types:["ID"],hashTypes:hashTypes,data:data});
  if(stack1 || stack1 === 0) { data.buffer.push(stack1); }
  data.buffer.push("\n  <div class=\"control-group\">\n    <label class=\"control-label\" for=\"name-field\">\n			<strong>Name</strong>\n		</label>\n    <div class=\"controls\">\n	    ");
  hashTypes = {'valueBinding': "STRING",'id': "STRING",'disabledBinding': "STRING"};
  data.buffer.push(escapeExpression(helpers.view.call(depth0, "Ember.TextField", {hash:{
    'valueBinding': ("name"),
    'id': ("name-field"),
    'disabledBinding': ("isEditingDisabled")
  },contexts:[depth0],types:["ID"],hashTypes:hashTypes,data:data})));
  data.buffer.push("\n    </div>\n  </div>\n  <div class=\"control-group\">\n    <label class=\"control-label strong\" for=\"location-field\">\n			<strong>Location</strong>\n		</label>\n    <div class=\"controls\">\n			");
  hashTypes = {'valueBinding': "STRING",'id': "STRING",'disabledBinding': "STRING"};
  data.buffer.push(escapeExpression(helpers.view.call(depth0, "Ember.TextField", {hash:{
    'valueBinding': ("location"),
    'id': ("location-field"),
    'disabledBinding': ("isEditingDisabled")
  },contexts:[depth0],types:["ID"],hashTypes:hashTypes,data:data})));
  data.buffer.push("\n    </div>\n  </div>\n  <div class=\"control-group\">\n    <label class=\"control-label\" for=\"established-field\">\n			<strong>Established</strong>\n		</label>\n    <div class=\"controls\">\n	    ");
  hashTypes = {'valueBinding': "STRING",'id': "STRING",'disabledBinding': "STRING"};
  data.buffer.push(escapeExpression(helpers.view.call(depth0, "Ember.TextField", {hash:{
    'valueBinding': ("established"),
    'id': ("established-field"),
    'disabledBinding': ("isEditingDisabled")
  },contexts:[depth0],types:["ID"],hashTypes:hashTypes,data:data})));
  data.buffer.push("\n    </div>\n  </div>\n  <p>\n		");
  hashTypes = {};
  stack1 = helpers['if'].call(depth0, "isEditing", {hash:{},inverse:self.program(6, program6, data),fn:self.program(4, program4, data),contexts:[depth0],types:["ID"],hashTypes:hashTypes,data:data});
  if(stack1 || stack1 === 0) { data.buffer.push(stack1); }
  data.buffer.push("\n  </p>\n</form>\n");
  return buffer;
  
});

Ember.TEMPLATES['producers'] = Ember.Handlebars.template(function anonymous(Handlebars,depth0,helpers,partials,data) {
this.compilerInfo = [2,'>= 1.0.0-rc.3'];
helpers = helpers || Ember.Handlebars.helpers; data = data || {};
  var buffer = '', stack1, stack2, hashTypes, options, escapeExpression=this.escapeExpression, self=this, helperMissing=helpers.helperMissing;

function program1(depth0,data) {
  
  
  data.buffer.push("New Brewery");
  }

function program3(depth0,data) {
  
  var buffer = '', stack1, stack2, hashTypes, options;
  data.buffer.push("\n    <tr>\n	    <td>\n				<img ");
  hashTypes = {'src': "STRING"};
  data.buffer.push(escapeExpression(helpers.bindAttr.call(depth0, {hash:{
    'src': ("producer.image")
  },contexts:[],types:[],hashTypes:hashTypes,data:data})));
  data.buffer.push(" width=48 height=48/>\n			</td>\n      <td>");
  hashTypes = {};
  data.buffer.push(escapeExpression(helpers._triageMustache.call(depth0, "producer.name", {hash:{},contexts:[depth0],types:["ID"],hashTypes:hashTypes,data:data})));
  data.buffer.push("</td>\n      <td>");
  hashTypes = {};
  data.buffer.push(escapeExpression(helpers._triageMustache.call(depth0, "producer.location", {hash:{},contexts:[depth0],types:["ID"],hashTypes:hashTypes,data:data})));
  data.buffer.push("</td>\n      <td>");
  hashTypes = {};
  data.buffer.push(escapeExpression(helpers._triageMustache.call(depth0, "producer.established", {hash:{},contexts:[depth0],types:["ID"],hashTypes:hashTypes,data:data})));
  data.buffer.push("</td>\n      <td>");
  hashTypes = {};
  options = {hash:{},inverse:self.noop,fn:self.program(4, program4, data),contexts:[depth0,depth0],types:["STRING","ID"],hashTypes:hashTypes,data:data};
  stack2 = ((stack1 = helpers.linkTo),stack1 ? stack1.call(depth0, "producer", "producer", options) : helperMissing.call(depth0, "linkTo", "producer", "producer", options));
  if(stack2 || stack2 === 0) { data.buffer.push(stack2); }
  data.buffer.push("</td>\n    </tr>\n    ");
  return buffer;
  }
function program4(depth0,data) {
  
  
  data.buffer.push("view");
  }

  data.buffer.push("<legend>Breweries</legend>\n");
  hashTypes = {'class': "STRING"};
  options = {hash:{
    'class': ("btn-spacing btn btn-small")
  },inverse:self.noop,fn:self.program(1, program1, data),contexts:[depth0],types:["STRING"],hashTypes:hashTypes,data:data};
  stack2 = ((stack1 = helpers.linkTo),stack1 ? stack1.call(depth0, "new_producer", options) : helperMissing.call(depth0, "linkTo", "new_producer", options));
  if(stack2 || stack2 === 0) { data.buffer.push(stack2); }
  data.buffer.push("\n<table class=\"table table-striped table-bordered\">\n	<col style=\"width:48px\">\n	<col>\n	<col>\n	<col>\n  <thead>\n	  <th>Image</th>\n    <th>Name</th>\n    <th>Location</th>\n    <th>Established</th>\n  </thead>\n  <tbody>\n    ");
  hashTypes = {};
  stack2 = helpers.each.call(depth0, "producer", "in", "controller", {hash:{},inverse:self.noop,fn:self.program(3, program3, data),contexts:[depth0,depth0,depth0],types:["ID","ID","ID"],hashTypes:hashTypes,data:data});
  if(stack2 || stack2 === 0) { data.buffer.push(stack2); }
  data.buffer.push("\n  </tbody>\n</table>\n\n\n");
  return buffer;
  
});

Ember.TEMPLATES['style'] = Ember.Handlebars.template(function anonymous(Handlebars,depth0,helpers,partials,data) {
this.compilerInfo = [2,'>= 1.0.0-rc.3'];
helpers = helpers || Ember.Handlebars.helpers; data = data || {};
  var buffer = '', stack1, hashTypes, escapeExpression=this.escapeExpression, self=this;

function program1(depth0,data) {
  
  var buffer = '', stack1, hashTypes;
  data.buffer.push("\n		");
  hashTypes = {'name': "STRING"};
  stack1 = helpers.view.call(depth0, "App.ImageUploadView", {hash:{
    'name': ("image")
  },inverse:self.noop,fn:self.program(2, program2, data),contexts:[depth0],types:["ID"],hashTypes:hashTypes,data:data});
  if(stack1 || stack1 === 0) { data.buffer.push(stack1); }
  data.buffer.push("\n	");
  return buffer;
  }
function program2(depth0,data) {
  
  var buffer = '', hashTypes;
  data.buffer.push("\n			<div class=\"controls\">\n				");
  hashTypes = {'width': "STRING",'height': "STRING",'srcBinding': "STRING",'class': "STRING"};
  data.buffer.push(escapeExpression(helpers.view.call(depth0, "view.previewImageView", {hash:{
    'width': ("200"),
    'height': ("100"),
    'srcBinding': ("image"),
    'class': ("img-polaroid")
  },contexts:[depth0],types:["ID"],hashTypes:hashTypes,data:data})));
  data.buffer.push("\n			</div>\n			<div ");
  hashTypes = {'class': "STRING"};
  data.buffer.push(escapeExpression(helpers.bindAttr.call(depth0, {hash:{
    'class': (":controls :file-wrapper isEditingDisabled:transparent:active")
  },contexts:[],types:[],hashTypes:hashTypes,data:data})));
  data.buffer.push(">\n				");
  hashTypes = {};
  data.buffer.push(escapeExpression(helpers.view.call(depth0, "view.fileField", {hash:{},contexts:[depth0],types:["ID"],hashTypes:hashTypes,data:data})));
  data.buffer.push("\n				<span class=\"btn-spacing btn btn-small\">Choose an Image</span>\n			</div>\n		");
  return buffer;
  }

function program4(depth0,data) {
  
  
  data.buffer.push("\n    	<button type=\"submit\" class=\"btn btn-primary\">Save</button>\n		");
  }

function program6(depth0,data) {
  
  var buffer = '', hashTypes;
  data.buffer.push("\n			<button ");
  hashTypes = {'on': "STRING"};
  data.buffer.push(escapeExpression(helpers.action.call(depth0, "edit", {hash:{
    'on': ("click")
  },contexts:[depth0],types:["STRING"],hashTypes:hashTypes,data:data})));
  data.buffer.push(" class=\"btn btn-primary\">Edit</button>\n		");
  return buffer;
  }

  data.buffer.push("<form class=\"form-horizontal\" ");
  hashTypes = {'on': "STRING"};
  data.buffer.push(escapeExpression(helpers.action.call(depth0, "save", {hash:{
    'on': ("submit")
  },contexts:[depth0],types:["ID"],hashTypes:hashTypes,data:data})));
  data.buffer.push(">\n	<legend>Beverage Style</legend>\n	");
  hashTypes = {};
  stack1 = helpers.view.call(depth0, "Ember.View", {hash:{},inverse:self.noop,fn:self.program(1, program1, data),contexts:[depth0],types:["ID"],hashTypes:hashTypes,data:data});
  if(stack1 || stack1 === 0) { data.buffer.push(stack1); }
  data.buffer.push("\n  <div class=\"control-group\">\n    <label class=\"control-label\" for=\"name-field\">\n			<strong>Name</strong>\n		</label>\n    <div class=\"controls\">\n	    ");
  hashTypes = {'valueBinding': "STRING",'id': "STRING",'disabledBinding': "STRING"};
  data.buffer.push(escapeExpression(helpers.view.call(depth0, "Ember.TextField", {hash:{
    'valueBinding': ("name"),
    'id': ("name-field"),
    'disabledBinding': ("isEditingDisabled")
  },contexts:[depth0],types:["ID"],hashTypes:hashTypes,data:data})));
  data.buffer.push("\n    </div>\n  </div>\n  <div class=\"control-group\">\n    <label class=\"control-label\" for=\"description-field\">\n			<strong>Description</strong>\n		</label>\n    <div class=\"controls\">\n	    ");
  hashTypes = {'valueBinding': "STRING",'rows': "INTEGER",'id': "STRING",'disabledBinding': "STRING"};
  data.buffer.push(escapeExpression(helpers.view.call(depth0, "Ember.TextArea", {hash:{
    'valueBinding': ("description"),
    'rows': (2),
    'id': ("description-field"),
    'disabledBinding': ("isEditingDisabled")
  },contexts:[depth0],types:["ID"],hashTypes:hashTypes,data:data})));
  data.buffer.push("\n    </div>\n  </div>\n  <p>\n		");
  hashTypes = {};
  stack1 = helpers['if'].call(depth0, "isEditing", {hash:{},inverse:self.program(6, program6, data),fn:self.program(4, program4, data),contexts:[depth0],types:["ID"],hashTypes:hashTypes,data:data});
  if(stack1 || stack1 === 0) { data.buffer.push(stack1); }
  data.buffer.push("\n  </p>\n</form>\n");
  return buffer;
  
});

Ember.TEMPLATES['styles'] = Ember.Handlebars.template(function anonymous(Handlebars,depth0,helpers,partials,data) {
this.compilerInfo = [2,'>= 1.0.0-rc.3'];
helpers = helpers || Ember.Handlebars.helpers; data = data || {};
  var buffer = '', stack1, stack2, hashTypes, options, escapeExpression=this.escapeExpression, self=this, helperMissing=helpers.helperMissing;

function program1(depth0,data) {
  
  
  data.buffer.push("New Beverage Style");
  }

function program3(depth0,data) {
  
  var buffer = '', stack1, stack2, hashTypes, options;
  data.buffer.push("\n    <tr>\n	    <td>\n				<img ");
  hashTypes = {'src': "STRING"};
  data.buffer.push(escapeExpression(helpers.bindAttr.call(depth0, {hash:{
    'src': ("style.image")
  },contexts:[],types:[],hashTypes:hashTypes,data:data})));
  data.buffer.push(" width=48 height=48/>\n			</td>\n      <td>");
  hashTypes = {};
  data.buffer.push(escapeExpression(helpers._triageMustache.call(depth0, "style.name", {hash:{},contexts:[depth0],types:["ID"],hashTypes:hashTypes,data:data})));
  data.buffer.push("</td>\n      <td>");
  hashTypes = {};
  data.buffer.push(escapeExpression(helpers._triageMustache.call(depth0, "style.description", {hash:{},contexts:[depth0],types:["ID"],hashTypes:hashTypes,data:data})));
  data.buffer.push("</td>\n      <td>");
  hashTypes = {};
  options = {hash:{},inverse:self.noop,fn:self.program(4, program4, data),contexts:[depth0,depth0],types:["STRING","ID"],hashTypes:hashTypes,data:data};
  stack2 = ((stack1 = helpers.linkTo),stack1 ? stack1.call(depth0, "style", "style", options) : helperMissing.call(depth0, "linkTo", "style", "style", options));
  if(stack2 || stack2 === 0) { data.buffer.push(stack2); }
  data.buffer.push("</td>\n    </tr>\n    ");
  return buffer;
  }
function program4(depth0,data) {
  
  
  data.buffer.push("view");
  }

  data.buffer.push("<legend>Beverage Styles</legend>\n");
  hashTypes = {'class': "STRING"};
  options = {hash:{
    'class': ("btn-spacing btn btn-small")
  },inverse:self.noop,fn:self.program(1, program1, data),contexts:[depth0],types:["STRING"],hashTypes:hashTypes,data:data};
  stack2 = ((stack1 = helpers.linkTo),stack1 ? stack1.call(depth0, "new_style", options) : helperMissing.call(depth0, "linkTo", "new_style", options));
  if(stack2 || stack2 === 0) { data.buffer.push(stack2); }
  data.buffer.push("\n<table class=\"table table-striped table-bordered\">\n	<col style=\"width:48px\">\n	<col>\n	<col>\n	<col>\n  <thead>\n	  <th>Image</th>\n    <th>Name</th>\n    <th>Description</th>\n  </thead>\n  <tbody>\n    ");
  hashTypes = {};
  stack2 = helpers.each.call(depth0, "beverage_style", "in", "controller", {hash:{},inverse:self.noop,fn:self.program(3, program3, data),contexts:[depth0,depth0,depth0],types:["ID","ID","ID"],hashTypes:hashTypes,data:data});
  if(stack2 || stack2 === 0) { data.buffer.push(stack2); }
  data.buffer.push("\n  </tbody>\n</table>\n\n\n\n");
  return buffer;
  
});

Ember.TEMPLATES['tap'] = Ember.Handlebars.template(function anonymous(Handlebars,depth0,helpers,partials,data) {
this.compilerInfo = [2,'>= 1.0.0-rc.3'];
helpers = helpers || Ember.Handlebars.helpers; data = data || {};
  var buffer = '', stack1, stack2, hashTypes, options, escapeExpression=this.escapeExpression, self=this, helperMissing=helpers.helperMissing;

function program1(depth0,data) {
  
  
  data.buffer.push("←All Taps");
  }

function program3(depth0,data) {
  
  
  data.buffer.push("Edit");
  }

  data.buffer.push("<h2>Tap</h2>\n\n<p>\n  <b>Position:</b> ");
  hashTypes = {};
  data.buffer.push(escapeExpression(helpers._triageMustache.call(depth0, "position", {hash:{},contexts:[depth0],types:["ID"],hashTypes:hashTypes,data:data})));
  data.buffer.push("\n</p>\n\n");
  hashTypes = {};
  options = {hash:{},inverse:self.noop,fn:self.program(1, program1, data),contexts:[depth0],types:["STRING"],hashTypes:hashTypes,data:data};
  stack2 = ((stack1 = helpers.linkTo),stack1 ? stack1.call(depth0, "taps", options) : helperMissing.call(depth0, "linkTo", "taps", options));
  if(stack2 || stack2 === 0) { data.buffer.push(stack2); }
  data.buffer.push("\n");
  hashTypes = {};
  options = {hash:{},inverse:self.noop,fn:self.program(3, program3, data),contexts:[depth0,depth0],types:["STRING","ID"],hashTypes:hashTypes,data:data};
  stack2 = ((stack1 = helpers.linkTo),stack1 ? stack1.call(depth0, "edit_tap", "model", options) : helperMissing.call(depth0, "linkTo", "edit_tap", "model", options));
  if(stack2 || stack2 === 0) { data.buffer.push(stack2); }
  data.buffer.push("\n<a href=\"#\" ");
  hashTypes = {};
  data.buffer.push(escapeExpression(helpers.action.call(depth0, "destroy", {hash:{},contexts:[depth0],types:["STRING"],hashTypes:hashTypes,data:data})));
  data.buffer.push(">Destroy</a>\n");
  return buffer;
  
});

Ember.TEMPLATES['taps'] = Ember.Handlebars.template(function anonymous(Handlebars,depth0,helpers,partials,data) {
this.compilerInfo = [2,'>= 1.0.0-rc.3'];
helpers = helpers || Ember.Handlebars.helpers; data = data || {};
  var buffer = '', stack1, stack2, hashTypes, options, escapeExpression=this.escapeExpression, self=this, helperMissing=helpers.helperMissing;

function program1(depth0,data) {
  
  
  data.buffer.push("New Tap");
  }

function program3(depth0,data) {
  
  var buffer = '', stack1, stack2, hashTypes, options;
  data.buffer.push("\n    <tr>\n      <td>");
  hashTypes = {};
  data.buffer.push(escapeExpression(helpers._triageMustache.call(depth0, "tap.position", {hash:{},contexts:[depth0],types:["ID"],hashTypes:hashTypes,data:data})));
  data.buffer.push("</td>\n      <td>");
  hashTypes = {};
  options = {hash:{},inverse:self.noop,fn:self.program(4, program4, data),contexts:[depth0,depth0],types:["STRING","ID"],hashTypes:hashTypes,data:data};
  stack2 = ((stack1 = helpers.linkTo),stack1 ? stack1.call(depth0, "tap", "tap", options) : helperMissing.call(depth0, "linkTo", "tap", "tap", options));
  if(stack2 || stack2 === 0) { data.buffer.push(stack2); }
  data.buffer.push("</td>\n    </tr>\n    ");
  return buffer;
  }
function program4(depth0,data) {
  
  
  data.buffer.push("view");
  }

  data.buffer.push("<h2>Taps</h2>\n\n");
  hashTypes = {};
  options = {hash:{},inverse:self.noop,fn:self.program(1, program1, data),contexts:[depth0],types:["STRING"],hashTypes:hashTypes,data:data};
  stack2 = ((stack1 = helpers.linkTo),stack1 ? stack1.call(depth0, "new_tap", options) : helperMissing.call(depth0, "linkTo", "new_tap", options));
  if(stack2 || stack2 === 0) { data.buffer.push(stack2); }
  data.buffer.push("\n\n<table>\n  <thead>\n    <th>position</th>\n  </thead>\n  <tbody>\n    ");
  hashTypes = {};
  stack2 = helpers.each.call(depth0, "tap", "in", "controller", {hash:{},inverse:self.noop,fn:self.program(3, program3, data),contexts:[depth0,depth0,depth0],types:["ID","ID","ID"],hashTypes:hashTypes,data:data});
  if(stack2 || stack2 === 0) { data.buffer.push(stack2); }
  data.buffer.push("\n  </tbody>\n</table>\n\n\n");
  return buffer;
  
});


