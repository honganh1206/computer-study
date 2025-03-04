---
id: 5-3-Structs in C
aliases:
  - 5-3-Structs in C
tags: []
---

# 5-3-Structs in C

A way to create a collection of data elements of **different types**

A `struct` provides a _level of abstraction_ on top of individual data values, treating them as a **single type** and the whole block is treated as a **single unit**

Structs in C are **value types**.

> [!TIP]
> C is not an object-oriented language and thus it does not have classes. However, it supports defining structured types aka _the data part of classes_

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

C struct types are **lvalues** meaning _they can appear on the left side of an assignment statement_ e.g. `student2 = student1;`

The value of a struct variable is the **contents** of its memory, as the struct itself is a **container** for its members. Here is an example:

```c
// The struct's value is the contents of x and y
struct Point p1 = {10, 20};
```

A struct variable can be assigned the value of another struct variable. The field values of the struct on the right side are **copied** to the field values of the one on the left to the field values of the one on the left

```c
student2 = student1;
 // student2 gets the value of student1
// (student1's field values are copied to
// corresponding field values of student2)
strcpy(student2.name, "Frances Allen");
 // change one field value
```

[[Passing structs to functions]]
