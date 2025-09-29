Note that building $N$-bit arithmetic circuits from $N$ 1-bit arithmetic circuits *requires more care* than building $N$-bit logical circuits from $N$ 1-bit logical circuits

When performing multibit addition/subtraction, individual bits are summed in order from **the least significant bit to the most significant one** i.e., from right to left

The `CARRY OUT` of the $i^{\text{th}}$ bit adder circuit is an *input value* to the $(i+1)^{\text{th}}$ bit adder circuit

We need the 3rd input `CARRY IN`

| A   | B   | CARRY IN | SUM | CARRY OUT |
| --- | --- | -------- | --- | --------- |
| 0   | 0   | 0        | 0   | 0         |
| 0   | 1   | 0        | 1   | 0         |
| 1   | 0   | 0        | 1   | 0         |
| 1   | 1   | 0        | 0   | 1         |
| 0   | 0   | 1        | 1   | 0         |
| 0   | 1   | 1        | 0   | 1         |
| 1   | 0   | 1        | 0   | 1         |
| 1   | 1   | 1        | 1   | 1         |
```bash
SUM = A XOR B XOR CARRY IN
```

![[01-Areas/Computer/SystemDesign/Dive_Into_Systems/notes/chapter5/image.png|1-bit adder circuit with three inputs]]

We use this 1-bit adder circuit to construct $N$-bit adder circuit by *feeding corresponding operand bits through individual 1-bit adder circuits* 

We then feed the `CARRY OUT` value from the $i^{th}$ adder circuit into the `CARRY IN` value of the $(i+1)^{th}$ 1-bit adder circuit

[[Ripple Carry Adder]]

Circuits for other arithmetic and logic functions are constructed in similar ways by *combining circuits and logic gates*. An example is `A - B` can be built from adder and negation circuits `(A + (-B))`