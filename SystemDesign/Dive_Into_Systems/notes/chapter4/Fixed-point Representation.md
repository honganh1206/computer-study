---
id: Fixed-point Representation
aliases:
  - Fixed-point Representation
tags: []
---

# Fixed-point Representation

Major exception: The digits after the binary point `.` represents powers of two but **raised to a negative value**

Example: Converting `0b000101.10` to decimal

$(0\times {2}^{4)}+ (0\times {2}^{3)}+ \dots + (0\times 2^{-2}) = 5.5$

![[Pasted image 20250414124636.png]]

With two bits after the binary point, the fractional portion of a number holds one of the four sequences: `00` $(.00)$, `01` $(.25)$, `10` $(.50)$, or `11`$(.75)$

Adding a third bit increases the precision to $0.125\space (2^{-3})$ and the pattern continues similarly

As the number of bits after the binary point is fixed, some computation may truncate/round the result.

Example is representing $0.375$ (`0b000000.011`) since we need a third bit after the binary point to store. For this reason, truncation yields a rounded result of $\frac{0.75}{2} = 0.25$

Sometimes the result of a sequence of computations might vary _according to the order in which they are performed_

```js
1. (0.75 / 2) * 3 = 0.75 // Should be 1.125
2. (0.75 * 3) / 2 = 1.125
```

