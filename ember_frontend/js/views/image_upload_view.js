var ImageUploadView = Ember.View.extend({
 	fileField: Ember.TextField.extend({
        type: 'file',
        attributeBindings: ['name'],
        change: function(evt) {
            var input = evt.target;
            if (input.files && input.files[0]) {
                var reader = new FileReader();
                var that = this;
                reader.onload = function(e) {
                    var view = that.getPath('parentView.previewImageView');
                    view.printme();
                    view.set('src', e.target.result);
					console.log(e.target.result);
/* since there is a two-way binding with the img src
                    and the model, an update to one should be reflected
                    in the other.  However, this doesn't seem to be the case
My guess is because I am not using the ember.js wrapper functions to update
                    the src attribute.
                    */
                    // console.log("Model src [" + App.myModel.get('myModel_src') + "]");

                    //App.myModel.set('myModel_src', e.target.result);
                }
                reader.readAsDataURL(input.files[0]);
            }
        },
        printme: function() {
            console.log("In FilField view\n");
        },
    }),

    previewImageView: Ember.View.extend({
        attributeBindings: ['name', 'width', 'height', 'src'],
        tagName: 'img',
        viewName: 'previewImageView',
        printme: function() {
            console.log('in previewImageView');
        },
    }),
});

module.exports = ImageUploadView;

