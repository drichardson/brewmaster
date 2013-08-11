TARGETS=opengl_sdl gcd framebuffer_info framebuffer_draw cairo_framebuffer_draw
CFLAGS=-g -O0 -Wall -Werror
CC=clang

all: $(TARGETS)

gcd: gcd.c
	$(CC) -fblocks -lBlocksRuntime -ldispatch $< $(CFLAGS) -o $@

framebuffer_info: framebuffer_info.c
	$(CC) $< $(CFLAGS) -o $@

framebuffer_draw: framebuffer_draw.c
	$(CC) $< $(CFLAGS) -o $@

cairo_framebuffer_draw: cairo_framebuffer_draw.c
	$(CC) -lcairo $< $(CFLAGS) -o $@

opengl_sdl: opengl_sdl.c
	$(CC) $< $(CFLAGS) -o $@ -lGL -lSDL -lGLU

clean:
	$(RM) $(TARGETS)
