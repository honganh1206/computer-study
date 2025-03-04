---
id: Arrays of Structs
aliases:
  - Arrays of Structs
tags: []
---

# Arrays of Structs

```c
// an array of 40 struct studentT
struct studentT classroom1[40];
// a pointer to a struct studentT
// (for a dynamically allocated array)
struct studentT *classroom2;
// an array of 40 struct studentT *
// (each element stores a (struct studentT *)
struct studentT *classroom3[40];
```

We can pass either a statically or dynamically allocated array of `struct`

```c
// Dynamically allocate an array of 15 studentT structs
// For classroom2 to point to
classroom2 = malloc(sizeof(struct studentT) * 15);
// Each element in array pointed to by classroom 2 is a struct
// So we can do this like statical arrays
classroom2[3].year = 2013;
updateAges(classroom1,40);
updateAges(classroom2,15);
```

```c
updateAges:
+--------------------------+
| classroom1:addr in heap | ---> +--------------------------------------------------+
+-------------------------+     |  0      |  1      |  2      | ...  | 14       |
                                | "Lars" | "Ruth" | "Leo"  | ...  | "ViJay"  |
main:                           |  19    |  20    |  18    | ...  |  21      |
+--------------------------+    |  3.0   |  3.8   |  3.2   | ...  |  3.4     |
| size: 15                |     | 2021    | 2020   | 2021   | ...  |  2019    |
| i: [ ]                  |     +--------------------------------------------------+
| classroom2: addr in heap|  ---> (Points to same heap memory)
+-------------------------+

         Stack                                      Heap
```
