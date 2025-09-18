Programmers often use a *process's completion time* as a metric to evaluate its performance. Example: When comparing two programs that calculate the prime factors of a large number, the one correctly completing the task faster is preferable.

Two different measures of the runtime of a process: 

## Wall time 

What? Elapsed time from the process's start to finish measured by clock hanging on the wall)

Include time in Running + Ready + Blocked states

In multiprogrammed and timeshared systems, the wall time of a process can slow down, as there are processes running concurrently.

## CPU time

CPU time measures just the *amount of time process spends on Running state*. As a result, a process's total CPU time is not affected by other processes