#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

#define MAX 10 // the maximum value of an element. (10 means 0-9)

pthread_mutex_t mutex;

struct t_arg {
  long id;
  long numthreads;
  int *ap;      // pointer to array to be sorted
  int length;   // Length of array to be sorted
  long *countp; // pointer to count array
};

/*error handling function: prints out error message*/
int print_error(char *msg) {
  fprintf(stderr, "%s\n", msg);
  exit(2);
}

/*
 * fills an input array of specified length (length) with random
   values from 0 to MAX-1
*/
void genRandomArray(int *array, long length) {
  int i;
  for (i = 0; i < length; i++) {
    array[i] = rand() % MAX;
  }
}

/*
 * prints out all the values in the input array separated by spaces
 */
void printArray(int *array, long length) {
  int i;
  for (i = 0; i < length; i++) {
    printf("%d ", array[i]);
  }
  printf("\n");
}

/*
 * prints out all the values in the counts array, separated by spaces
 */
void printCounts(long *counts) {
  int i;
  for (i = 0; i < MAX; i++) {
    printf("%ld ", counts[i]);
  }
  printf("\n");
}

/*
 * Compute the frequency of all elements in the input array
 * and store them in the counts array
 */
void *countElems(void *args) {
  struct t_arg *myargs = (struct t_arg *)args;
  long myid = myargs->id;
  long nthreads = myargs->numthreads;
  long length = myargs->length;
  int *arr = myargs->ap;
  long *counts = myargs->countp;

  // Local declaration of counts array for each thread.
  // This allows update to counts array for each thread without changing the shared values.
  long local_counts[MAX] = {0};

  /*
   * Assign work to threads
   */
  long chunk = length / nthreads;
  long start = myid * chunk;
  long end = (myid + 1) * chunk;
  long val;
  /* Assign the last element to the last chunk */
  if (myid == nthreads - 1) {
    end = length;
  }

  long i;
  /*Heart of the program */
  /*for (i = start; i < end; i++) {*/
  /*  val = arr[i];*/
  /*  // Each thread locks and unlocks the mutex n/t times,*/
  /*  // thus slowing down the loop's execution*/
  /*  pthread_mutex_lock(&mutex);*/
  /*  counts[val] = counts[val] + 1;*/
  /*  pthread_mutex_unlock(&mutex);*/
  /*}*/

  for (i = start; i < end; i++) {
    val = arr[i];
    local_counts[val] = local_counts[val] + 1;
  }

  pthread_mutex_lock(&mutex);
  for (i = 0; i < MAX; i++) {
    counts[i] += local_counts[i];
  }
  pthread_mutex_unlock(&mutex);

  return NULL;
}

/*
 * Overwrite the original array A using the frequencies stored in array counts
 */
void *writeArr(void *args) {
  struct t_arg *myargs = (struct t_arg *)args;
  long myid = myargs->id;
  long nthreads = myargs->numthreads;
  long length = myargs->length;
  int *arr = myargs->ap;
  long *counts = myargs->countp;

  /*
   * Assign number of values recorded in counts array to threads
   */
  long chunk = MAX / nthreads;
  long start = myid * chunk;
  long end = (myid + 1) * chunk;
  /* Assign the last element to the last chunk */
  if (myid == nthreads - 1) {
    end = MAX;
  }

  int i;
  long j = 0, amt;
  for (i = 0; i < MAX; i++) {
    amt = counts[i];
    while (amt > 0) {
      arr[j] = i;
      j++;
      amt--;
    }
  }
  return NULL;
}

int main(int argc, char **argv) {
  if (argc != 4) {
    fprintf(stderr, "usage: %s <n> <p?> <t>\n", argv[0]);
    fprintf(stderr, "where <n> is the length of the array\n");
    fprintf(stderr, "and <p?> is the print option (0/1)\n");
    fprintf(stderr, "and <t> is the number of threads\n");
    return 1;
  }
  /*Static seed ensures the same output every run.
   * If we run our program many times, random generator will behave similarly
   * each run.
   * */
  srand(10);

  long t;
  long length = strtol(argv[1], NULL, 10);
  if (length < 1) {
    print_error("ERROR: length must be greater than 0\n");
  }

  int verbose = atoi(argv[2]);

  long nthreads = strtol(argv[3], NULL, 10);
  if (nthreads < 1)
    print_error("ERROR: need a positive number of threads");
  if (length < nthreads)
    print_error("ERROR: length must be greater than nthreads");

  int ret;
  int *arr = malloc(length * sizeof(int));
  if (!arr)
    print_error("ERROR: malloc failed\n");

  genRandomArray(arr, length);

  long counts[MAX] = {0};
  pthread_t *thread_arr;
  thread_arr = malloc(nthreads * sizeof(pthread_t));
  struct t_arg *thread_args = malloc(nthreads * sizeof(struct t_arg));
  if (!thread_arr || !thread_args)
    print_error("ERROR: malloc failed");
  /*Fill thread array with params */
  for (t = 0; t < nthreads; t++) {
    thread_args[t].id = t;
    thread_args[t].numthreads = nthreads;
    thread_args[t].ap = arr;
    thread_args[t].length = length;
    thread_args[t].countp = counts;
  }

  pthread_mutex_init(&mutex, NULL);

  for (t = 0; t < nthreads; t++) {
    ret = pthread_create(&thread_arr[t], NULL, countElems, &thread_args[t]);
    if (ret)
      print_error("ERROR: pthread_create failed");
  }

  for (t = 0; t < nthreads; t++) {
    ret = pthread_join(thread_arr[t], NULL);
    if (ret)
      print_error("ERROR: pthread_join failed");
  }

  for (t = 0; t < nthreads; t++) {
    ret = pthread_create(&thread_arr[t], NULL, writeArr, &thread_args[t]);
    if (ret)
      print_error("ERROR: pthread_create failed");
  }

  for (t = 0; t < nthreads; t++) {
    ret = pthread_join(thread_arr[t], NULL);
    if (ret)
      print_error("ERROR: pthread_join failed");
  }

  pthread_mutex_destroy(&mutex);

  free(thread_arr);
  free(arr); // free memory

  if (verbose) {
    printf("counts array:\n");
    printCounts(counts);
  }

  return 0;
}
