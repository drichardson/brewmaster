precision mediump float;

// Fragment specific uniforms
uniform vec4 u_fragColor;
uniform sampler2D u_texture;

// Shared uniforms
uniform bool u_enableTexture;

// Varying (input to fragment shader)
varying vec2 v_textureCoordinates;

void main()
{
    if (u_enableTexture) {
        gl_FragColor = u_fragColor + texture2D(u_texture, v_textureCoordinates);
    } else {
        gl_FragColor = u_fragColor;
    }
}

