A scenario in which *two threads attempt to write to the same location in memory* is a **data race** condition.

A **race condition** refers to any scenario in which *the simultaneous execution of two operations gives an incorrect result*.

Example: Running two threads on two separate cores of a multicore system. Each thread could be running different instructions of a particular function, or possibly the same instruction.

Consider the following function:

```c
void *countElems(void *args) {
  struct t_arg *myargs = (struct t_arg *)args;
  long myid = myargs->id;
  long nthreads = myargs->numthreads;
  long length = myargs->length;
  int *arr = myargs->ap;
  long *counts = myargs->countp;

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
  /*Heart of the program, but also where data races happen */
  for (i = start; i < end; i++) {
    val = arr[i];
    counts[val] = counts[val] + 1;
  }

  return NULL;
}
```

The `counts[val] = counts[val] + 1` represents the **read-modify-write** pattern, and it might be run by two threads during step `i`, leading to this issue:

| Time  | Thread 0                                        | Thread 1                                        |
| ----- | ----------------------------------------------- | ----------------------------------------------- |
| _i_   | Read counts[1] and place into Core 0’s register | …​                                              |
| _i+1_ | Increment register by 1                         | Read counts[1] and place into Core 1’s register |
| _i+2_ | Overwrite counts[1] with contents of register   | Increment register by 1                         |
| _i+3_ | …​                                              | Overwrite counts[1] with contents of register   |
Supposed `counts[1]` contains the value 60. 

In time step `i`, thread 0 reads `counts[1]` and places the value 60 in Core 0's register.

In time step `i+1`, *while* (important) thread 0 increments Core 0's register by 1 (to 61), the *current* value in `counts[1]` (60) is read into Core 1's register by thread 1.

In time step `i+2`, thread 0 updates `counts[1]` value to 61, while thread 1 increments the value stored in Core 1's register (60) by 1.

The result is that during time step `i+3`, the value `counts[1]` is overwritten by thread 1 with the value 61 and NOT 62 as expected, meaning `counts[1]` "lose" an increment.

We can see that even during the small gap between the read and write,  both threads write the same new value, since that line code span multiple machine instructions and non-atomic (See more in [[Atomic operations]])

