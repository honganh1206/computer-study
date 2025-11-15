POSIX threads  are an example of **explicit parallel programming** of threads, and the programmer must exactly specify what each thread is required to do, when to start and stop.

If we use Pthreads to add incremental parallelism to an existing sequential program, we must rewrite the entire program to use threads, and that is often not desirable.

The **Open Multiprocessing (OpenMP)** library implements the *implicit* alternative to Pthreads.

OpenMP enables programmers to parallelize components by adding **pragmas** (special compiler directives) to parts of the code like `#pragma omp`

## Common Pragmas

`#pragma omp parallel`: Create a team of threads and have each thread run the code in its scope. Equivalent to `pthread_create` and `pthread_join`

`#pragma omp for`: Specify each thread to execute a subset of iterations of a `for` loop. OpenMP makes *dynamic scheduling* (request a new set of iterations when a thread completes the assigned iteration) easier

`#pragma om parallel for`: Combination of the two above, generate a team of threads before assigning each thread a set of iterations.

`#pragma omp critical`: Treat the code under its scope as critical, meaning only one thread should execute the section at a time to ensure correct behavior.

