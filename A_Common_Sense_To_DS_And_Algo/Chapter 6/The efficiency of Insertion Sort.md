---
tags:
  - "#study"
  - "#review"
cssclasses:
  - center-images
---
- Four types of steps occur in Insertion Sort: removals, comparisons, shifts, and insertions

### Comparison

- Take place each time **we compare the temp value with the leftward value**
- Worst-case scenario (Array sorted in reverse order) => Compare **each** number to the value on the left => $\approx \frac{N^2}{2}$ steps

### Shifting

- Take place each time we **move a value one cell to the right**
- Worst-case scenario (Array sorted in reverse order) => Every comparison forces us to shift a value to the right => $\approx \frac{N^2}{2}$ steps

### Removing & Inserting

- Removing & Inserting the temp value happens **once per pass-through** => $2.(N-1)$ steps

### Total

- Number of steps: $N^{2}+ 2.N-2$ steps 
- Time complexity: $O(N^{2} + N)$

> [!important]
> 
> Big O Notation only takes into account **the highest order of N** when we have multiple orders added together. That is, if we have an algorithm of $N^{4}+ N^{3}+N^{2}+N$, we only call the time complexity $O(N^4)$