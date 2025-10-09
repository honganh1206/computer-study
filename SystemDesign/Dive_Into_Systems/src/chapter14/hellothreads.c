#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
int print_error(char *msg) {
  fprintf(stderr, "%s\n", msg);
  exit(2);
}

/*
 * Thread function passed to pthread_create.
 * Each thread executes this function and terminates when it returns from its
 * function.
 * Think of this as the main function for a worker thread.
 * We fetch the thread's function return value via pthread_join().
 */
void *HelloWorld(void *id) {
  // Cast generic pointer of thread ID to long pointer
  long *myid = (long *)id;
  // The 1st thread that prints to stdout will have its output show up first.
  // But behind the scene the OS determines the execution order.
  printf("Hello world! I am thread %ld\n", *myid);
  // No need for threads to return anything
  return NULL;
}

int main(int argc, char **argv) {
  int i;
  int nthreads;
  pthread_t *thread_arr; // Pointer to future thread array
  long *thread_ids;
  int ret; // error detection

  if (argc != 2) {
    fprintf(stderr, "usage: %s <n>\n", argv[0]);
    fprintf(stderr, "where <n> is the number of threads\n");
    return 1;
  }

  // Convert string to long
  nthreads = strtol(argv[1], NULL, 10);
  if (nthreads < 1) {
    print_error("ERROR: enter a positive number of threads");
  }

  // Allocate space for thread structs and IDs
  thread_arr = malloc(nthreads * sizeof(pthread_t));
  thread_ids = malloc(nthreads * sizeof(long));
  if (!thread_arr || !thread_ids) {
    print_error("ERROR: malloc failed");
  }

  for (i = 0; i < nthreads; i++) {
    thread_ids[i] = i;
    ret = pthread_create(&thread_arr[i], NULL, HelloWorld, &thread_ids[i]);
    if (ret) {
      print_error("ERROR: pthread_create failed");
    }
  }

  /*
   * Join all the threads.
   * Main will block in this loop until all threads have returned from the
   * thread function.
   * */
  for (i = 0; i < nthreads; i++) {
    // Specify which thread to wait on for termination 
    // and where the thread's return value should be stored.
    // All worker threads must terminate before main function proceeds.
    ret = pthread_join(thread_arr[i], NULL);
    if (ret) {
      print_error("ERROR: pthread_join failed");
    }
  }

  free(thread_arr);
  free(thread_ids);
}
