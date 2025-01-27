---
id: Rules for using pointer variables
aliases:
  - Rules for using pointer variables
tags: []
---

# Rules for using pointer variables

## Pointer type

We need to think about **two types**: The type of the pointer variable, and the type stored in the memory address to which the pointer variable points

Q: Why the two types? Aren't they the same?
A: No, the pointer's type includes information about _the data type it points to_, but the pointer type itself is a separate type, not similar to value type

> [!IMPORTANT] Why does a pointer have a type when it only stores an address?
> As the type of the pointer indicates the type of data it is pointing to, pointer having a type is useful for pointer arithmetic. [If you increment a pointer, it moves by the size of an integer, not just one byte](../chapter1/Pointer Arithmetic is type-aware.md)

The pointer type dictates _how the compiler interprets the data at the memory address_ and _ensure type safety during operations_

## NULL pointers

All pointer variables can be assigned the special `NULL` to indicate _an invalid address_

> [!TIP]
> A `NULL` pointer is useful when testing if a pointer variable points to a valid memory address
> We should NEVER dereference a NULL pointer, which might lead to undefined behaviors

## Dereferencing pointers

The **dereference pointer (\*)** follows a pointer variable to the location in memory that it points to and _access the value at that specific location_

```c
int x = 8;

ptr = &x;
*ptr = 8; // the memory location ptr is pointing to is assigned the value 8

```

> [!WARNING]
> If your program dereferences a pointer that _does not contain a valid address_, the program crashes like `ptr = NULL; *ptr = 6;`
