---
id: 2-3-Pointers and Functions
aliases:
  - 2-3-Pointers and Functions
tags: []
---

# 2-3-Pointers and Functions

The **pass by pointer** pattern uses a pointer function parameter, and that parameter gets the **address** of some storage location passed by the caller

When we dereference the pointer parameter inside the function, the function can modify the value at the storage location. For instance, the caller passes the address of one of its local variables, and the invoked function dereference the pointer argument and modify the value

[Pass by value](01-Areas/Computer/Dive_Into_Systems/notes/chapter2/Pass%20by%20value.md)

[Pass by pointer](01-Areas/Computer/Dive_Into_Systems/notes/chapter2/Pass%20by%20pointer.md)
