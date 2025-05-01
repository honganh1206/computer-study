![[image-6.png|A four-way MUX circuit with FOUR inputs A B C D and TWO select bits]]


Four three-input `AND` gates and one four-input `OR` gate

How it works:

![[image-7.png|C as the output when the Select input is 2]]

The `S` input value of 2 (`0b10` in binary) with `S0 = 0` and `s1 = 1` (from right to left)

The top `AND` gate gets the input `NOT(S0) AND NOT(S1) AND A == 1 AND 0 AND A`, resulting in 0

The second `AND` gate gets the input `S0 AND NOT(S1) AND B == 0 AND 0 AND B` resulting in 0

The third `AND` gate gets the input `NOT(S0) AND S1 AND C == 1 AND 1 AND C` resulting in 1

The fourth and final `AND` gate gets the input `S0 AND S1 AND D == 0 AND 1 AND D` resulting in 0

The final output through the `OR` gate is 1 as the value of `C`

