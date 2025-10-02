> [!summary]
> - OSes implement two abstractions: [[Processes]] and [[Virtual Memory]] to handle multiprogramming.
> - The OS keeps track of all processes in a system and their state, and it also implements context switching of processes.
> - The OS also provides a way for processes to create new processes, to exit, and to communicate with each other.
> - The virtual memory abstraction protects processes from sharing the computer's physical memory space. [[Paging]] is one implementation.
> - Virtual memory space can be stored in RAM or on a disk, making RAM as a cache for disk.
> - Modern OSes implement support for interprocess communication methods like [[Signal]], [[Message passing]] and [[Shared memory]].
> - Most OSes include **hypervisor** support, allowing the host OS to run multiple virtual guest OSes.
> - Most OSes provide some degree of extensibility for the user to tune the OS to match the type of application workloads they run. These OSes can even support [[Loadable kernel modules]]


A *layer* sitting between the computer hardware and application programs. Its primary purpose is to *manage* the underlying hardware components to efficiently run program workloads.

The OS makes the computer *easy to use*: When the user double-clicks on an icon to start a program running on the underlying system, the OS *handles all the details of this operation* while hiding from users the low-level actions necessary to run the user's program.

The OS makes efficient use of system resources by implementing **multiprogramming**, which *allows more than a single program to run on the computer at a time*. How? The OS shares hardware resources among several programs running on the system.

To support multiprogramming, the OS needs to implement an *abstraction* of a running program called a **process**. The process abstraction enables the OS to *manage the set of multiple programs running in the system at any given time.*

[[The Kernel]]

[[Booting and Running]]

[[Processes]]

[[Virtual Memory]]

[[Interprocess Communication]]

[[Hypervisor and Virtualization]]

