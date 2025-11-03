---
id: Barriers
aliases: []
tags: []
---

A **barrier** forces _all_ threads to reach a common point in execution before releasing the threads to continue executing concurrently.

Consider this example:

```c
void *threadEx(void *args){
    //parse args
    //...
    long myid = myargs->id;
    int nthreads = myargs->numthreads;
    int *array = myargs->array

    printf("Thread %ld starting thread work!\n", myid);
    pthread_barrier_wait(&barrier); //forced synchronization point
    printf("All threads have reached the barrier!\n");
    for (i = start; i < end; i++) {
        array[i] = array[i] * 2;
    }
    printf("Thread %ld done with work!\n", myid);

    return NULL;
}
```

We can see that no thread can start processing its assigned portion of the array _until every thread has printed out the message that they are starting work_.

