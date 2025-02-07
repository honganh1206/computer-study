---
id: Double indexing
aliases:
  - Double indexing
tags: []
---

# Double indexing

Understand how double indexing is evaluated:

- `two_d_arr`: An array of pointers. It stores the **base address** of an array of `(int *)` values and its type is `int**`
- `two_d_arr[i]`: The ith index into the array of arrays. It stores an `(int *)` that represents the base address of **an array of `(int)` values**. Its type is `int*`
- `two_d_arr[i][j]`: The jth element pointed to by the ith element of the array of arrays. It stores an `int` value on row i, column j of the 2D array.
