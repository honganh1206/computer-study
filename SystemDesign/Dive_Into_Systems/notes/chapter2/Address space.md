---
id: Address space
aliases:
  - Address space
tags: []
---

# Address space

When launching a new program, the OS allocates the new program's **address space**--storage locations for everything the program needs for its execution

A program's address can be described as **an array of addressable bytes**, and each address stores all or part of a program instruction or data value

A program's memory space is _divided into several parts_. Each part is used to _store a different kind of entity in the process's address space_

```
+-----------------------------+ -- Lowest addresses
|       Operating System      |
+-----------------------------+
| Code:                       |
|   Function instructions     |
+-----------------------------+
| Data:                       |
|   Global variables          |
+-----------------------------+
| Heap:                       |
|   Dynamically allocated     |
|   memory (grows as needed)  |
+-----------------------------+
| Stack:                      |
|   Local variables and       |
|   parameters (grows and     |
|   shrinks with function     |
|   calls and returns)        |
+-----------------------------+ -- Highest addresses
```

The top part is reserved for the OS to use, but the rest is for the running program. The `Code` section stores instructions like `main()`, `max()` and `change()`

Local variables and parameters reside in the `Stack` as it grows and shrinks over the program's execution. The `Stack` is stored _near the bottom of memory_ aka the highest memory addresses to leave space for changes

> [!IMPORTANT]
> Stack storage space for local variables and parameters only exists _when the function is active_

The `Data` section storing global variables _does not grow or shrink_ but persists for the entire run of the program

The `Heap` section is associated with **dynamic memory allocation** and it is _far from stack memory_ so it can _grow into higher addresses_ as more space is dynamically allocated
