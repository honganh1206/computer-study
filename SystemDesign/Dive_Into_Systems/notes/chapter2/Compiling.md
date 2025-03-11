---
id: Compiling
aliases:
  - Compiling
tags: []
---

# Compiling

This step does the **bulk** of the compilation task: Translate C source code to machine-specific assembly code `myprog.s`

```bash
# View the intermediate result with -S. Output would be a .s assembly file with the same name
gcc -S myprog.c
# We can build .a or .so files
ar -rcs libmylib.a mylib.o
```
