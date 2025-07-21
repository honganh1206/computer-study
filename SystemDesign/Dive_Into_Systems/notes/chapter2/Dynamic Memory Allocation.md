---
id: 2-4-Dymanic Memory Allocation
aliases:
  - 2-4-Dymanic Memory Allocation
tags: []
---

# 2-4-Dynamic Memory Allocation

Dynamic Memory Allocation (DMA) allows a C program to **request more memory as it's running** and a pointer variable to **store the address of the dynamically allocated space**

DMA _grants flexibility_ to programs that:

- Do not know the size of specific data structures until runtime
- Need for a variety of input sizes
- Need to allocate _exactly_ the size of data structures needed for a particular execution
- Grow/shrink the sizes of memory allocated when the programs run

[[Heap memory]]

[[malloc and free]] 

[[Dynamically allocated arrays and strings]]

[[Pointers to Heap Memory and Functions]]