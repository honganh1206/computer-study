Private virtual address spaces are an abstraction to *prevent processes to interfere with others' execution state*. However, sometimes we need processes to communicate with one another (or sometimes share their execution state).

[[Signals]] are a very *restricted* form of interprocess communication, in which *one process sends a signal to another to notify it of some event*.

Processes can also communicate by [[Message passing]]: The OS implements an *abstraction of a message communication channel* for processes to exchange messages.

The OS may support interprocess communication through [[Shared memory]], which *allows a process to share all or part of its virtual address space with other processes*.

