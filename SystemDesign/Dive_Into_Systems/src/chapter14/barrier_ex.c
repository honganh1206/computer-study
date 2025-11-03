#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define ARRAY_SIZE 16
#define NUM_THREADS 4

pthread_barrier_t barrier;

typedef struct {
  long id;
  int numThreads;
  int *arr;
  int start;
  int end;
} thread_args;

int print_error(char *msg) {
  fprintf(stderr, "%s\n", msg);
  exit(2);
}

void *scalar(void *args) {
  thread_args *myargs = (thread_args *)args;
  long myid = myargs->id;
  int *arr = myargs->arr;
  int start = myargs->start;
  int end = myargs->end;
  printf("Thread %ld starting work on indices [%d, %d)\n", myid, start, end);

  /*Wait until ALL threads reach this point */
  pthread_barrier_wait(&barrier);
  printf("Thread %ld passed the barrier and is doubling values.\n", myid);
  for (int i = start; i < end; i++) {
    /* This could lead to a data race if not done right? */
    arr[i] *= 2;
  }

  printf("Thread %ld finished.\n", myid);
  return NULL;

}

int main() {
    pthread_t threads[NUM_THREADS];
    thread_args targs[NUM_THREADS];
    int *array = malloc(ARRAY_SIZE * sizeof(int));

    // Initialize array
    for (int i = 0; i < ARRAY_SIZE; i++) {
        array[i] = i + 1;
    }

    // Initialize barrier for NUM_THREADS
    pthread_barrier_init(&barrier, NULL, NUM_THREADS);

    int chunk = ARRAY_SIZE / NUM_THREADS;
    for (long t = 0; t < NUM_THREADS; t++) {
        targs[t].id = t;
        targs[t].numThreads= NUM_THREADS;
        targs[t].arr = array;
        targs[t].start = t * chunk;
        targs[t].end = (t == NUM_THREADS - 1) ? ARRAY_SIZE : (t + 1) * chunk;
        pthread_create(&threads[t], NULL, scalar, &targs[t]);
    }

    for (int t = 0; t < NUM_THREADS; t++) {
        pthread_join(threads[t], NULL);
    }

    pthread_barrier_destroy(&barrier);

    printf("\nFinal array values:\n");
    for (int i = 0; i < ARRAY_SIZE; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    free(array);
    return 0;
}
