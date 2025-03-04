---
id: Pointer Arithmetic is type-aware
aliases:
  - Pointer Arithmetic is type-aware
tags: []
---

# Pointer Arithmetic is type-aware

An example of how values are stored in an array:

| Memory Address | Value      |
| -------------- | ---------- |
| 1000           | 1 (arr[0]) |
| 1004           | 2 (arr[1]) |
| 1008           | 3 (arr[2]) |
| 1012           | 4 (arr[3]) |
| 1016           | 5 (arr[4]) |

```c
int arr[3] = {1, 2, 3};
int* ptr = arr; // arr decays to &arr[0]
// ptr now points to the 1st element of the array
// When writing ptr + 1, the compiler calculates the new address as `new_address = ptr + (1 * sizeof(int))`
printf("%d\n", *(ptr + 1)) // 2nd argument is the value of the 2nd element in the original array and thus printing 2
```
