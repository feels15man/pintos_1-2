/*
  File for 'threads-term' task implementation.
*/

#include <stdio.h>
#include "tests/threads/tests.h"
#include "threads/malloc.h"
#include "threads/thread.h"
#include "devices/timer.h"


static void threads_term_test_func(void *arg UNUSED);

struct thread_params {
    char *thread_name;
};

void test_threads_term(void) 
{
  msg("Test started.");

  tid_t tid_list[5];
  struct thread_params params_list[5];

  for (int i = 0; i < 5; i++) 
  {
    char name[16];
    snprintf (name, sizeof name, "thread_%d", i + 1);
    params_list[i].thread_name = name;
    // printf("name - %s\t%s\n", name,params_list[i].thread_name);
    // test.thread_num = i + 1;
    tid_list[i] = thread_create(name, PRI_DEFAULT, threads_term_test_func, &params_list[i]);
  }
  msg("Threads created successfuly.");

  timer_sleep(400);

  thread_terminate(tid_list[0]);//Thread_1
  thread_terminate(tid_list[2]);//Thread_3
  msg("Threads 1 and 3 terminated successfuly.");

  timer_sleep(400);

  msg("Test finifshed.");

}



static void threads_term_test_func(void *arg UNUSED) {
  // struct thread_params *thread_data = (struct thread_params *)arg;
  struct thread *t = thread_current ();
  while (true) {
      printf("%s is running\n", t -> name);
      timer_sleep(100); // 100 ticks per second
      // thread_yield ();
  }
}