---
id: Dynamically allocated arrays and strings
aliases:
  - Dynamically allocated arrays and strings
tags: []
---

# Dynamically allocated arrays and strings

> [!TIP]
> C programmers often use `malloc` to allocate [arrays](../chapter1/5-1-Arrays in C.md) (using the `Heap`) instead of declaring them statically (using the `Stack`) for multiple reasons e.g., allocate memory for unknown array size, extend array lifetime, etc.

A successful call to `malloc` can allocate [one contiguous chunk of heap memory](./Heap memory.md). The return value from `malloc` is _the address of the start of this chunk of memory_ aka the **base address** of a dynamically allocated array in heap memory, which also _the address of the 1st element of the array_

[Why the base address of a dynamically allocated array is also the address of the first element](01-Areas/Computer/Dive_Into_Systems/notes/chapter2/Why%20the%20base%20address%20of%20a%20dynamically%20allocated%20array%20is%20also%20the%20address%20of%20the%20first%20element.md)

How much to request: Total number of bytes in each array element X Number of elements in the array

```c
int *arr;
arr = malloc(sizeof(int) * 20);
char *c_arr;
c_arr = malloc(sizeof(char) * 10); // allocate an array of 10 chars on the heap
```

How things work under the hood: The `int` pointer stores the **base address** of an array of 20 contiguous storage locations in heap memory

```c
// Array elements of both of these arrays are FAR APART in the heap, not contiguous
Stack                   Heap
+----------------+      +---------------------------------+
| arr:  [addr]  | --->  | 0  1  2  ...  19                |
| c_arr: [addr] | --->  | 0  1  2  ...  9                 |
+----------------+      +---------------------------------+
```

> [!IMPORTANT]
> While `malloc` returns a pointer to dynamically allocated space in heap memory, C programs store the pointer to _heap locations on the `Stack`_- not the `Heap` itself

Suppose that we have two types of arrays: `s_array` as a statically-typed array and `d_array` as a dynamically-typed array. While their types differ, _both arrays will evaluate to the base address of the array in memory_

While it is not suggested, we can also use the `*` operator to access array elements

```c
// Both work the same way - put 8 in index 0
d_array[0] = 8;
*d_array = 8;
```
