#include "shader_loader.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <errno.h>
#include <string.h>


///
// Create a shader object, load the shader source, and
// compile the shader.
//
bool shader_load_from_string(GLenum type, const char *shader_source, GLuint* shader_out)
{
    GLuint shader;
    GLint compiled;

    // Create the shader object
    shader = glCreateShader(type);

    if (shader == 0)
        return false;

    // Load the shader source
    glShaderSource (shader, 1, &shader_source, NULL);

    // Compile the shader
    glCompileShader(shader);

    // Check the compile status
    glGetShaderiv(shader, GL_COMPILE_STATUS, &compiled);

    if (!compiled) 
    {
        GLint infoLen = 0;

        glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &infoLen);

        if (infoLen > 1)
        {
            char* infoLog = malloc(sizeof(char) * infoLen );

            glGetShaderInfoLog(shader, infoLen, NULL, infoLog);
            printf("Error compiling shader:\n%s\n", infoLog);            

            free(infoLog);
        }

        glDeleteShader(shader);
        return false;
    }

    if (shader_out) {
        *shader_out = shader;
    } else {
        glDeleteShader(shader);
    }

    return true;

}

bool shader_load_from_file(GLenum shaderType, const char* filename, GLuint* shader_out)
{
    int fd = open(filename, O_RDONLY);
    if (fd == -1) {
        fprintf(stderr, "Couldn't open shader at %s. %d: %s\n", filename, errno, strerror(errno));
        return false;
    }

    struct stat statbuf;
    if (fstat(fd, &statbuf) == -1) {
        fprintf(stderr, "Couldn't get stat info for %s\n", filename);
        close(fd);
        return false;
    }

    char* shader_source = mmap(NULL, statbuf.st_size, PROT_READ, MAP_PRIVATE, fd, 0);
    if (shader_source == MAP_FAILED) {
        fprintf(stderr, "mmap failed to map file %s. %d: %s\n", filename, errno, strerror(errno));
        close(fd);
        return false;
    }

    bool result = shader_load_from_string(shaderType, shader_source, shader_out);

    if (munmap(shader_source, statbuf.st_size) == -1) {
        fprintf(stderr, "error unmapping file %s. %d: %s\n", filename, errno, strerror(errno));
    }

    close(fd);

    return result;
}

