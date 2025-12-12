---
tags:
  - "#study"
  - "#review"
cssclasses:
  - center-images
---
- As the computer *always keeps track of the array's size*, inserting an item to an array means adding it to the **next** memory address

![[Pasted image 20240103220420.png]]


- When inserting a new element at the *beginning*/middle of an array, we need to **shift** pieces of data to make room for the insertion
- Steps to take
	- Best case (insertion at the end) - $O(1)$
	- Worst case (insertion at the beginning) - $O(n+1)$