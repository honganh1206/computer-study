---
id: Right Shifting
aliases:
  - Right Shifting
tags: []
---

# Right Shifting

Bits moving to the left are truncated, and new bits appearing from right to left must be either all ones or all zeros

A **logical right shift** prepends zeros the high-order bits of the result, while a **arithemtic right shift** copies the shifted value's most significant bit into the new bit positions

```bash
1011 0011 >> 2 -> 00101100 # Logical
1011 0011 >> 2 -> 11101100 # Arithmetic
```

See more

[[The right shift operation behaves a bit differently]]
