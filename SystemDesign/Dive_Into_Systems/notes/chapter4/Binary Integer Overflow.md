---
id: Binary Integer Overflow
aliases: []
tags: []
---

## Unsigned Overflow

If performing produces a smaller result, the addition has caused unsigned overflow

Shortcut: The $\text{Carry}_\text{in}$ must match the $\text{Carry}_{out}$

For addition ($\text{Carry}_{in} = 0$), the result should be **larger** than the 1st operand

For subtraction ($\text{Carry}_{in} = 1$), the result should be **smaller** than the 1st operand

## Signed Overflow

There is still a discontinuity in the modular number space, but because _a signed interpretation allows negatives, the discontinuity does not occur around 0_. Thus, it is **always safe** to generate a result that moves closer to zero

## Detecting Overflow

Systems detect overflow by _comparing the most significant bit of the operands with the most significant bit of the result_

```bash
+70 → 0100 0110
+90 → 0101 1010

# Overflow occured
  0100 0110
+ 0101 1010
------------
  1001 1100 → Result: -100 (in two's complement)
```
