#include <dispatch/dispatch.h>
#include <stdio.h>

int main(int argc, char** argv) {
    puts("Hi");
    dispatch_semaphore_t sem = dispatch_semaphore_create(1);

    // simple block
    __block int counter = 0;
    void (^b)(void) = ^{
        dispatch_semaphore_wait(sem, DISPATCH_TIME_FOREVER);
        printf("block called %d time(s)\n", ++counter);
        dispatch_semaphore_signal(sem);
    };
    b();
    
    dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0), b);
    dispatch_after(dispatch_time(DISPATCH_TIME_NOW, 2 * NSEC_PER_SEC), dispatch_get_main_queue(), b);
    puts("about to call dispatch_main, control+C to end");
    dispatch_main();
    puts("will never get here");
    return 0;
}

