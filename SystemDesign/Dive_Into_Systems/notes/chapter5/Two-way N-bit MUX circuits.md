![[image-5.png|A two-way 4-bit MUX built from four two-way 1-bit MUX circuits]]


 A two-way $N$-bit circuit needs $\log_{2}(N)$ bits for its Select input. In this case, the `S` input must be 2-bit wide

- `S=00` → connect D₀
- `S=01` → connect D₁
- `S=10` → connect D₂
- `S=11` → connect D₃

Why additional selection bits? With $\log_{2}(N)$ bits, $N$ **distinct** values can be encoded, one for selecting each of the $N$ inputs

Each distinct permutation of the $\log_{2}(N)$ Select bits is input with one of the $N$ input values to an `AND` gate. The result is *exactly one MUX input value* selected as the MUX output