---
id: Debugging memory with Valgrind
aliases:
  - Debugging memory with Valgrind
tags: []
---

# Debugging memory with Valgrind

Valgrind highlights heap memory errors in program

Some memory error types:

1. Uninitialized memory

```c
int *ptr, x;
ptr = malloc(sizeof(int) * 10);
x = ptr[3]; // reading from uninitialized memory
```

2. Reading/Writing to an unallocated memory location

```c
ptr[11] = 100; // writing to unallocated memory (no 11th element)
x = ptr[11]; // reading from unallocated memory
```

3. Freeing already freed memory

```c
free(ptr);
free(ptr); // freeing the same pointer a second time
```

4. [[Memory leak]]

> [!WARNING]
> Even in a small program, it might be difficult to find the real error. Things get worse if a memory access error is in a different part of the program code.

Sometimes, _when a program seems to run fine for some input but crashes on other input_, it means there is a memory access error in the program

> [!WARNING]
> Valgrind cannot detect stack memory access errors at the same granularity as it does with heap memory

[[How to use Memcheck]]
