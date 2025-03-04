---
id: Method 1 - Single malloc
aliases:
  - Method 1 - Single malloc
tags: []
---

# Method 1 - Single malloc

This is **more memory efficient** since _the entire space for all `N x M` elements will be allocated AT ONCE_
No semantic difference: The `malloc` function returns the **starting address** of a contiguously allocated chunk of heap memory requested

A caveat: The programmer has to **explicitly** map 2D row and column indexing on top of this single chunk of heap memory space

Memory after the call to `malloc`

```c
+------------------+
|     Stack        |
|                  |
| two_d_array:     |
| addr in heap     |
| (9230)           |
+------------------+

Memory Mapping:
9230: [0][0]
9234: [0][1]
9238: [0][2]
9242: [0][3]
9246: [1][0]
9250: [1][1]
9254: [1][2]
9258: [1][3]
9262: [2][0]
9266: [2][1]
9270: [2][2]
9274: [2][3]
  ...   ...
```

The pointer variable for the 2D array is allocated _on the stack_

With only a single call to `malloc`, all elements are located close together in contiguous memory, and _each access requires only a single level of indirection_

> [!WARNING]
> The C compiler cannot differentiate between a 1D and 2D array, so the [double indexing](./Double indexing.md) syntax `([i][j])` CANNOT be used for statically declared 2D arrays. The programmer has to explicitly use `([i*M + j])` where `M` is the column dimension
