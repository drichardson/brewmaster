#pragma once

// Register a thread as the main thread. Should be called once at startup, preferable
// by main.
void thread_register_main(void);

// Assert the current thread is the main thread. Requires that thread_register_main
// was already called.
void thread_assert_is_main(void);

