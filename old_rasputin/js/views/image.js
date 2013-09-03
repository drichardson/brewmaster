
Backbone.Form.editors.Image = Backbone.Form.editors.Base.extend({

    tagName: 'div',

		template: Handlebars.compile( $("#file-upload-template").html() ),

    events: {
			'change input[type=file]': 'updateImage',

			'change': function() {
			    // The 'change' event should be triggered whenever something happens
			    // that affects the result of `this.getValue()`.
			    this.trigger('change', this);
			},
			'focus': function() {
			    // The 'focus' event should be triggered whenever an input within
			    // this editor becomes the `document.activeElement`.
			    this.trigger('focus', this);
			    // This call automatically sets `this.hasFocus` to `true`.
			},
			'blur': function() {
			    // The 'blur' event should be triggered whenever an input within
			    // this editor stops being the `document.activeElement`.
			    this.trigger('blur', this);
			    // This call automatically sets `this.hasFocus` to `false`.
			}
    },

    initialize: function(options) {
        // Call parent constructor
        Backbone.Form.editors.Base.prototype.initialize.call(this, options);

				this.listenTo(this.model, 'change', this.render);

        // Custom setup code.
        if (this.schema.customParam) {
					this.doSomething();
				}
    },

    render: function() {
	    	Backbone.Form.editors.Base.prototype.render.apply(this, arguments);
  
				this.$el.html(this.template(this.model.toJSON()));
        return this;
    },

		// Keep the data on the img teg
    getValue: function() {
				return this.$("#image-preview").attr("src");
    },

    setValue: function(value) {
				this.$("#image-preview").attr("src", value);
    },

    focus: function() {
        if (this.hasFocus) return;

        // This method call should result in an input within this edior
        // becoming the `document.activeElement`.
        // This, in turn, should result in this editor's `focus` event
        // being triggered, setting `this.hasFocus` to `true`.
        // See above for more detail.
        this.$el.focus();
    },

    blur: function() {
        if (!this.hasFocus) return;

        this.$el.blur();
    },

		updateImage: function(e) {
			this.readFile(e.target.files[0]);
		},
		
		readFile: function(file) {
		    var reader = new FileReader();
		    // closure to capture the file information.
		    reader.onload = (function(theFile,that) {
		        return function(e) {
		            // Set the value on the 
								that.setValue(e.target.result);
		        };
		    })(file,this);

		    // Read in the image file as a data URL.
		    reader.readAsDataURL(file);
		}
		
});