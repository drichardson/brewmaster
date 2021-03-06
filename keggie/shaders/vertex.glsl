// Attributes (input to vertex shader)
attribute vec4 a_position;
attribute vec2 a_textureCoordinates;

// Uniforms. May also be used by fragment shader.
uniform mat4 u_modelViewProjectionMatrix; // convert from model space to normalized device coordinate space
uniform bool u_enableTexture;

// Varying (output from vertex shader - input to fragment shader)
varying vec2 v_textureCoordinates;

void main()
{
    gl_Position = u_modelViewProjectionMatrix * a_position;

    if (u_enableTexture) {
        v_textureCoordinates = a_textureCoordinates;
    }
}

