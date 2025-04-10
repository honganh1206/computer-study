
Treat the high-order bit exclusively as a **sign bit** $d_{N-1}$. If it is equal to 1, the value is negative and otherwise

## Drawbacks:

Two representations of zero like `0b0000` and `0b1000` (negative zero). The hardware need to account for two possible binary sequences sharing the same value but have different bit values
 
 Inconvenient discontinuity between negative values and zero: A case would be `0b1111 + 1` will roll over back to `0b0000`