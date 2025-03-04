---
id: Pointers and structs
aliases:
  - Pointers and structs
tags: []
---

# Pointers and structs

We can declare a variable as a pointer to a user-defined `struct` type

We use the special operator `->` to derefer a `struct` pointer and access one of its field values

```c
// the gpa field of what sptr points to gets 3.5:
sptr->gpa = 3.5;
// the name field of what sptr points to is a char *
// (can use strcpy to init its value):
strcpy(sptr->name, "Lars");
```

What is going on under the hood:

```js

main:
+------------------+      +------------------+
| sptr: addr in heap| --> | "Lars"           |
|                  |      | 19               |
|                  |      | 3.5              |
|                  |      | 2021             |
+------------------+      +------------------+
| s: "Freya"      |
| 18              |
| 4.0             |
| 2020            |
+----------------+
  Stack                  Heap
```

## Pointer Fields in Structs

We can have pointer types as field values in a struct

```js

main:
+------------------+      +---------------------------+
| p1: addr in heap | --> | Z | h | i | c | h | e | n | \0 |
| 22               |      +---------------------------+
+------------------+
| p2: addr in heap | --> +------------------+      +-------------+
|                  |      | addr in heap    | ---> | V | i | c | \0 |
|                  |      | 19              |      +-------------+
+------------------+      +------------------+

  Stack                      Heap
```

> [!WARNING]
> As structs and the types of their fields increase in complexity, be careful with their syntax
