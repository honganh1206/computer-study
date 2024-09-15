---
tags:
  - "#study"
cssclasses:
  - center-images
---
Caches memories work as a **staging areas** for information that the processor might need to fetch from.

![[Pasted image 20240910214358.png|Caches memories]]


L1 cache on the processor can hold **tens of thousands of bytes** and can be accessed **as fast as the register file**. L2 cache (larger than L1) connects with the processor via a special bus. It might be slower than L1, but still **5-10 times** faster than the main memory. L1 and L2 caches are implemented with *static random access memory* (SRAM). Modern systems have three levels of caching: L1, L2 and L3.

The idea behind caching is to **exploit locality** by *accessing data and code in localized regions*. Application programmers who understand cache memories can exploit them for performance gain (More in [[Chapter 6]])

