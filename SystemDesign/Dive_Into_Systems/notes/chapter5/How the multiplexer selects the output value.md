
Case 1: `A = 1, B = 0, S = 1`

![[image-3.png|A two-way 1-bit multiplexer circuit chooses A when S is 1]]

 `S` is negated by the `NOT` gate before being sent to the top `AND` gate with B, thus the 0 output from the upper `AND` gate

`S` feeds into the bottom `AND` gate with `A` with the value 1, resulting in `(1 AND A)`. Since `A = 1`, the output of the lower `AND` gate is 1

The two outputs from the `AND` gates go through the `OR` gate, resulting in `0 OR A` as output with the final result is `A`

Case 2: Same as Case 1 but with `S = 0`

![[image-4.png]]

The negation of 0 is input to the top `AND` gate, resulting in `1 AND B` and the value of `B` is the output of the top `AND` gate

The input to the bottom `AND` gate is `0 AND A` resulting in 0 as the output value of the bottom `AND` gate

The final output is `(0 OR B) = B` 