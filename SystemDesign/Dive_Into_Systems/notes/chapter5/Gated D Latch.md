A [[RS Latch]] with more circuitry to ensure that it **never** receives an input of 0 to both `R` and `S`

![[image-13.png]]

The data input `D` is the value to store in the circuit, and the Write Enable (WE) *controls the writing value* to the RS latch

When `WE == 0`, the output from both leftmost NAND gates is 1, thus `R == S == 1` regardless of whether `D == 1` or `D == 0`

Why? Because the data input `D` is **inverted** before it is sent to the bottom NAND gate, and the input of either the top or bottom NAND gate could be 1

When `WE == 0` either `R` or `S` is 1