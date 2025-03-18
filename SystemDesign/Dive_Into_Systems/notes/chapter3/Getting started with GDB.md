---
id: Getting started with GDB
aliases:
  - Getting started with GDB
tags: []
---

# Getting started with GDB

The `-g` flag adds extra debugging information to the binary executable file. The extra information helps the debugger _map machine code instructions to lines of C source code_

> [!WARNING]
> When compiling for debugging, AVOID compiler optimizations (do NOT build with `-O2`). The optimized code is challenging to debug since the machine code _cannot be clearly mapped back to the source code_.

```bash
gdb a.out
# or
ddd a.out
```

When a program terminates with an error, the OS dumps **a core file** containing the **state** of the program when it crashed. We can check this with:

```bash
gdb core a.out
```
