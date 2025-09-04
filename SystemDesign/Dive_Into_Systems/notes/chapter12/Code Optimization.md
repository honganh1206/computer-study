We improve a program by reducing its code size, complexity, memory use, or runtime, or a combination of thereof *without changing the program's inherent functions*.

Many compilation systems include a *code optimizer* as an intermediate step, specifically an **optimizing compiler** which applies code-improving transformations.

For example, the GCC C compiler implements many *optimization flags* that *five user direct access to a subset of the implemented optimizations*.

The trade-off for optimized code is compile time and ease of debugging.

For simplicity, GCC wraps up a subset of optimization flags into different *optimization levels* the programmer can directly invoke:

```sh
$ gcc -01 -o program program.c
```


| Optimization level | Use                                                                                             |
| ------------------ | ----------------------------------------------------------------------------------------------- |
| 01                 | Basic optimizations to reduce code size and execution time                                      |
| 02                 | Include most of GCC's implemented optimizations, but do not involve space-performance trade-off |
| 03                 | Additional optimizations such as function inlining                                              |

> - In most cases,  fractional performance gains are not worth the hit to code readability.
> - A programmer should let the compiler optimize whenever possible.
