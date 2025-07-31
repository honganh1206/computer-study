---
id: How structs work with the compiler
aliases:
  - How structs work with the compiler
tags: []
---

# How structs work with the compiler

TLDR: When you declare a struct variable, the compiler allocates some memory to it. The value of a struct is the **actual data stored in that memory block**. All members of a struct are _stored directly in the memory_ allocated to the struct variable

Only the struct variable's fields (the areas in boxes) are stored in memory

Fields are simply **storage locations** or _offsets_ from the start of the struct variable's memory. When looking at the example below, note that to access the field name `gpa`, the compiler must _skip past the array `name`, and one integer `age`_

```js
student1:
+-----------+-----------------------------------+
| Field     | Stored values (memory space)     |
+-----------+-----------------------------------+
| name      | 'K' | 'w' | 'a' | 'm' | 'e' | ' ' | ... |
+-----------+-----------------------------------+
| age       |                20                |
+-----------+-----------------------------------+
| gpa       |                3.5               |
+-----------+-----------------------------------+
| grad_yr   |               2020               |
+-----------+-----------------------------------+
```

Think of it this way:

- A struct is like a _blueprint_, and it tells the compiler to organize pieces of data in a **consecutive** block of memory large enough to hold all the field
- Each field is an offset (an address relative to the starting point of the structure) and they are laid out **sequentially**

```js
Memory Address:     0      64     68     72
                   |      |      |      |
                   v      v      v      v
                   +------+------+------+
                   | name | age  | gpa  |
                   +------+------+------+
                   <-64B-> <-4B-> <-4B->

```

The order of accessing `gpa`: Start at the base address of the student variable -> Skip 64 bytes of the `name` field -> Skip past 4 bytes of the `age` field -> Access the memory at the location with offset = 68 bytes

```c
struct studentT student;
// Assuming student starts at memory address 1000

// When you write:
student.gpa = 3.5;

// The compiler effectively does:
// Base address (1000) + offset for name (64) + offset for age (4) = 1068
// Then writes 3.5 at address 1068
```

> [!IMPORTANT]
>
> - The compiler handles all offset calculations **automatically**
> - The exact size depends on the **system architecture** and the compiler
> - There might be padding between fields (See [[x64 alignment policy]])
> - Offsets are calculated at **compile time**
