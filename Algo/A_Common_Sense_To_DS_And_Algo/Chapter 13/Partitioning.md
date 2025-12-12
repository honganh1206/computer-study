---
tags:
  - "#study"
  - "#review"
  - "#algorithm"
  - "#programming"
cssclasses:
  - center-images
---
We take a random number in the array as the **pivot** and make sure every number less/greater than the pivot ends up on the left/right of the pivot

![[Pasted image 20240505105253.png]]
### Steps

1. The left pointer **continuously moves one cell to the right** until it **reaches a value that is greater than or equal to the pivot**, and then stops.
2. The right pointer **continuously moves one cell to the left** until it **reaches a value that is less than or equal to the pivot**, and then stops or **when it reaches the end of the array**.
3. At this point there are two scenarios:
	- If *the left pointer has reached/gone beyond the right pointer*, we **move to Step 4** as all elements to the left of the left pointer < the pivot + All elements on the right > the pivot
	- If not, we **swap** the values between the two pointers and go back from Step 1 → 3

4. We swap the pivot with the value the left pointer is pointing to