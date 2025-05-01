Used to *select/choose one of several values*

A $N$-way multiplexer has a set of $N$ input values and a single output value selected from one of the inputs

An **additional** input value `S` for **Select** encodes which one of the $N$ inputs is chosen for the output

Most basic two-way MUX selects between two 1-bit inputs: `A` and `B`

If the `S` input is 1, it will select `A` for output and `B` if `S` input is 0

| A   | B   | S   | out           |
| --- | --- | --- | ------------- |
| 0   | 0   | 0   | 0 (B’s value) |
| 0   | 1   | 0   | 1 (B’s value) |
| 1   | 0   | 0   | 0 (B’s value) |
| 1   | 1   | 0   | 1 (B’s value) |
| 0   | 0   | 1   | 0 (A’s value) |
| 0   | 1   | 1   | 0 (A’s value) |
| 1   | 0   | 1   | 1 (A’s value) |
| 1   | 1   | 1   | 1 (A’s value) |

Expression: `OUTPUT = (S AND A) OR (NOT(S) AND B)`

![[image-2.png|The value of signal input S decides whether to choose A or B as output]]

[[How the multiplexer selects the output value]]

