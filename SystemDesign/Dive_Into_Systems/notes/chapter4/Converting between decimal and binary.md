
We check the parity (even or odd) status of a decimal number and repeatedly dividing it by two to determine successive bits

For example, when converting 422:
- 422 is even, so d0 should be a 0. (This is the rightmost bit.)
- 422/2 = 211, which is odd, so d1 should be a 1.
- 211/2 = 105, which is odd, so d2 should be a 1.
- 105/2 = 52, which is even, so d3 should be a 0.
- 52/2 = 26, which is even, so d4 should be a 0.
- 26/2 = 13, which is odd, so d5 should be a 1.
- 13/2 = 6, which is even, so d6 should be a 0.
- 6/2 = 3, which is odd, so d7 should be a 1.-  3/2 = 1, which is odd, so d8 should be a 1.
- 1/2 = 0, so any digit numbered nine or above will be 0, and the algorithm terminates.