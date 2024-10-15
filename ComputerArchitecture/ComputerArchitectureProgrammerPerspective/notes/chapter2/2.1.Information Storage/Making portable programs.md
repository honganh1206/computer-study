---
tags:
  - "#study"
  - "#review"
  - "#computer"
  - "#programming"
cssclasses:
  - center-images
---
One aspect of portability is **to make program insensitive to the EXACT sizes of different data types**.

[[Lower bounds and upper bounds of different data types in C]]

Hidden word size dependencies have arisen as **bugs** e.g., An object of type `int` could be used to *store a pointer*. This might work fine on 32-bit programs but not 64-bit programs.