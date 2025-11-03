Broadcasting is useful when *multiple threads are locked on a particular condition*.

Calling `pthread_cond_bradcast(&cond)` wakes up *all* threads blocked on condition `cond`

```c
// mutex (initialized in main)
pthread_mutex_t mutex;

// condition variable signifying the barrier (initialized in main)
pthread_cond_t barrier;

void *threadEx_v2(void *args){
    // parse args
    // ...

    long myid = myargs->id;
    int nthreads = myargs->numthreads;
    int *array = myargs->array

    // counter denoting the number of threads that reached the barrier
    int *n_reached = myargs->n_reached;

    // start barrier code
    pthread_mutex_lock(&mutex);
    *n_reached++;

    printf("Thread %ld starting work!\n", myid)

    // if some threads have not reached the barrier
	// Why the loop? The condition may change, so we need to re-test
	// also a final check of the condition variable before releasing the mutex
    while (*n_reached < nthreads) {
		// Sometimes a loop is errorneously woken up,
		// even though a condition is not met
        pthread_cond_wait(&barrier, &mutex);
    }
    // all threads have reached the barrier
    printf("all threads have reached the barrier!\n");
	// Release all threads, enabling them to continue execution
    pthread_cond_broadcast(&barrier);

    pthread_mutex_unlock(&mutex);
    // end barrier code

    // normal thread work
    for (i = start; i < end; i++) {
        array[i] = array[i] * 2;
    }
    printf("Thread %ld done with work!\n", myid);

    return NULL;
}
```