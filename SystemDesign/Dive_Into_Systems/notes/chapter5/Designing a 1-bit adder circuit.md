Quite similar to how we design [[Logic Circuits]]. 

| A   | B   | SUM | CARRY OUT |
| --- | --- | --- | --------- |
| 0   | 0   | 0   | 0         |
| 0   | 1   | 1   | 0         |
| 1   | 0   | 1   | 0         |
| 1   | 1   | 0   | 1         |
Aside from two inputs, we have two outputs: One for the result of adding `A` and `B`, and the other for overflow or `CARRY OUT`

For each output `SUM` and `CARRY OUT`, create logical expression of when output value is 1

```bash
SUM: (NOT(A) AND B) OR (A AND NOT(B))     # 1 when exactly one of A or B is 1 - Case 2 and 3
CARRY OUT:  A AND B                       # 1 when both A and B are 1
```

If we have `XOR` gate we can express `SUM: (A XOR B)`

![[Pasted image 20250426194039.png]]

We can use this 1-bit adder circuit as a building block to build $N$-bit adder circuits to perform addition on values of different sizes
