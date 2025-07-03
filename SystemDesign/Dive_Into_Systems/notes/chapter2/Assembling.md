---
id: Assembling
aliases:
  - Assembling
tags: []
---

# Assembling

Convert the assembly code into _relocatable binary object code_ like `myprog.o`

The result would be an **object file** containing machine-code instructions, but it will not be enough to run on its own

The `gcc` compiler will then produce _binary files_ in the format ELF (Executable and Linkable format)

```bash
gcc -c myprog.c

# See the Assembly after compilation
gcc -S myprog.c
```

We can view the inside of the binary files with:

```bash
objdump -d myprog.o
```
