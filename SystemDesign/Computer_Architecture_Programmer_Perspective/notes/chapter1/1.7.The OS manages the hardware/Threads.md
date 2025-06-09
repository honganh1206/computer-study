---
tags:
  - "#study"
cssclasses:
  - center-images
---
A process can consist of *multiple execution units* called **threads**. Each thread runs in the context of the process + share the same code and global data.


> [!important] The rise of threads
> Threads are becoming an increasingly important programming model as the requirement for concurrency in network servers increases. Threads offer: 
> - Ability to **share data between multiple threads** unlike processes
> - Efficiency compared to processes

Each thread is an independent stream of execution. 

Example: Two programs have their own thread of independent execution, and these two threads can be scheduled by the OS to run "at the same time" on a multithreaded processor


