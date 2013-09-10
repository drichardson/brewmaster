#include <pthread.h>
#include <stdlib.h>
#include <assert.h>

static pthread_t _main_thread;

void thread_register_main(void) {
    _main_thread = pthread_self();
}

// Assert the current thread is the main thread. Requires that thread_register_main
// was already called.
void thread_assert_is_main(void) {
    assert(_main_thread == pthread_self());
}

