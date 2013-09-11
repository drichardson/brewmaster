#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <limits.h>

#include "GLES2/gl2.h"
#include "EGL/egl.h"

#include "gl_context.h"
#include "geometry.h"
#include "image.h"
#include "opengl_utilities.h"
#include "shader_loader.h"
#include "texture_loader.h"
#include "text_rendering.h"
#include "threads.h"
#include "log.h"
#include "bundle.h"

///
// Draw a triangle using the shader pair created in init_app_gl()
//
static void DrawTriangle(gl_context_t* context)
{
    GLfloat vVertices[] = {
        -0.5f,  0.5f, 0.0f,
        -0.5f, -0.5f, 0.0f,
        0.5f, -0.5f, 0.0f
    };

    // Use the program object
    gl_context_use_main_program(context);
    glUseProgram(context->mainProgram);
    GLint fragColor = glGetUniformLocation(context->mainProgram, "u_fragColor"); 

    // Load the vertex data
    glVertexAttribPointer(context->a_position, 3, GL_FLOAT, GL_FALSE, 0, vVertices);
    glEnableVertexAttribArray(context->a_position);
    glUniform4f(fragColor, 1, 1, 0, 1);

    glDrawArrays(GL_TRIANGLES, 0, 3);
    check_gl();
}

static void DrawRedBoxAroundScreen(gl_context_t* context)
{
    // Draw a yellow 1 pixel box around the entire thing.
    GLfloat boxLines[] = {
        -1.0, -1.0, 0,
        -1.0, 1.0, 0,
        1.0, 1.0, 0,
        1.0, -1.0, 0
    };

    // Use the program object
    glUseProgram(context->mainProgram);
    GLint fragColor = glGetUniformLocation(context->mainProgram, "u_fragColor"); 

    glVertexAttribPointer(context->a_position, 3, GL_FLOAT, GL_FALSE, 0, boxLines);
    glEnableVertexAttribArray(context->a_position);
    glUniform4f(fragColor, 1,0,0,1);
    glDrawArrays(GL_LINE_LOOP, 0, 4);
    check_gl();
}


static void DrawToolbarBackground(gl_context_t* context)
{
    rect2d_t rect;
    rect.origin.x = -1.0;
    rect.origin.y = 0.8;
    rect.size.width = 2;
    rect.size.height = 0.2;
    image_t* img = bundle_image_named("toolbar-background.png");
    image_draw(img, context, rect);
    image_free(img);
}

int main(int argc, char const **argv)
{
    thread_register_main();

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
    log_debug("Loading font from %s\n", font_path);
    //text_render("This is a test.", font_path, 20.0, 0.0, 0.0);

    eglSwapBuffers(context.egl_context.display, context.egl_context.surface);

    while(1) sleep(10);

    return 0;
}

