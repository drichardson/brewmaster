#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <limits.h>

#include <GLES2/gl2.h>
#include <EGL/egl.h>

#include "gl_context.h"
#include "geometry.h"
#include "image.h"
#include "opengl_utilities.h"
#include "shader_loader.h"
#include "texture_loader.h"
#include "text_rendering.h"
#include "log.h"
#include "bundle.h"

#if 0
// For debugging
static void DrawRedBoxAroundRect(gl_context_t* context, rect2d_t rect)
{
    float const l = rect_left(rect);
    float const r = rect_right(rect);
    float const t = rect_top(rect);
    float const b = rect_bottom(rect);

    // Draw a yellow 1 pixel box around the entire thing.
    GLfloat boxLines[] = {
        l, b, 0,
        l, t, 0,
        r, t, 0,
        r, b, 0
    };

    // Use the program object
    glUseProgram(context->mainProgram);

    glVertexAttribPointer(context->a_position, 3, GL_FLOAT, GL_FALSE, 0, boxLines);
    glEnableVertexAttribArray(context->a_position);
    glUniform4f(context->u_fragColor, 1,0,0,1);
    glDrawArrays(GL_LINE_LOOP, 0, 4);
    check_gl();
}
#endif

static void DrawImageResourceAtPoint(gl_context_t* context, char const* image_name, GLfloat xFromLeft, GLfloat yFromTop) {
    image_t* img = bundle_image_named(image_name);
    rect2d_t r;
    r.size = image_size(img);
    r.origin.x = xFromLeft;
    r.origin.y = rect_top(context->screen_bounds) - r.size.height - yFromTop;
    image_draw(img, context, r);
    image_free(img);
}

static void DrawBeerLabel(gl_context_t* context, image_t* img) {
    rect2d_t r = rect_make(0, 0, 0, 0);
    r.size = image_size(img);
    image_draw(img, context, r);
}

static void DrawToolbarBackground(gl_context_t* context)
{
    DrawImageResourceAtPoint(context, "toolbar-background.png", 0, 0);
}

static void DrawGear(gl_context_t* context) {
    //DrawImageResourceAtPoint(context, "toolbar-background.png", point_make(0, 0));
}

static void DrawSelectedTap(gl_context_t* context) {
    //DrawImageResourceAtPoint(context, "toolbar-background.png", point_make(0, 0));
}

static void DrawRightLabel(gl_context_t* context, char const* label) {
    point2d_t point = point_make(192, rect_top(context->screen_bounds) - 22);
    char font_path[PATH_MAX];
    bundle_resource_path(font_path, sizeof(font_path), "fonts/GillSans.ttc");
    text_render(context, label, font_path, 20, point, rgba_make(1,1,1,0)); 
}

static void Draw(gl_context_t* context) {
    // Clear the color buffer
    // Set background color and clear buffers
    glClearColor(1, 1, 1, 1);
    glClear(GL_COLOR_BUFFER_BIT);
    check_gl();

    image_t* img = bundle_image_named("beer-label-ruination-ipa.jpg");
    DrawBeerLabel(context, img);
    image_free(img);

    // TODO:DOUG Add blur
    DrawToolbarBackground(context);
    DrawGear(context);
    DrawSelectedTap(context);
    DrawRightLabel(context, "54\xc2\xb0" "F");

    gl_context_swap_buffers(context);
}

int main(int argc, char const **argv)
{
    gl_context_t context;
    memset(&context, 0, sizeof(context));

    bool rc = egl_initialize(&context.egl_context);
    if (!rc) {
        log_error("Couldn't initialize open gl to get full screen.");
        exit(1);
    }

    if (!gl_context_initialize(&context)) {
        log_error("Application specific gl initialization failed.");
        exit(1);
    }

    // Use fake screen bounds when developing in a TV
    if (context.screen_bounds.size.width == 1920) {
        log_debug("Artificially setting screen size to 240x320");
        context.screen_bounds = rect_make(0, 0, 240, 320);
    }
        
    Draw(&context);

    while(1) sleep(10);

    return 0;
}

