A **deadlock** can arise when *multiple synchronization constructs are incorrectly applied*.

A deadlocked thread is blocked from execution by another thread, but this thread is also blocked on a blocked thread. This is called a **gridlock** (cars in all directions cannot move due to being blocked by other cars) and it is a common real-world example.

Consider a scenario where multithreading is used to implement a banking application:

```c
// Each account has its own mutex
// to ensure no race conditions can occur when updating the balance
struct account {
    pthread_mutex_t lock;
    int balance;
};

void *Transfer_v1(void *args){
    //argument passing removed to increase readability
    //...

    pthread_mutex_lock(&fromAcct->lock);
    pthread_mutex_lock(&toAcct->lock);
	// Scenario: A and B (on different threads) transfer money to each other, then both threads will concurrently execute Transfer function.
	// In such scenario, both threads will try to acquire the lock the other thread is holding, thus blocking each other.
    fromAcct->balance -= amt;
    toAcct->balance += amt;

    pthread_mutex_unlock(&fromAcct->lock);
    pthread_mutex_unlock(&toAcct->lock);

    return NULL;
}

void *Transfer_v2(void *args){
    //argument passing removed to increase readability
    //...

	// Re-arrange the locks so each lock/unlock surrounds only the balance update statement associated with it.
    pthread_mutex_lock(&fromAcct->lock);
    fromAcct->balance -= amt;
    pthread_mutex_unlock(&fromAcct->lock);

    pthread_mutex_lock(&toAcct->lock);
    toAcct->balance += amt;
    pthread_mutex_unlock(&toAcct->lock);

    return NULL;
}
```

> [!warning]
> Deadlock is not unique to threads, and processes can deadlock with one another.