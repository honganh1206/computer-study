Truth table

| A   | B   | A XOR B |
| --- | --- | ------- |
| 0   | 0   | 0       |
| **0**   | **1**   | **1**       |
| **1**   | **0**   | **1**       |
| 1   | 1   | 0       |
`A XOR B` evaluates to 1 only when either `A` or `B` is 1

Expressions

```bash
NOT(A) # 1 when A is 0
B # 1 when B is 1

(NOT A) AND B # 1 when A is 0 and B is 1
((NOT A) AND B) OR (A AND (NOT B)) # 1 when either A or B is 1
```

Design the circuit

![[1-bit XOR circuit.svg]]