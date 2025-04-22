---
id: Sign Extension
aliases: []
tags: []
---

When we perform arithmetic operations on two numbers of different number of bits, say 32-bit `int` and 16-bit `short`, the smaller number needs to be **sign extended**

Sign extension means we **repeat the most significant bit** of the number to extend its length to the target length

Say we want to extend the 4-bit sequence `0b0110` (6), we extend it by repeating the `0` bit to `0b000000110` (still 6)

```
0b1011 = -8 + 0 + 2 + 1 = -5
0b11011 = -16 + 8 + 0 + 2 + 1 = -5
```

See more

[[Zero extension and sign extension]]

