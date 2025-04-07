---
id: Memory leak
aliases:
  - Memory leak
tags: []
---

# Memory leak

A memory leak is a chunk of allocated heap memory that is _not referred to by any pointer variable_ in the program, and thus cannot be freed

```c
ptr = malloc(sizeof(int) * 10);
ptr = malloc(sizeof(int) * 5); // memory leak of first malloc of 10 ints
```

This causes the program to _run out of heap memory space_, and can lead to the program crashing or undefined behaviors
