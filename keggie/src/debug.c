#include "debug.h"
#include <stdarg.h>
#include <assert.h>
#include <stdio.h>
#include <math.h>

#define DEBUG_TIMER_CLOCK CLOCK_MONOTONIC_RAW

void debug_timer_init(debug_timer* t) {
    struct timespec resolution;
    int rc = clock_getres(DEBUG_TIMER_CLOCK, &resolution);
    assert(rc == 0);

    // Use the resolution of the clock to determine how many digits of precision to use for the log messages.
    // 1 -> 9 (nanosecond resolution)
    // 1000 -> 6 (microsecond resolution)
    // 1000000 -> 3 (millisecond resolution)
    unsigned precision = log10(1e9 / resolution.tv_nsec);
    snprintf(t->format, sizeof(t->format), "DEBUG TIMER @ %%.%uf: ", precision);

    // The last thing this function should do is grab the current time, so we don't waste anytime
    // in the above functions.
    rc = clock_gettime(DEBUG_TIMER_CLOCK, &t->start_time);
    assert(rc == 0);
}

void debug_timer_log(debug_timer const* t, char const* format, ...) {
    struct timespec now;
    int rc = clock_gettime(DEBUG_TIMER_CLOCK, &now);
    assert(rc == 0);
    double interval = (now.tv_sec - t->start_time.tv_sec);
    interval += (now.tv_nsec - t->start_time.tv_nsec) / 1e9;
    va_list va;
    va_start(va, format);
    printf(t->format, interval);
    vprintf(format, va);
    putchar('\n');
    va_end(va);
}

