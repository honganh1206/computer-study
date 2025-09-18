---
tags:
  - "#study"
cssclasses:
  - center-images
---
> Processes are **abstractions** for the processor, main memory, and I/O devices.

The OS provides the illusion that *the program is the only one running on the system*: The program seems to have **exclusive use** of *the processor, main memory, and I/O devices.* => The **process** provides such illusion as one of the most important + successful ideas in CS.

Example: A user may run two instances of Unix shell program along with a browser, and the OS creates three processes associated with these programs, and it also handles the switching between these processes.

A process == The OS’s **abstraction** for a running program. Multiple processes can run concurrently on the same system with each having exclusive use of the hardware.

[[Running concurrently]] 

A process includes the program's binary executable code, data and execution context. That context tracks the program's execution by *maintaining its register values, stack location, and the currently executing instruction*

[[Multiprogramming and Context Switching]]

[[Process State]]

[[Creating and destroying processes]]

