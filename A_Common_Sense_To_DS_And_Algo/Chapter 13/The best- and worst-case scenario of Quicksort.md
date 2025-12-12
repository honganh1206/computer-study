---
tags:
  - "#study"
  - "#review"
  - "#algorithm"
  - "#programming"
cssclasses:
  - center-images
---
- Best-case: Pivot always **ends up smack in the middle of the sub array** after the partition. The time complexity would be $O(N\log N)$
- Worst-case: Pivot always **ends up on one side of the sub-array** instead of in the middle as the array is in perfect ascending/descending order
	- The pivot is consistently chosen as the smallest/largest in the sub-array, meaning each partition will result in **one sub-array with one fewer element than the original array**. The time complexity would be $O(N^2)$
