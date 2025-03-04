---
id: Dynamically allocating strings
aliases:
  - Dynamically allocating strings
tags: []
---

# Dynamically allocating strings

> [!WARNING]
> Many functions from `string.h` like `strcpy` and `strcat` will _assume_ the location the string pointer `char *` is pointing has sufficient memory. Thus, we as programmers must ensure that sufficient memory is available at the destination before invoking such functions.

String literals are not writable

```c
// THis will yield undefined results
char *mystr = "string literal value";
strcat(mystr, "string literals aren't writable");
```
