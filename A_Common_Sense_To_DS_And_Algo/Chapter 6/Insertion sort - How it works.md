---
tags:
  - "#study"
  - "#review"
cssclasses:
  - center-images
---
1. Temporarily **remove the value at index 1** and **store it in a temporary variable**. In subsequent passthroughs, **we remove the values at the subsequent indexes**

![[Pasted image 20240219143624.png]]
2. Shifting phase: Take the value to the left of the gap and compare it to the temporary variable. If the left value > temp value => we shift that value to the right
![[Pasted image 20240219144433.png]]
=> As the gap moves leftward, if we encounter a value lower than the temp value || reaching the end of the array => Shifting phase over

3. Insert the temp value to the current gap

![[Pasted image 20240219144514.png]]


4. Repeat step 1-3 until *the pass-through begins at the final index of the array*

> [!tip]
> 
> In programming terms, you can think of insertion sort as iterating through an array and **treating each element as a "key"** to be inserted into its correct position among the already sorted elements.

