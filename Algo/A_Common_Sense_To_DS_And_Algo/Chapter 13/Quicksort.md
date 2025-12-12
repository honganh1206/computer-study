---
tags:
  - "#study"
  - "#review"
  - "#algorithm"
  - "#programming"
cssclasses:
  - center-images
---
### Steps:

1. Partition the array => The pivot is in its proper place
2. Treat the left + right arrays as sub-arrays and repeat the steps 1 → 2 from Partition section 
3. Base case: A sub array that has zero or one element


[[The efficiency of quicksort]]

[[The best- and worst-case scenario of Quicksort]]

## Quicksort vs. Insertion sort

|                | Best case    | Average case | Worst case |
| -------------- | ------------ | ------------ | ---------- |
| Insertion sort | $O(N)$       | $O(N^2)$     | $O(N^2)$   |
| Quicksort      | $O(N\log N)$ | $O(N\log N)$ | $O(N^2)$   |
