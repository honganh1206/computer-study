> [!summary]
> A multicore processor increases the **throughput**, not the speed, of process execution, so more processes can complete in a given period of time. While the CPU time remains the same, its wall-clock time may decrease.


![[image.png|Example of five processes executing on a single-core CPU]]

From the above example, we can see the two measures of time: The *CPU time* measures the amount of time process takes to execute on a CPU (computer-based), and the *wall-clock time* measures the amount of time a human perceives a process takes to complete (human perception-based).

We can see that some processes run concurrently with each other, since their executions overlap at some points. We can say that the processes are running **concurrently** with each other.

> [!information]
> During the single-core era, concurrency gave the illusion that a computer can execute many things at once e.g., run a calculator program while working on a web browser, etc., however, each process still executes *serially* and the OS determines  the order (It's still the same in the multicore era).

A multicore CPU enables the OS to *schedule a process to an available core*, thus allowing processes to execute **simultaneously**.

We call it **parallel execution**: Simultaneously executing instructions from processes running on multiple cores.

Below is an example of a dual-core system. One core is in dark blue, the other is in light green:

![[image-1.png]]

We can see the parallel execution increases the number of processes that execute at one time, as all processes complete execution by the time unit T7.
