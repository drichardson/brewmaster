#include "text_rendering.h"
#include "texture_loader.h"
#include <cairo/cairo.h>
#include <assert.h>
#include <stdio.h>

bool texture_render_text(GLuint* texture_out, char const* text, char const* font, float font_size, int *rendered_width, int *rendered_height) {

    // TODO: Don't use 100x100
    int width = 1920;
    int height = 100;
    cairo_surface_t* surface = cairo_image_surface_create(CAIRO_FORMAT_ARGB32, width, height);
    assert(surface);
    cairo_t *cr = cairo_create(surface);
    assert(cr);

    cairo_set_source_rgb (cr, 0, 0, 1.0);
    cairo_rectangle (cr, 0, 0, width, height);
    cairo_fill (cr);

    cairo_text_extents_t te;
    cairo_set_source_rgb (cr, 0.0, 0.0, 0.0);
    //cairo_select_font_face (cr, "Georgia", CAIRO_FONT_SLANT_NORMAL, CAIRO_FONT_WEIGHT_BOLD);
    //cairo_set_font_size(cr, font_size);
    cairo_text_extents (cr, text, &te);
    printf("text extents: te.width = %f, te.x_bearing = %f, te.y_bearing = %f\n", te.width, te.x_bearing, te.y_bearing);
    cairo_move_to (cr, 0.5 - te.width / 2 - te.x_bearing, 0.5 - te.height / 2 - te.y_bearing); 
    //cairo_show_text(cr, text);

    bool result = texture_load_image(cairo_image_surface_get_data(surface),
            GL_RGBA,
            texture_out,
            cairo_image_surface_get_width(surface),
            cairo_image_surface_get_height(surface));

    cairo_destroy(cr);
    cairo_surface_destroy(surface);

    return result;
}

