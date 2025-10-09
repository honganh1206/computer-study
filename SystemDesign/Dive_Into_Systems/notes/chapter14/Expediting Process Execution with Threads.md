We speed up the execution of a single process by *decomposing* it to [[Threads]]

![[image-2.png|In a multithreaded process, threads share the call stack memory]]

The OS speeds up the execution of a multithreaded program by scheduling different threads to *run of separate cores*. 

> The maximum number of threads == the number of physical cores. If the former exceeds, the remaining threads must wait for their execution turn.

Below are examples of running four threads on a single core CPU, dual-core CPU and quad-core CPU. In general, if the number of threads matches the number of cores (c) and the OS schedules each thread to run on a separate core in parallel, *the multithreaded process should run in approximately 1/c of the time*.

![[image-3.png|Running on a single-core CPU]]

![[image-4.png|Running on a dual-core CPU]]
![[image-5.png|Running on a quad-core CPU]]


> [!warning]
> If there are multiple multithreaded processes waiting to use the CPU, they will all compete for the limited number of cores. This results in **resource contention** among the processes.

