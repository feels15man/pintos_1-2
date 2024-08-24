
/*
  File for 'test-new-alg' task implementation.
*/

#include <stdio.h>
#include "tests/threads/tests.h"
#include "threads/malloc.h"
#include "threads/thread.h"
#include "threads/synch.h"
#include "devices/timer.h"


//func analog thread_create with cpu_birst ...
// void thread_create_with_cpu_burst(const char *name, int priority,
//                                   thread_func *function, void *aux, int cpu_burst)
// {
//   tid_t temp_tid = thread_create(name, priority, function, aux);
//   // for(struct list_elem *e = list_begin(&all_list); e != list_end(&all_list); e = list_next(e)){
//   //   struct thread *t = list_entry(e, struct thread, elem);
//   //   if(t->tid == temp_tid)
//   //   {
//   //     t->cpu_burst = cpu_burst;
//   //     break;
//   //   }
//   // }
// }


void test_new_alg_func(void){
  struct thread *t = thread_current();
  while (1)
  {
    printf("%s running for:%d\tcpu_burst:%d\n", t->name, t->cpu_ticks + 1, t->cpu_burst);
  }
}


void test_new_alg(void) 
{
  thread_set_priority(PRI_MAX);

  thread_create_with_cpu_burst("proc_0", 22, test_new_alg_func, NULL, 6);
  thread_create_with_cpu_burst("proc_1", 2, test_new_alg_func, NULL, 5);
  thread_create_with_cpu_burst("proc_2", 31, test_new_alg_func, NULL, 4);
  thread_create_with_cpu_burst("proc_3", 45, test_new_alg_func, NULL, 7);
  thread_create_with_cpu_burst("proc_4", 3, test_new_alg_func, NULL, 8);

  FCFS_on();
  thread_set_priority(PRI_MIN);

  msg("Done");
}
