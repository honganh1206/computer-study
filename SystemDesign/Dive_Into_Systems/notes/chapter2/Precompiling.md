---
id: Precompiling
aliases:
  - Precompiling
tags: []
---

# Precompiling

This step runs 1st and expand the _preprocessor directives_ like `#include` and `#define`

Syntax errors in this step might be due to not finding header files associated with `#include` directive

```bash
# View the immediate result with -E
gcc -E myprog.c > out
```
