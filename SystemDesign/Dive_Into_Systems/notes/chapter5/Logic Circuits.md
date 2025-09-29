We will be designing a simple equality 1-bit circuit
## 1. Design a truth table for the circuit

| A     | B     | A == B output |
| ----- | ----- | ------------- |
| **0** | **0** | **1**         |
| 0     | 1     | 0             |
| 1     | 0     | 0             |
| **1**     | **1**     | **1**             |
A **conjunction** of expressions combines sub-expressions that evaluates to 0 or 1 with `AND`, and is itself 1 only when both of its sub-expressions evaluate to 1

## 2. Write an expression for when each circuit output is 1

[[How to write a logical expression using conjunction and disjunction]]

 Consider `A == 0` and `B == 0`. We then express each input when the output evaluate to 1
<!--SR:!2025-09-29,4,270-->

```bash
NOT(A)    # is 1 when A is 0
NOT(B)    # is 1 when B is 0
```

Then we create a conjunction by combining them with `AND`

```bash
NOT(A) AND NOT(B)    # is 1 when A and B are both 0
```

Finally we create a **disjunction** of each conjunction that evaluate to 1

```bash
(NOT(A) AND NOT(B) OR (A AND B)) # is 1 when A and B are both 0 and 1
```

## 3.Translate the expression to a sequence of logic gates

Here the circuit designers employ techniques to *simplify the expression to create a minimal equivalent expression* - one that corresponds to the fewest operators and/or shortest path lengths of gates through the circuit

Tip: **Start from the innermost expression and work outward**

![[Pasted image 20250426162557.png]]

First set of gates: `NOT` gates of inputs `A` and `B`

Second set of gates: `AND` gate of input `A` and `B`

Third set of gates: Outputs of both `AND` gates are fed into the `OR` gate representing the disjunction

Verification by simulating all possible permutations

![[Pasted image 20250426163415.png]]

Abstract the implementation of the 1-bit equality circuit

![[Pasted image 20250426163457.png]]


[[Designing 1-bit XOR circuit using only AND OR and NOT gates]]


