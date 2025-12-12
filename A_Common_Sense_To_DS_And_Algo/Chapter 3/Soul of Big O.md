---
tags:
  - "#study"
  - "#review"
cssclasses:
  - center-images
---
- For an algorithm that takes 3 steps no matter how much data, it will still take $O(1)$, as the notation wants to **tell you the story of how the number of steps increased as the data changes**

![[Pasted image 20240117151322.png]]


> [!note] Same algorithm, different scenarios
> 
> - If we use linear search and find the value in the **1st cell of the array**, then we can say linear search is $O(1)$ in the *best-case* scenario
> - Big O Notation usually refers to the **worst-case scenario** and that is why we describe linear search as being $O(n)$