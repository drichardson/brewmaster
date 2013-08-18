TARGETS=openvc opengl_raspi gcd framebuffer_info framebuffer_draw cairo_framebuffer_draw parse_json
CFLAGS=-g -O0 -Wall -Werror

all: $(TARGETS)

gcd: gcd.c
	clang -fblocks -lBlocksRuntime -ldispatch $< $(CFLAGS) -o $@

framebuffer_info: framebuffer_info.c
	$(CC) $< $(CFLAGS) -o $@

framebuffer_draw: framebuffer_draw.c
	$(CC) $< $(CFLAGS) -o $@

cairo_framebuffer_draw: cairo_framebuffer_draw.c
	$(CC) -lcairo $< $(CFLAGS) -o $@

parse_json: parse_json.c
	clang -ljansson $< $(CFLAGS) -o $@
	
# Extra C flags added to support Broadcom specific shit. See:
# /opt/vc/src/hello_pi/hello_triangle2
# or
# http://elinux.org/RPi_VideoCore_APIs
# for more information.
#BC_CFLAGS+=-DSTANDALONE -D__STDC_CONSTANT_MACROS -D__STDC_LIMIT_MACROS -DTARGET_POSIX -D_LINUX -fPIC -DPIC -D_REENTRANT -D_LARGEFILE64_SOURCE -D_FILE_OFFSET_BITS=64 -U_FORTIFY_SOURCE -DHAVE_LIBOPENMAX=2 -DOMX -DOMX_SKIP64BIT -ftree-vectorize -pipe -DUSE_EXTERNAL_OMX -DHAVE_LIBBCM_HOST -DUSE_EXTERNAL_LIBBCM_HOST -DUSE_VCHIQ_ARM -Wno-psabi

BC_LDFLAGS+=-L/opt/vc/lib/ -lGLESv2 -lEGL -lopenmaxil -lbcm_host -lvcos -lvchiq_arm -lpthread -lrt
BC_INCLUDES+=-I/opt/vc/include/ -I/opt/vc/include/interface/vcos/pthreads -I/opt/vc/include/interface/vmcs_host/linux


opengl_raspi: opengl_raspi.c
	$(CC) $(BC_INCLUDES) $(CFLAGS) $(BC_CFLAGS) $< -o $@ $(BC_LDFLAGS)
	
openvc: openvc.c tiger.c
	$(CC) $(BC_INCLUDES) $(CFLAGS) $(BC_CFLAGS) tiger.c openvc.c -o $@ $(BC_LDFLAGS)
clean:
	$(RM) $(TARGETS)
