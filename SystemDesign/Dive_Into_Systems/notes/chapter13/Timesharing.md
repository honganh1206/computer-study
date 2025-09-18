General-purpose OSes often implement **timesharing** - the OS schedules each process to *take turn* executing on the CPU for short time durations a.k.a time slice or quantum. When a process completes its time slice on the CPU, the OS removes the process from the CPU and lets another run.

Most systems define time slices to be a *few milliseconds* around $10^{\neg3}$ seconds.

> [!tip]
> For Unix systems, use `ps -A` to list all the processes running in the system, and `top` 

In timeshared systems, processes run *concurrently*, meaning *their executions overlap in time*. The OS allow the CPU to switch between running two processes.

