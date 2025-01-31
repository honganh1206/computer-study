---
id: Heap memory
aliases:
  - Heap memory
tags: []
---

# Heap memory

**EVERY BYTE** in a program's memory space has an address. Everything a program needs to run is _in its memory space_. Different types of entities reside in different parts of a program's memory space

The `Heap` and `Stack` sections are far from a program's [address space](./Address space.md) to leave a large amount of space for each when the programs runs

When a program requests memory at runtime, the heap _provides a chunk of memory whose address must be assigned to a pointer variable_

```c
+-------------------+  0
| Operating System  |
+-------------------+
|       Code        |
+-------------------+
|       Data        |
+-------------------+
|       Heap        |
|         6         |  <- Dynamic memory allocation (e.g., malloc in C)
+-------------------+
|       Stack       |
|       ptr ->      |  <- Pointer on the stack pointing to heap memory
+-------------------+  max
```

A pointer variable `ptr` on the `Stack` stores the address of dynamically allocated heap memory aka the `ptr` points to the heap memory

> [!IMPORTANT] Anonymous memory
> Heap memory is **anonymous memory**: Addresses in the heap are NOT bound to variable names, as programs variables are allocated on the `Stack` or the data part of program memory

A local pointer variable on the stack or a global one can _store the address of an anonymous heap memory location_. We can then dereference such a pointer to store data in the heap
