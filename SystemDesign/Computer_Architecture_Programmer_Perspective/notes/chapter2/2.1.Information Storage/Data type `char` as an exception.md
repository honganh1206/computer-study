---
id: Data type `char` as an exception
aliases: []
tags:
  -  #study
  -  #review
  -  #computer
  -  #programming
cssclasses:
  - center-images
---

Most data types encode `signed` (allow both positive and negative values) unless declared as `unsigned`, but the C standard does NOT guarantee that _it will by default treat `char` as signed data_.

```c
char a = -1;         // May behave differently based on the platform (signed or unsigned)
signed char b = -1;  // Guaranteed to be signed
unsigned char c = -1; // Will wrap around and result in 255 for 8-bit char

```

> [!tip]
> Programmers should use the declaration `signed char` to guarantee a 1-byte signed value.
