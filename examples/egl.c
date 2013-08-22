#include <stdio.h>
#include <EGL/egl.h>
#include <assert.h>

int main(int argc, char const** argv) {

    // Get the default display
    EGLDisplay display = eglGetDisplay(EGL_DEFAULT_DISPLAY);
    printf("display: %p\n", display);
    assert(display != EGL_NO_DISPLAY);

    // Initialize EGL and get the versions
    int major, minor;
    EGLBoolean result = eglInitialize(display, &major, &minor);
    assert(result);
    printf("major: %d, minor: %d\n", major, minor);

    // Get the configurations available for use.
    EGLint numConfigsOne;
    result = eglGetConfigs(display, NULL, 0, &numConfigsOne);
    assert(result);
    printf("configs: total %d\n", numConfigsOne);
    
    EGLConfig* configs = (EGLConfig*)malloc(sizeof(EGLConfig)*numConfigsOne);
    EGLint numConfigsTwo;
    result = eglGetConfigs(display, configs, numConfigsOne, &numConfigsTwo);
    assert(result);
    assert(numConfigsOne == numConfigsTwo);
    EGLint i;
    for(i = 0; i < numConfigsTwo; ++i) {
        EGLint bufferSize;
        eglGetConfigAttrib(display, configs[i], EGL_BUFFER_SIZE, &bufferSize);

        printf("Config #%d -------------------\n", i);
        printf("Buffer Size: %d\n", bufferSize);
    }
    free(configs);


    return 0;
}

