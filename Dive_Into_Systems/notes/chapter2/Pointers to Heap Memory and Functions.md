---
id: Pointers to Heap Memory and Functions
aliases:
  - Pointers to Heap Memory and Functions
tags: []
---

# Pointers to Heap Memory and Functions

When we pass a dynamically allocated array to a function, it is the **value** of the pointer variable argument is passed instead (i.e., the [**base address** of the array](./Dynamically allocated arrays and strings.md) in the heap)

The same function can be used for both statically and dynamically allocated array, and the parameter declarations `int *arr` and `int arr[]` are **equivalent**. However, by convention, the pointer syntax is used for dynamically allocated arrays

```c
void init_array(int *arr, int size) {
  int i;
  for (i = 0; i < size; i++) {
    arr[i] = i; // Dereferencing happen here. This is equivalent to *(arr + i)
  }
}
```
