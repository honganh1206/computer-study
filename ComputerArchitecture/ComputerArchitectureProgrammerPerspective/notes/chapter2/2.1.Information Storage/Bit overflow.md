---
tags:
  - "#study"
  - "#review"
  - "#computer"
  - "#programming"
cssclasses:
  - center-images
sr-due: 2024-10-18
sr-interval: 4
sr-ease: 270
---
As computer representations only *use a limited number of bits* to encode a number, some operations can **overflow** when the results are too large to be represented.
	- Example: The expression $200 * 300 * 400 * 500 = 12,000,000,000$ yields −884,901,888 (bit value) *causes an overflow* in 32-bit representation for data type `int` (representing value from  $−2^{31}=−2,147,483,648$ as the *most negative number* to $2^{31}-1=2,147,483,647$ as the *most positive number*) 


> [!info]
> Integer computer arithmetic satisfies many of the familiar properties of true integer arithmetic. The expression $(500 * 400) * (300 * 200)$ still yields $−884,901,888$



