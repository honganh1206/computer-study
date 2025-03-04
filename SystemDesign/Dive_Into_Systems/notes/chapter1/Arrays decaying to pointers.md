---
id: Arrays decaying to pointers
aliases:
  - Arrays decaying to pointers
tags: []
---

# Arrays decaying to pointers

When you use the name of an array in an expression like `int* ptr = arr;`, it is **implicitly converted to a pointer**

Why "decay"? Because _the array loses some of its original properties_ and becomes a simpler pointer type

[Pointer Arithmetic is type-aware](01-Areas/Computer/Dive_Into_Systems/notes/chapter1/Pointer%20Arithmetic%20is%20type-aware.md)

## Why?

Arrays in C are designed to be **lightweight**, so instead of passing the entire array, only a pointer to the first element is passed

## When?

Passing an array to a function

```c
void printArray(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
}

int main() {
    int arr[5] = {1, 2, 3, 4, 5};
    printArray(arr, 5); // arr decays to a pointer and prints 1 2 3 4 5
    return 0;
}
```

Using arrays in an expression

```c
int* ptr = arr + 2; // arr decays to a pointer, then pointer arithmetic is used
```

Assigning an array to a pointer

```c
int* ptr = arr; // arr decays to &arr[0]
```

## When NOT?

When using arrays with `sizeof` operator

```c
int arr[5] = {1, 2, 3, 4, 5};
printf("%zu\n", sizeof(arr)); // Prints 20 (5 * sizeof(int))
```

When using with address-of operator

```c
int(*ptr)[5] = &arr; // ptr is a pointer to an array of 5 integers
```
