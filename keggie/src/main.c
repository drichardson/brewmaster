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

///
// Draw a triangle using the shader pair created in init_app_gl()
//
static void DrawTriangle(gl_context_t* context)
{
    rect2d_t rect = rect_midrect_of_size(context->screen_bounds, size_make(context->screen_bounds.size.width/2.0, context->screen_bounds.size.height/2.0));
    float const l = rect_left(rect);
    float const r = rect_right(rect);
    float const t = rect_top(rect);
    float const b = rect_bottom(rect);

    GLfloat vVertices[] = {
        l, t, 0,
        l, b, 0,
        r, b, 0
    };

    // Use the program object
    gl_context_use_main_program(context);
    glUseProgram(context->mainProgram);

    // Load the vertex data
    glVertexAttribPointer(context->a_position, 3, GL_FLOAT, GL_FALSE, 0, vVertices);
    glEnableVertexAttribArray(context->a_position);
    glUniform4f(context->u_fragColor, 1, 1, 0, 1);

    glDrawArrays(GL_TRIANGLES, 0, 3);
    check_gl();
}

static void DrawRedBoxAroundScreen(gl_context_t* context)
{
    rect2d_t rect = context->screen_bounds;
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


static void DrawToolbarBackground(gl_context_t* context)
{
    image_t* img = bundle_image_named("beer-label-ruination-ipa.jpg");
    rect2d_t beerLabelRect = rect_make(0, 0, 0, 0);
    beerLabelRect.size = image_size(img);
    image_draw(img, context, beerLabelRect);
    image_free(img);

    img = bundle_image_named("toolbar-background.png");
    rect2d_t toolbarRect;
    toolbarRect.size = image_size(img);
    toolbarRect.origin.x = beerLabelRect.origin.x;
    toolbarRect.origin.y = rect_top(beerLabelRect) - toolbarRect.size.height;
    image_draw(img, context, toolbarRect);
    image_free(img);

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

    // Set the viewport
    glViewport(0, 0, context.egl_context.screen_width, context.egl_context.screen_height);

    // Clear the color buffer
    glClear(GL_COLOR_BUFFER_BIT);

    DrawTriangle(&context);
    DrawRedBoxAroundScreen(&context);
    DrawToolbarBackground(&context);
    
    char font_path[PATH_MAX];
    bundle_resource_path(font_path, sizeof(font_path), "fonts/GillSans.ttc");
    text_render(&context, "This is a test.", font_path, 30.0, 300.0, 300.0);
    //text_render(&context, "d", font_path, 30.0, 300.0, 300.0);

    eglSwapBuffers(context.egl_context.display, context.egl_context.surface);

    while(1) sleep(10);

    return 0;
}

