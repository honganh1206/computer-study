---
tags:
  - "#study"
  - "#review"
cssclasses:
  - center-images
sr-due: 2024-11-09
sr-interval: 26
sr-ease: 250
---

Set is a type of data structure that **does NOT allow duplicated values** to be contained within it.

## The four operations

- Read: 1 step
- Search: $n$ steps
- Insert: *Every insertion into a set require a search to ensure no duplicated element* 
	- Best case: Insert at the **end** of the set - $n+1$ steps
	- Worst case: Insert at the **beginning** of the set - $2n + 1$ ($n$ steps needed more to *shift all elements to the left*)