The OS maintains information about each process:

- A process ID (PID) to uniquely identify a process (Use the `ps` command to list information about processes)
- The address space information of the process
- The execution state
- The set of resources allocated to the process
- The current process state to check eligibility for execution on the CPU

A process moves through several states throughout its lifetime, and such states correspond to process execution eligibility:

- **Ready**: The process could run on the CPU but is not currently scheduled (candidate for being context-switched). There are several ways for a process to enter the ready state: Examples are being created and initialized by the CPU or its time slice in a [[Timesharing]] system is up.
- **Running**: The process is scheduled on the CPU and is actively executing instructions.
- **Blocked**: The process is waiting for some event before it can continue being executed e.g., waiting for data to be read from disk. Blocked processes are not scheduled on the CPU and when they get unblocked, they move to ready state.
- **Exited**: The process has exited but it still needs to be completely removed from the system. A process exits for several reasons e.g., completing the execution, exiting with an error, receiving a termination request, etc., An exited process will never run again, but still requires final clean-up.

![[image-8.png|The states of a process during its lifetime]]


[[Process Runtime]]

