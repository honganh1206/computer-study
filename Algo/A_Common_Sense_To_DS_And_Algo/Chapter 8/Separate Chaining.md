---
tags:
  - "#study"
  - "#review"
cssclasses:
  - center-images
sr-due: 2025-09-28
sr-interval: 3
sr-ease: 250
---
- When a collision occurs, instead of placing a single value in a cell, we place a **reference** to an array

![[Pasted image 20240306165621.png]]


=> This array contains **subarrays** where the first value is the word, and the second value is its synonym.

- If we look for the synonym of the word "dab", the computer hashes the value -> Look at the cell -> Perform a linear search through subarrays -> Return the value at index 1

> [!tip]
> 
> In a worst-case scenario, a hash table performing a linear search has a time-complexity of $O(N)$