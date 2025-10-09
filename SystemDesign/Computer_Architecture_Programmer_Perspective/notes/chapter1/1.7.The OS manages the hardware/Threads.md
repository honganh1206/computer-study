---
tags:
  - "#study"
cssclasses:
  - center-images
---
A process can consist of *multiple execution units* called **threads**. Each thread runs in the context of the process + share the same code and global data.


> [!important] The rise of threads
> Threads are becoming an increasingly important programming model as the requirement for concurrency in network servers increases. Threads offer: 
jj> - Ability to **share data between multiple threads** unlike processes
> - Efficiency compared to processes

Each thread is an independent stream of execution. 

Example: Two programs have their own thread of independent execution, and these two threads can be scheduled by the OS to run "at the same time" on a multithreaded processor

While each thread has its own private allocation of call stack memory, **all threads share the program data, instructions and heap** allocated to the multithreaded process.

A **thread function** is analogous to a `main` function for a worker thread. Each thread executes the thread function using its *private execution state* i.e., its own stack memory and register values. 

Usually thread functions are of type `void*` (see more in [[Void type and type recasting]]).

> [!warning]
> Never make any assumptions about the order in which threads will execute. We use **synchronization** for our programs if we need threads run in a particular order.