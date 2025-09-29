> A latch is a type of digital circuit that stores/remembers a 1-bit value

A reset-set latch (RS latch) has two input values `S` and `R` and one output value `Q` (also as the value stored in the latch)

A RS latch might have another output `NOT(Q)`

![[image-10.png]]


Consider the following scenario where `Q == 1` then `~Q == 0`
<!--SR:!2025-09-26,1,230-->

![[image-11.png]]

The output of the top NAND gate `Q` is input `a` to the bottom NAND gate, while the output of the bottom NAND gate `~Q` is input `b` to the top NAND gate

When `R == 1` and `S == 1`,  the latch stores `Q` as `Q == 1` (stable)
<!--SR:!2025-09-26,1,230-->


With `Q == 1`, the feedback input value `a == Q == 1` to the bottom NAND gate. We then have `R NAND a == 1 NAND 1 == 0 == ~Q
<!--SR:!2000-01-01,1,250!2025-09-26,1,230!2000-01-01,1,250-->

The feedback input value of the bottom NAND gate is `b == ~Q == 0` combines with `S` to produce `S NAND b == 1 NAND 0 == 1 == Q`
<!--SR:!2025-09-26,1,230!2000-01-01,1,250-->

> This latching mechanism allows us to **continuously** store the value of `Q == 1` with `S == R == 1`
<!--SR:!2025-09-29,4,270-->

[[Changing the value of Q]]