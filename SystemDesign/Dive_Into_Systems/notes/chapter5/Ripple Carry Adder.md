 The 1-bit adder circuit for the $0^{th}$ bits (the least significant bits) receives a value of 0 for its `CARRY IN` from another part of the CPU circuitry that decodes the ADD instruction

![[image-1.png]]

The `SUM` ripples through the circuit from the low-order to the high-order bits

Only after bit $i^{th}$ of the `SUM` and `CARRY OUT` values are computed will the bit $(i+1)^{th}$ of the `SUM` and `CARRY OUT` be correctly computed (This is how [[Binary Integer Arithmetic]] works under the hood)