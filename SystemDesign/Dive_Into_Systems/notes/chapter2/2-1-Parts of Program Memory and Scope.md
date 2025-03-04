---
id: 2-1-Parts of Program Memory and Scope
aliases:
  - 2-1-Parts of Program Memory and Scope
tags: []
---

# 2-1-Parts of Program Memory and Scope

The **scope** defines the set of program code blocks in which _a variable is bound to a program memory location_ and can be used by program code

A global variable _remains permanently in scope_ and _can be used in any code in the program_ as **it is bound to one specific memory location**. For this reason, every global variable must have a unique name to uniquely identify a specific storage location

Local variables and parameters are only in scope inside the function they are defined. Space to store a parameter's value is allocated on the stack _when the function get called_, and that space is deallocated when the function returns

Each function invocation gets its own bindings for its parameters and local variables

> [!TIP]
> Avoid programming with global variables whenever it is possible. Using local variables and parameters is easier to debug and more space-efficient

[Address space](01-Areas/Computer/Dive_Into_Systems/notes/chapter2/Address%20space.md)
