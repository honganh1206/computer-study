POSIX stands for **Portable Operating System Interface**, an IEEE standard specifying *how UNIX systems look, act and feel*.

A program can start as a single-threaded process, and later on it accumulates [[Threads]] to become a multithreaded process.

Two major steps of multithreading:

- The **creation** step, in which *the main thread spawns one or more worker threads*. After the spawn, each worker thread runs within its own execution context *concurrently* with other threads and processes. We use `pthread_create` for this.
- The **join** step, in which *the main thread waits for all workers to complete before proceeding as a single-threaded process*.  We use `pthread_join` for this.
	- When we join a thread that has terminated, we *free the thread's execution context and resources*. 
	- When we join a thread that has NOT terminated, that action *blocks* the caller until the thread terminates