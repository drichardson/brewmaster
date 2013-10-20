#pragma once

#include <time.h>

typedef struct {
    char format[40];
    struct timespec start_time;
} debug_timer;

void debug_timer_init(debug_timer*);
void debug_timer_log(debug_timer const* t, char const* format, ...) __attribute__ ((format (printf, 2, 3)));

