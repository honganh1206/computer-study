---
id: Offset of elements in an array
aliases:
  - Offset of elements in an array
tags: []
---

# Offset of elements in an array

The location of element index `i` is at an **offset** `i` from the base address of the array 

The exact address of the element index `i` depends on the **number of bytes** of the type stored in the array. Individual elements of each array are allocated to **contiguous** memory addresses

```c
int iarray[6];  // an array of six ints, each of which is four bytes
char carray[4]; // an array of four chars, each of which is one byte
```

Visualizing the addresses

```c
addr   element
----   -------
1230:  iarray[0]
1234:  iarray[1]

1238:  iarray[2]
1242:  iarray[3]
1246:  iarray[4]
1250:  iarray[5]

...

1280:  carray[0]
1281:  carray[1]
1282:  carray[2]
1283:  carray[3]
```
