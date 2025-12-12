---
tags:
  - "#study"
  - "#review"
  - "#algorithm"
  - "#programming"
cssclasses:
  - center-images
sr-due: 2025-09-26
sr-interval: 1
sr-ease: 230
---
Scenario: An array of **8 values** we need to get the second-lowest value

1. Partition the array for the *1st time*. The pivot ends up in the *middle of the array*.
2. Supposed the pivot’s index is 5 => Pivot is the *fifth-lowest value* of the array
3. Take the sub-array on the left of the pivot then partition it for the *2nd time* => New pivot ends up in the third cell => New pivot is the *third-to-lowest value* of the original array
   
![[Pasted image 20240508172952.png]]

4. Partition the sub-array *3rd time* => The second-to-lowest value will end up on the correct spot within the original array