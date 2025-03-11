---
id: The semantics of pointer arithmetic and the underlying arithmetic function
aliases:
  - The semantics of pointer arithmetic and the underlying arithmetic function
tags: []
---

# The semantics of pointer arithmetic and the underlying arithmetic function

The semantics of pointer arithmetic are **type-independent**: Changing any type of pointer's value by `N` (`ptr = ptr + N`) makes the pointer point `N` storage locations beyond its current value

(Might be referring to [this note](../chapter1/Pointer Arithmetic is type-aware.md))

The _actual_ arithmetic function that the compiler generates for a pointer arithmetic expression _varies depending on the type of the pointer variable_. An example is incrementing a `char` pointer will increase its value by one since the next valid `char` address is one byte from the current location
