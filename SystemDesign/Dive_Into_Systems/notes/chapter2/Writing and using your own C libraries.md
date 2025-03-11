---
id: Writing and using your own C libraries
aliases:
  - Writing and using your own C libraries
tags: []
---

# Writing and using your own C libraries

Good practice: Divide large C programs into separate **modules** i.e., separate `.c` files. Definitions shared by more than one module are put in **header files** i.e., `.h` files. The C library code follows the same practice

Programmers often implement their own C libraries. The steps:

1. Define an _interface_ in a header `.h` file.
2. Implement the library in a `.c` file.
3. Compile the binary form of the library that can be linked into programs.

A library could be compiled into a binary archive `.a` or a shared object `.so`. However, the user cannot compile the code themselves (no access to the source code) and the user must **explicitly** link the executable file using `-l` command line option

> [!TIP]
>
> 1. Include `.h` file contents only ONCE to avoid duplicate definition errors at compile time
> 2. Write verbose comments in the header files
> 3. Use the `extern` keyword before ANY global variables to export it

Refer to the linking commands [here](./Creating my own library - A quick glance.md)
