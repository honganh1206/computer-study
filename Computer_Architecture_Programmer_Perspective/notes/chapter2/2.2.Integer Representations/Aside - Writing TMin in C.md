---
tags:
  - "#study"
  - "#review"
  - "#programming"
  - "#clang"
cssclasses:
  - center-images
---
In `limits.c`, we have $TMin_{32}$ and $TMax_{32}$ as below:


```c
/* Minimum and maximum values a ‘signed int’ can hold.
*/
#define INT_MAX 2147483647
#define INT_MIN (-INT_MAX - 1)

```

Note that the asymmetry of two’s-complement representation forces us to write like that.