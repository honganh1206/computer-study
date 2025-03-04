---
id: Method 2 - Multiple mallocs
aliases:
  - Method 2 - Multiple mallocs
tags: []
---

# Method 2 - Multiple mallocs

1. Allocate a 1D array of `N` pointers to the element type, with a 1D array of pointers _for each row_ in the 2D array
2. Allocate `N` 1D arrays of size `M` to store the set of column values for each row in the 2D array
3. Assign the addresses of each of these `N` arrays to the first array of `N` pointers

This requires `N + 1` calls to `malloc`: One for the array of row arrays, and one for **each** of the `N` row's column arrays. This means the element locations _within a row_ are contiguous, but elements are NOT contiguous across rows of the 2D array

This approach is not as efficient as [the 1st method](./Method 1 - Single malloc.md), and the type definition is more confusing, but it can use the [double indexing](./Double indexing.md) syntax `([i][j])`

```c
Stack:
-------------------------------------------------
| main:                                        |
|----------------------------------------------|
| two_d_array: addr in heap (pointing to 0)   |
-------------------------------------------------

Heap:
-------------------------------------------------
| Index | Memory Block (Heap)                  |
|----------------------------------------------|
|   0   | addr in heap ---> [ 0  |  1  |  2  | ... | M-1 ] |
|   1   | addr in heap ---> [ 0  |  1  |  2  | ... | M-1 ] |
|  ...  |               ...                   |
|  N-1  | addr in heap ---> [ 0  |  1  |  2  | ... | M-1 ] |
-------------------------------------------------
```

> [!IMPORTANT]
> Only the elements as part of a single call to `malloc` are contiguous in memory

[[Double indexing]]

## An array of arrays & Function Parameters
