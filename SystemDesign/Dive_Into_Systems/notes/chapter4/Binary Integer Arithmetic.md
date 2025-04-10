
See more

[[2.3.Integer Arithmetic]] (WIP)

## Addition

When adding two bits that are both 1, *the result carries out to the next digit* e.g., `1 + 1 = 0b10` requiring 2 bits to represent. This is similar to when we add two decimal digits that sum a value larger than9

| $\text{Digit}_A$ | $\text{Digit}_B$ | $\text{Carry}_\text{in}$ from previous digit | $\text{Result}$ | $\text{Carry}_\text{out}$ to the next digit |
| ---------------- | ---------------- | -------------------------------------------- | --------------- | ------------------------------------------- |
| 0                | 0                | 0                                            | 0               | 0                                           |
| 0                | 0                | 1                                            | 1               | 0                                           |
| 0                | 1                | 0                                            | 1               | 0                                           |
| 0                | 1                | 1                                            | 0               | 1                                           |
| 1                | 0                | 0                                            | 1               | 0                                           |
| 1                | 0                | 1                                            | 0               | 1                                           |
| 1                | 1                | 0                                            | 0               | 1                                           |
| 1                | 1                | 1                                            | 1               | 1                                           |

## Subtraction

Combination of addition + negation. Think of $7 - 3$ as $7 + (-3)$

Subtraction feeds the $\text{Carry}_{in}$ to the $d_{0}$ of the adder

A $\text{Carry}_\text{out}$ from the high-order bit does not indicate an overflow

## Multiplication and Division

Use the common pencil-and-paper strategy. We consider one digit at a time and add the result. Remember to shift the results from right to left 1 digit each time

Example: `0b0101` (5) and `0b0011` (3)


```
	0101
x   0011
--------
    0101
   0101
  0000
 0000
--------
    1111 (15)
```

For division, the fractional portion gets truncated in some languages, but in general we do the same thing most students learn in grade school