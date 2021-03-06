#include "egl_context.h"
#include "opengl_utilities.h"
#include "bcm_host.h"
#include <assert.h>

bool egl_initialize(egl_context_t* context)
{
    bcm_host_init();

    int32_t success = 0;
    EGLBoolean result;
    EGLint num_config;

    static EGL_DISPMANX_WINDOW_T nativewindow;

    DISPMANX_ELEMENT_HANDLE_T dispman_element;
    DISPMANX_DISPLAY_HANDLE_T dispman_display;
    DISPMANX_UPDATE_HANDLE_T dispman_update;
    VC_RECT_T dst_rect;
    VC_RECT_T src_rect;

    static const EGLint attribute_list[] =
    {
        EGL_RED_SIZE, 8,
        EGL_GREEN_SIZE, 8,
        EGL_BLUE_SIZE, 8,
        EGL_ALPHA_SIZE, 8,
        EGL_SURFACE_TYPE, EGL_WINDOW_BIT,
        EGL_NONE
    };

    static const EGLint context_attributes[] = 
    {
        EGL_CONTEXT_CLIENT_VERSION, 2,
        EGL_NONE
    };
    EGLConfig config;

    // get an EGL display connection
    context->display = eglGetDisplay(EGL_DEFAULT_DISPLAY);
    assert(context->display!=EGL_NO_DISPLAY);
    check_gl();

    // initialize the EGL display connection
    result = eglInitialize(context->display, NULL, NULL);
    assert(EGL_FALSE != result);
    check_gl();

    // get an appropriate EGL frame buffer configuration
    result = eglChooseConfig(context->display, attribute_list, &config, 1, &num_config);
    assert(EGL_FALSE != result);
    check_gl();

    // get an appropriate EGL frame buffer configuration
    result = eglBindAPI(EGL_OPENGL_ES_API);
    assert(EGL_FALSE != result);
    check_gl();

    // create an EGL rendering context
    context->context = eglCreateContext(context->display, config, EGL_NO_CONTEXT, context_attributes);
    assert(context->context!=EGL_NO_CONTEXT);
    check_gl();

    // create an EGL window surface
    success = graphics_get_display_size(0 /* LCD */, &context->screen_width, &context->screen_height);
    assert(success >= 0);

    dst_rect.x = 0;
    dst_rect.y = 0;
    dst_rect.width = context->screen_width;
    dst_rect.height = context->screen_height;

    src_rect.x = 0;
    src_rect.y = 0;
    src_rect.width = context->screen_width << 16;
    src_rect.height = context->screen_height << 16;        

    dispman_display = vc_dispmanx_display_open(0 /* LCD */);
    dispman_update = vc_dispmanx_update_start(0);

    dispman_element = vc_dispmanx_element_add(dispman_update, dispman_display,
            0/*layer*/, &dst_rect, 0/*src*/,
            &src_rect, DISPMANX_PROTECTION_NONE, 0 /*alpha*/, 0/*clamp*/, 0/*transform*/);

    nativewindow.element = dispman_element;
    nativewindow.width = context->screen_width;
    nativewindow.height = context->screen_height;
    vc_dispmanx_update_submit_sync(dispman_update);

    check_gl();

    context->surface = eglCreateWindowSurface(context->display, config, &nativewindow, NULL);
    assert(context->surface != EGL_NO_SURFACE);
    check_gl();

    // connect the context to the surface
    result = eglMakeCurrent(context->display, context->surface, context->surface, context->context);
    assert(EGL_FALSE != result);
    check_gl();

    return true;
}


