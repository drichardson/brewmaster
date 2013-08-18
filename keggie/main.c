#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "VG/openvg.h"
#include "VG/vgu.h"
#include "fontinfo.h"
#include "shapes.h"
#include "fonts/fonts.h"

static Fontinfo DefaultTypeface;

// Sort of simulate a sainsmart display. The shapes library still
// knows about the acutal size of the display, however.
void init_simulating_sainsmart_display(int *w, int *h) {
    init(w, h);
    *w = 240;
    *h = 320;
}

int main() {
	int width, height;

	init_simulating_sainsmart_display(&width, &height);	// Graphics initialization
    DefaultTypeface = load_HelveticaNeueDeskUI();

    Start(width, height);				   // Start the picture
	Background(0, 0, 0);				   // Black background
	Fill(44, 77, 232, 1);				   // Big blue marble
	Circle(width / 2, 0, width);			   // The "world"
	Fill(255, 255, 255, 1);				   // White text
	TextMid(width / 2, height / 2, "hello, world", DefaultTypeface, width / 10);	// Greetings 
	End();						   // update picture

    sleep(2);

	finish();					   // Graphics cleanup
	exit(0);
}

