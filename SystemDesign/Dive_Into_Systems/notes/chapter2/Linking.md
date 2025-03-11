---
id: Linking
aliases:
  - Linking
tags: []
---

# Linking

Create a single executable file `.out` from relocatable binaries `.o` and libraries `.a` or `.so`

```bash
# Running without flags conbines all four steps to produce a single executable file
# Result is an a.out file
gcc myprog.c
```

The linker will verify any references to names (symbols) in a `.o` files that are _present_ in other `.o`, `.a` or other `.so` files. An example would be `gcc` finding `printf` in the standard C library `libc.so`

`gcc` then embeds **copies** of library functions from the `.a` files in the resulting `a.out` file. Thus, all calls to library functions by the application are **bound** to the locations in the `a.out` files

Example: A call to a library function named `gofish` means _replacing the use of function name_ with the address memory of a function stored in libray files

[[Runtime linking]]
