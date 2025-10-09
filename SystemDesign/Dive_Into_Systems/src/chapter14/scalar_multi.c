
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

struct t_arg {
  int *arr; // pointer to shared array
  long length;
  long s;
  long numthreads;
  long id; // thread ID
};

int print_error(char *msg) {
  fprintf(stderr, "%s\n", msg);
  exit(2);
}

void initialize_array(int *array, long length) {
  int i;
  for (i = 0; i < length; i++) {
    array[i] = 1 + (rand() % 10);
  }
}

void print_chunk_results(int *arr, long length, long nthreads) {
  long chunk = length / nthreads;

  for (int tid = 0; tid < nthreads; tid++) {
    long start = tid * chunk;
    long end = start + chunk;
    if (tid == nthreads - 1) {
      end = length;
    }

    printf("Thread %d chunk [%ld-%ld]: ", tid, start, end - 1);
    for (long i = start; i < end && i < start + 10; i++) {
      printf("%d ", arr[i]);
    }
    if (end - start > 10) {
      printf("... ");
    }
    printf("\n");
  }
}

// Each element in the array is scaled by multiplying the element with s
void *scalar_multiply(void *args) {
  /* Cast to struct t_arg * from void* */
  struct t_arg *myargs = (struct t_arg *)args;

  long myid = myargs->id;
  long length = myargs->length;
  long s = myargs->s;
  long nthreads = myargs->numthreads;
  int *ap = myargs->arr;

  int i;
  // Assign each thread its own chunk of elements to process
  long chunk = length / nthreads;
  // Each thread determines its element range using chunk size and its ID
  long start = myid * chunk;
  long end = start + chunk;
  // Suppose each thread has 33,333,333 elements, that leaves 1 element
  // unassigned, then we assign that element to the last thread.
  if (myid == nthreads - 1) {
    end = length;
  }

  // Perform scalar on assigned chunk
  for (i = start; i < end; i++) {
    ap[i] *= s;
  }

  return NULL;
}

int main(int argc, char **argv) {
  int i;
  int ret; // Error detection

  if (argc != 4) {
    fprintf(stderr, "usage: %s <n> <l> <s>\n", argv[0]);
    fprintf(stderr, "where <n> is the number of threads, <l> is the array's "
                    "length and <s> is the scalar factor.\n");
    return 1;
  }
  long length = strtol(argv[2], NULL, 10); // 1 bil
  long nthreads = strtol(argv[1], NULL, 10);
  long s = strtol(argv[3], NULL, 10); // scalar

  int *arr = malloc(length * sizeof(int));

  pthread_t *thread_arr = malloc(nthreads * sizeof(pthread_t));

  struct t_arg *thread_args = malloc(nthreads * sizeof(struct t_arg));

  if (!thread_arr || !thread_args || !arr) {
    print_error("ERROR: malloc failed");
  }

  initialize_array(arr, length);

  /*Populate thread arguments */
  for (i = 0; i < nthreads; i++) {
    thread_args[i].arr = arr;
    thread_args[i].length = length;
    thread_args[i].s = s;
    thread_args[i].numthreads = nthreads;
    thread_args[i].id = i;
  }

  for (i = 0; i < nthreads; i++) {
    ret =
        pthread_create(&thread_arr[i], NULL, scalar_multiply, &thread_args[i]);
    if (ret) {
      print_error("ERROR: pthread_create failed");
    }
  }

  for (i = 0; i < nthreads; i++) {
    ret = pthread_join(thread_arr[i], NULL);
    if (ret) {
      print_error("ERROR: pthread_join failed");
    }
  }

  print_chunk_results(arr, length, nthreads);

  free(thread_arr);
  free(thread_args);
  free(arr);

  return 0;
}
