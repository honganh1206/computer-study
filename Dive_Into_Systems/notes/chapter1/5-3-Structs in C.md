---
id: 5-3-Structs in C
aliases:
  - 5-3-Structs in C
tags: []
---

# 5-3-Structs in C

A way to create a collection of data elements of **different types**: A `struct` provides a _level of abstraction_ on top of individual data values, treating them as a **single type**

C is not an object-oriented language and thus it does not have classes. However, it supports defining structured types aka _the data part of classes_

```c
struct <struct_name> {
    <field 1 type> <field 1 name>;
    <field 2 type> <field 2 name>;
    <field 3 type> <field 3 name>;
...
};

// Sample
struct studentT {
    char name[64];    // 64 bytes
    int age;          // 4 bytes (typically)
    float gpa;        // 4 bytes (typically)
    int grad_yr;        // 4 bytes (typically)
};
```

The name of the new struct type should be **two words**: `struct studentT`

[How structs work with the compiler](01-Areas/Computer/Dive_Into_Systems/notes/chapter1/How%20structs%20work%20with%20the%20compiler.md)
