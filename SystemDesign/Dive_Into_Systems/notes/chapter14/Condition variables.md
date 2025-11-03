Condition variables *force a thread to block until a particular condition is reached*.

> [!tip]
> Condition variables are *always* used in conjunction with a mutex. The mutex enforces mutual exclusion, whereas the condition variable ensures that particular conditions are met before a thread acquires the mutex.

Condition variables must be initialized before being used, as well as destroyed after use.

We use `pthread_cond_wait` and `pthread_cont_signal` when using condition variables. The first function causes the calling thread to block on a condition, and the second function causes the calling thread to unblock/signal another thread that is waiting on the condition.