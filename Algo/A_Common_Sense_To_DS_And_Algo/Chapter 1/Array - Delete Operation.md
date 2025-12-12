---
tags:
  - "#study"
  - "#review"
cssclasses:
  - center-images
sr-due: 2024-12-06
sr-interval: 53
sr-ease: 290
---
- Eliminate the value at a particular index in **one step** $O(1)$ => ISSUE: There are gaps in the middle of an array
- SOLUTION: Shift elements to the left
- Steps to take
	- Worst case: Remove the value at index 0 - $O(n)$
	- Best case: Remove the last value - $O(1)$