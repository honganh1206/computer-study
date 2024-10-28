---
tags:
  - "#study"
  - "#review"
  - "#programming"
  - "#computer"
cssclasses:
  - center-images
---
We beg to question: For a data type consisting of $w$ bits, what if we shift by $k$ bits with $k \geq w$? For example this expression: `int lval = 0xFEDCBA98 << 32;`

On many machines, the shift amount will be computed with the modulo operation, meaning the number of shifted bits will be the result of `k % w`

If k = 32 and w = 32, then `k % w = 0`, meaning there will be no changes.

If k = 34 and w = 32, then `k % w = 2`, meaning we will shift by 2 bits.
