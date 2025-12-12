---
tags:
  - "#study"
  - "#review"
cssclasses:
  - center-images
sr-due: 2024-12-12
sr-interval: 59
sr-ease: 250
---
- We see whether a particular value exists within an array and if the value exists, we check index it is located. We then return the index.

> [!info] Reading vs. Searching
> A computer has **immediate access** to all of its memory addresses, but it has **no idea** offhand what values are contained at each memory address.


- When looking for a value inside a memory address, the computer has to *inspect each cell one at a time*
- Steps to take: $n$ steps to look for the right value in $O(n)$