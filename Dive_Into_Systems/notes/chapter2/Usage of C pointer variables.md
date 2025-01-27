---
id: Useage of C pointer variables
aliases:
  - Useage of C pointer variables
tags: []
---

# Usage of C pointer variables

C programs mostly use pointer variables for:

1. **Pass-by-pointers** parameters to write functions that can _modify their argument's value through a pointer parameter_
2. Dynamic memory allocation when a programmer does not know the size of a data structure at compile time
3. Resizing data structures as the program runs

Structure: `<type_name> *<variable_name>`

```c
int *ptr; // store the memory address of an int aka ptr "points to" an int
char *cptr; // store the memory address of a char (cptr "points to" a char)
```

We initialize a pointer by using the **address operator (&)** with a variable to get the variable's address value

```c
int x;
char ch;

ptr = &x; // ptr "points to" x
cptr = &ch; // cptr "points to" ch
cptr = &x; // ERROR: cptr can hold a char memory location
// (&x is the address of an int)
```
