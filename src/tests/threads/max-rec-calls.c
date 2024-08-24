/*
  File for 'max-rec-calls' task implementation.
*/

#include <stdio.h>
#include "tests/threads/tests.h"
#include "threads/malloc.h"
#include "threads/thread.h"


struct arguments_func{
  int d;
  int n;
};

void recursive_function_test(void *a) {
  struct arguments_func b = *(struct arguments_func *) a;

  b.d += 1;
  int depth = b.d;
  int n = b.n;
  printf("depth - %d\n", depth);
  recursive_function_test(&b);
}

void test_max_rec_calls(void) {
    msg("Testing maximum recursive calls");
    struct arguments_func arguments;
    arguments.d = 0;
    arguments.n = 2;
    printf("size - %d\n", sizeof(arguments));
    thread_create("Test_recursion", PRI_DEFAULT, recursive_function_test, &arguments);
    msg("Thread created");

    timer_sleep(400);
    // pass();
}
