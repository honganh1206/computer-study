---
id: Linking libraries in C
aliases:
  - Linking libraries in C
tags: []
---

# Linking libraries in C

A C library has an _application programming interface_ to the library, which is defined in the `.h` file and the _implementation_ of the library's functionality

Often the C source code is not exported to the user but rather available in a _pre-compiled binary form_. These files can be **linked** to an executable file by `gcc` during compilation time

Pre-compiled library code might be an archive file `somelib.a` containing several `.o` files that can be _statically linked at compile time_

For example, the implementation of the C string library is part of the standard C library `libc` that the `gcc` compiler _automatically_ links to every executable file it creates

A library consists of one or more `.c` files and may include header files internal to the library implementation

Libraries other than the C standard libraries need to be **explicitly linked** in with the `-l` option

```bash
# Full name of the lib should not be included in the -l argument
gcc -o myprog myprog.c -lpthread -lreadline
```

`gcc` can freely find the _most recent version_ of a library in the user's library path. It also allows the compiler to _dynamically link_ when both `.a` and `.so` files are available

The user can choose to _statically link_ the libraries

```bash
gcc -o myprog myprog.c --static -lpthread -lreadline
```
