---
id: Pointer Arithmetic
aliases:
  - Pointer Arithmetic
tags: []
---

# Pointer Arithmetic

A program can perform arithmetic on a pointer to _access any of the array's elements_. However, it is not really a good practice since _it is more difficult to debug_

When incremented, a pointer can [point to the next storage location of the type it points to](../chapter1/Pointer Arithmetic is type-aware.md)

[[The semantics of pointer arithmetic and the underlying arithmetic function]]

Pointer arithmetic works on dynamically allocated arrays too, but we must be careful when working with dynamically allocated multidimensional arrays

When working with [[Dynamically allocated 2D arrays]] we should **reset the pointer** for the 1st method, or we can just initialize the pointer to point to the base address for the 2nd method (contiguous blocks of memory)
