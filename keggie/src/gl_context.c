#include "gl_context.h"
#include "shader_loader.h"
#include "bundle.h"
#include "log.h"
#include "opengl_utilities.h"
#include "matrix.h"
#include <limits.h>
#include <math.h>

static void gl_context_reset_state(gl_context_t* ctx) {
    gl_context_use_main_program(ctx);

    matrix_t translate;
    matrix_t scale;
    matrix_t mvp;

    // TODO: Cache this. Only need to calculate once on initalization or screen size change.
    matrix_make_translation(-1, -1, 0, &translate);
    matrix_make_scale(2.0/ctx->screen_bounds.size.width, 2.0/ctx->screen_bounds.size.height, 1, &scale);
    matrix_multiply(&translate, &scale, &mvp);

    glUniformMatrix4fv(ctx->u_modelViewProjectionMatrix, 1, GL_FALSE, (GLfloat const*)&mvp);
    glUniform4f(ctx->u_fragColor, 1,1,1,1);
    glUniform1i(ctx->u_enableTexture, 0);

    glDisable(GL_BLEND);
}

bool gl_context_initialize(gl_context_t* ctx) {

    ctx->screen_bounds = rect_make(0, 0, ctx->egl_context.screen_width, ctx->egl_context.screen_height);

    GLuint vertexShader;
    GLuint fragmentShader;
    GLuint programObject;
    GLint linked;

    char vertext_shader_path[PATH_MAX];
    bundle_resource_path(vertext_shader_path, sizeof(vertext_shader_path), "shaders/vertex.glsl");
    char fragment_shader_path[PATH_MAX];
    bundle_resource_path(fragment_shader_path, sizeof(fragment_shader_path), "shaders/fragment.glsl");

    bool const vertexShaderLoaded = shader_load_from_file(GL_VERTEX_SHADER, vertext_shader_path, &vertexShader);
    bool const fragmentShaderLoaded = shader_load_from_file(GL_FRAGMENT_SHADER, fragment_shader_path, &fragmentShader);

    assert(vertexShaderLoaded);
    assert(fragmentShaderLoaded);

    // Create the program object
    programObject = glCreateProgram();

    if ( programObject == 0 ) {
        log_error("glCreateProgram failed");
        return false;
    }

    glAttachShader(programObject, vertexShader);
    glAttachShader(programObject, fragmentShader);

    // Won't be deleted until program is deleted.
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);

    // Link the program
    glLinkProgram(programObject);

    // Check the link status
    glGetProgramiv(programObject, GL_LINK_STATUS, &linked);

    if (!linked) 
    {
        GLint infoLen = 0;

        glGetProgramiv(programObject, GL_INFO_LOG_LENGTH, &infoLen);

        if (infoLen > 1)
        {
            char* infoLog = malloc(sizeof(char) * infoLen);

            glGetProgramInfoLog(programObject, infoLen, NULL, infoLog);
            log_error("Error linking program:\n%s", infoLog);

            free(infoLog);
        }

        glDeleteProgram(programObject);
        return false;
    }

    // Get attribute locations
    ctx->a_position = glGetAttribLocation(programObject, "a_position");
    ctx->a_textureCoordinates = glGetAttribLocation(programObject, "a_textureCoordinates");

    assert(ctx->a_position != -1);
    assert(ctx->a_textureCoordinates != -1);
    
    // Get uniform locations
    ctx->u_modelViewProjectionMatrix = glGetUniformLocation(programObject, "u_modelViewProjectionMatrix");
    ctx->u_enableTexture = glGetUniformLocation(programObject, "u_enableTexture");
    ctx->u_fragColor = glGetUniformLocation(programObject, "u_fragColor");
    ctx->u_texture = glGetUniformLocation(programObject, "u_texture");

    assert(ctx->u_modelViewProjectionMatrix != -1);
    assert(ctx->u_fragColor != -1);
    assert(ctx->u_enableTexture != -1);
    assert(ctx->u_texture != -1);

    // Store the program object
    ctx->mainProgram = programObject;

    // Set the viewport
    glViewport(0, 0, ctx->egl_context.screen_width, ctx->egl_context.screen_height);

    // Make sure there weren't any gl errors missed before returning.
    check_gl();

    // ctx should be completely initialized at this point.
    gl_context_reset_state(ctx);

    GLenum fbStatus = glCheckFramebufferStatus(GL_FRAMEBUFFER);
    if (fbStatus != GL_FRAMEBUFFER_COMPLETE) {
        log_error("Framebuffer status not complete: %x", fbStatus);
        return false;
    }

    return true;
}

void gl_context_use_main_program(gl_context_t *ctx) {
    // Reset variables back to known state.

    glUseProgram(ctx->mainProgram);
}

void gl_context_swap_buffers(gl_context_t* ctx) {
    eglSwapBuffers(ctx->egl_context.display, ctx->egl_context.surface);
}

