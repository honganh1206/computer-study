Tags: #review #computer #study 

## Principle

Let $\vec{x}, \vec{y}$ be bit vectors of length $w$, integers $x, y$ represented by these bit vectors in two's-complement form will be $x = \text{B2T}_{w}(\vec{x})$ and $y=\text{B2T}_{w}(\vec{y})$. 

Non-negative integers $x', y'$ representing these bit vectors will be $x' = \text{B2U}_{w}(\vec{x})$ and $y'=\text{B2U}_{w}(\vec{y})$/ Then we will have:

$$
\text{T2B}_{w}(x~*^{t}_{w}~y)=\text{U2B}_{w}(x'~*^{u}_{w}~y')
$$

The unsigned truncated product always equals $(x\times y)\text{mod}~8$

The table below shows the result of *multiplying different 3-bit numbers then truncating it to 3-bit numbers* (remove the first 3 bits?)

| Mode             | $x$ |         | $y$ |         | $x \times y$ |            | Truncated $x \times y$ |         |
| ---------------- | --- | ------- | --- | ------- | ------------ | ---------- | ---------------------- | ------- |
| Unsigned         | 5   | `[101]` | 3   | `[011]` | 15           | `[001111]` | 7                      | `[111]` |
| Two's-complement | -3  | `[101]` | 3   | `[011]` | -9           | `[110111]` | -1                     | `[111]` |
| Unsigned         | 4   | `[100]` | 7   | `[111]` | 28           | `[011100]` | 4                      | `[100]` |
| Two's-complement | -4  | `[100]` | -1  | `[111]` | 4            | `[000100]` | -4                     | `[100]` |
| Unsigned         | 3   | `[011]` | 3   | `[011]` | 9            | `[001001]` | 1                      | `[001]` |
| Two's-complement | 3   | `[011]` | 3   | `[011]` | 9            | `[001001]` | 1                      | `[001]` |

## Derivation

From equation 2.6 in [[Conversion from two-complement to unsigned]] when conversing from two's-complement to unsigned, we have $x'=x + x_{w-1}2^{w}$ and $y'=y + y_{w-1}2^{w}$. Computing these values then we have:

$$
\begin{align}
(x'\times y')\text{mod}~2^{w} = [(x + x_{w-1} 2^{w}) \times (y + y_{w-1}2^{w})]\text{mod}~2 \\ \\
= [x\times y + 2^{w}\times(x_{w-1}y + y_{w-1}x) + x_{w-1}y_{w-1} 2^{2w}$]\text{mod}2^{w} \\ \\
= (x\times y)\text{mod} 2^{w}
\end{align}
\quad \text{(2.18)}
$$

Note that the weights $2^{w}$ and $2^{2w}$ drop out due to *the modulus operator*. 

From equation 2.17 in [[2.3.5 Two-Complement Multiplication]] we also have this:

$$
\text{T2U}_{w}(x~*^{t}_{w}~y) = \text{T2U}_{w}(\text{U2T}_{w}(x\times y)\text{mod}~2^{w}) = (x\times y)\text{mod}~2^{w}
$$

The $\text{T2U}_{w}$ and $\text{U2T}_{w}$ cancel each other out. 

Combining equation 2.16 and 2.18 and then applying $\text{U2B}_{w}$ to have this:

$$\text{U2B}_{w}(\text{T2U}_{w}(x~*^{t}_{w}~y)) = \text{T2B}_{w}(x~*^{t}_{w}~y)=\text{U2B}_{w}(x'~*^{u}_{w}~y')$$