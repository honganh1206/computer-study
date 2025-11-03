Mutual exclusion (or **mutex** for short) locks are a type of *synchronization primitive* that ensures *only one thread enters and executes the code inside the critical section at any given time*.

Before using a mutex, a program must:

1. Declare the mutex in memory shared by threads (often as a global variable)
2. Initialize the mutex before the threads need to use it (often in `main` function)

```c
pthread_mutex_t mutex; // Declare a mutex
pthread_mutex_init(&mutex, NULL); // Init a mutex in main
pthread_mutex_destroy(&mutex); // Release a mutex
```

A thread must first acquire a lock by calling the `pthread_mutex_lock` function.

After a thread has a lock, no thread can enter the critical section until the thread with the lock releases it.

If another thread calls `pthread_mutex_lock` and the mutex is already locked, the thread must wait until the mutex becomes available (Recall [[Process State]]).

When a thread exits the critical section, it must call the `pthread_mutex_unlock` function to release the mutex.

> [!warning]
> Locking and unlocking a mutex are *expensive* operations, since calling a function repeatedly (and needlessly) in a loop can be a major cause of slowdown (Recall function inlining in [[Code optimization techniques from the compilers]])

It is recommended that we *lock and unlock functions as little as possible* and *reduce the critical section to the smallest possible size*.

> [!tips]
>z Use the lock and unlock functions as little as possible, and reduce the critical section to the smallest possible size. 
> This could be done by using local variables to collect intermediate values, and after the hard word requiring parallelization is over, use a mutex to safely update the shared variables.

Each thread should have its own subset of data to prevent risk of a race condition on data

[[Deadlock]]