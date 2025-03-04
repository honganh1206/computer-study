---
id: Single-Dimensional Arrays
aliases:
  - Single-Dimensional Arrays
tags: []
---

# Single-Dimensional Arrays

In [[[5-Arrays and Strings in C]], we know that a statically-declared array is either located on the stack (as a local variable) for the data region of memory (as a global variable). When we pass an array to a function, C copies the **base address** to the parameter, so if we modify the array through the array parameter, we also modify the values in the argument array 

We also know that [the base address of the array is also the address of the first element](./Why the base address of a dynamically allocated array is also the address of the first element.md) and [the location of an element in an array depends on the base address and type stored in an array](./Offset of elements in an array.md) 

