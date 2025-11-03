**False sharing** is the *illusion* that individual elements are being shared by multiple cores. To understand it, we revisit an example:

```c
void *countElems(void *args){
    //extract arguments
    //ommitted for brevity
    int *array = myargs->ap;
    long *counts = myargs->countp;

    //assign work to the thread
    //compute chunk, start, and end
    //ommited for brevity

    long i;
    //heart of the program
    for (i = start; i < end; i++){
        val = array[i];
        counts[val] = counts[val] + 1;
    }

    return NULL;
}
```

The execution as below:

| Time  | Thread 0                                          | Thread 1                                          |
| ----- | ------------------------------------------------- | ------------------------------------------------- |
| _i_   | Reads array[x] (1)                                | …​                                                |
| _i+1_ | Increments counts[1] (**invalidates cache line**) | Reads array[x] (4)                                |
| _i+2_ | Reads array[x] (6)                                | Increments counts[4] (**invalidates cache line**) |
| _i+3_ | Increments counts[6] (**invalidates cache line**) | Reads array[x] (2)                                |
| _i+4_ | Reads array[x] (3)                                | Increments counts[2] (**invalidates cache line**) |
| _i+5_ | Increments counts[3] (**invalidates cache line**) | …​                                                |

(There is no race conditions in this sample execution sequence, since each thread yields unique values) 

Since the `counts` array *fits on a single cache line* in the L1 cache (40 bytes fitting into a 64-byte cache line), any cache line containing `counts` is *invalidated* with every write to `counts` per MSI protocol (every time a program updates a shared variable, the _entire cache line in other caches storing the variable is invalidated_), even though different threads update different memory locations of `counts`.

It appears that all the cores are accessing the same elements of `counts`, even though this is not the case.

The repeated invalidation and overwriting of lines from the L1 cache is an example of **thrashing**, where *repeated conflicts in the cache cause a series of misses*.

> [!warning]
>Program can get slower even if we increase the number of threads, if we have to overwrite and invalidate multiple cache lines on a multicore system.

## Fixing false sharing

One solution is to *pad the array* with additional elements, so the array won't fit in a single cache line (thus avoiding invalidation). However, padding can waste memory, and this approach may not eliminate the problem from all architectures (as cache sizes between architectures and machines vary).

Another solution is to *have threads write to local (to a thread) storage whenever possible*.

```c
// local_counts accumulates frequencies instead of counts
for (i = start; i < end; i++){
    val = array[i];
    local_counts[val] = local_counts[val] + 1; //updates local counts array
}
```

Since the invalidation triggers only on writes to shared values, and `local_counts` is not shared among threads, a write to it will not invalidate its associated cache line.

```c
//update to global counts array
pthread_mutex_lock(&mutex); //acquire the mutex lock
for (i = 0; i < MAX; i++){
    counts[i] += local_counts[i];
}
pthread_mutex_unlock(&mutex); //release the mutex lock
```

Since `counts` is located on a single cache line, it will still get invalidated, but the penalty is `MAX x t (writes)`, which is much smaller than `n` writes.