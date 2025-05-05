We can do so by changing the value of either `R` or `S` to 0. When `Q == 0`, `R` and `S` are set back to 1

> Both `R` and `S` cannot be 0 at the same time

Example: Assume `Q == 1` and to write  `Q == 0` we first set `R == 0`

![[image-12.png]]

This means that `R NAND a == 0 NAND 1 == 1 == ~Q` happens at the bottom NAND gate

The output `b == 1` also goes to the top NAND gate and thus `S NAND b == 1 NAND 1 == 0 == Q` changing the output