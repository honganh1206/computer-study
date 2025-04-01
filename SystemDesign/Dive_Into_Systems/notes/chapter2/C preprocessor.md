---
id: C preprocessor
aliases:
  - C preprocessor
tags: []
---

# C preprocessor

Use the text-substitution marcros

Allow generating and modifying C code by using a separate macro language in the rest of the normal C code

How does it work? We evaluate this separate language before compiling the C code

```c
#define GREETING "Hello there"
int main(int argc, char *argv[])
{
#ifdef DEBUG // Check if preprocessor variable DEBUG is defined
  printf(GREETING " Debug-Mode!\n");
#else
  printf(GREETING " Production-Mode!\n");
#endif
}
```
