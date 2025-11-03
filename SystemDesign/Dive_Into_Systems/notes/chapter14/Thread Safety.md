It is NOT always safe to assume that standard C library functions can be used "as is", since not all functions are *thread safe*.

## Re-entrancy

A function is **re-entrant** if it can be re-executed/partially executed by a function without causing issue (? this is rather broad? does this mean the function is deterministic?)

Re-entrant code ensures accesses to the global state of a program always result in that global state remaining consistent.

```c
// Re-entrant function: it safely modifies global state
void *increment(void *arg) {
    for (int i = 0; i < 100000; i++) {
        pthread_mutex_lock(&lock);
        global_counter++;
        pthread_mutex_unlock(&lock);
    }
    return NULL;
}
```


> [!warning]
> All thread safe code is re-entrant, but not all re-entrant code is thread safe.

Refer to this [list of thread-unsafe functions](http://pubs.opengroup.org/onlinepubs/009695399/functions/xsh_chap02_09.html)