#include "gl_context.h"
#include "shader_loader.h"
#include "bundle.h"
#include "log.h"
#include "opengl_utilities.h"
#include <limits.h>

bool gl_context_initialize(gl_context_t* ctx) {
    // Set background color and clear buffers
    glClearColor(1, 1, 1, 1);
    glClear(GL_COLOR_BUFFER_BIT);

    check_gl();
 
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

    // Bind vPosition to attribute 0   
    ctx->a_position = 0;
    glBindAttribLocation(programObject, ctx->a_position, "a_position");

    ctx->a_textureCoordinates = 1;
    glBindAttribLocation(programObject, ctx->a_textureCoordinates, "a_textureCoordinates");

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

    // Store the program object
    ctx->mainProgram = programObject;
    return true;
}

void gl_context_use_main_program(gl_context_t *ctx) {
    // Reset variables back to known state.

    glUseProgram(ctx->mainProgram);
}

