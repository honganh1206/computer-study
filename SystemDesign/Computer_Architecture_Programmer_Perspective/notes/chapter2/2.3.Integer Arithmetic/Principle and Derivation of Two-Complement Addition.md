Tags: #review #computer 
## Principle

For values $x, y$ such that $-2^{w-1} \leq x,y \leq 2^{w-1}-1$

$$
x +^{t}_{w} y =
\begin{array}{rcl}
& x + y - 2^{w}, & 2^{w-1} \leq x + y & \text{Positive overflow}\\
& x + y , & -2^{w-1} \leq x + y < 2^{w-1} & \text{Normal}\\
& x + y + 2^{w}, & x + y < -2^{w-1} & \text{Negative overflow}
\end{array}
$$

![[Figure 2-24.png]]

The $w$-bit two's-complement sum of two numbers has the exact same bit-level representation as the unsigned sum (explained in [[2.2.3. Two-Complement Encodings]]). 

## Derivation

Since the two's-complement addition has the *same bit-level representation* as unsigned addition, we can convert the arguments to unsigned -> perform unsigned addition -> convert back to two's-complement form.

$$
x +^{t}_{w} y = U 2 T_{w} (T 2 U_{w}(x) +^{u}_{w} T 2 U_{w}(y))
$$

By equation 2.6 ([[Conversion from two-complement to unsigned]]),  we can write $T 2 U_{w}(x)$ as $x_{w-1}2^{w}+x$ and $T 2 U_{w}(y)$ as $y_{w-1}2^{w}+ y$ accordingly. As $+^{u}_{w}$ is just addition modulo $2^w$, we can have:


$$
\begin{align}
 x +^{t}_{w} y = U 2 T_{w} (T 2 U_{w}(x) +^{u}_{w} T 2 U_{w}(y)) \\ \\
= U 2 T_{w}[(x_{w-1}2^{w}+x + y_{w-1}2^{w}+y)\text{mod}2^w]\\ \\
= U 2 T_{w}[(x + y)\text{mod}2^w]
\end{align}
$$

Note that $(x_{w-1}2^{w} + y_{w-1}2^{w})\text{mod}2^w=0$ as it cancels out the $2^w$ and leaves no remainder.

Let us define $z \doteq{x + y}$ and $z' \doteq{z\text{mod}2^{w}}$, and $z''\doteq{U 2 T_{w}(z')}$. We can see that $z''\doteq{x +^{u}_{w}y}$

(We examine these 4 cases by referring to equation 2.7 in [[Conversion from unsigned to two-complement]])

1. For $-2^w\leq z <-2^{w-1}$, we have $z'=z + 2^{w}$ and this means $0 \leq z' \leq -2^{w-1} + 2^{w}=2^{w-1}$. In this case, $z''=z'$   and this is the **negative overflow** case.
2. For $-2^{w-1} \leq z < 0$,  we still have $z'=z+2^{w}$, and this means $2^{w-1} \leq z' < 2^{w}$. We can see that z' in a range such that $z''=z'-2^{w}$ and therefore  $z''=z'-2^{w}=z + 2^{w}-2^{w}=z$.
3. For $0 \leq z < 2^{w-1}$, we have $z'=z$ and thus giving $0 \leq z' <2^{w-1}$. We can see that $z''=z=z$ so the two's-complement sum of $z''$ is equal to $x + y$ 
4. For $2^{w-1} \leq z < 2^{w}$, we will again have $z'=z$ and thus giving $2^{w-1} \leq z' < 2^{w}$. For that we will have $z''=z'-2^{w}$ and thus $z''=x + y - 2^{w}$. This is the **positive overflow** case.

| $x$      | $y$      | $x + y$   | $x +^{t}_{4}y$ | Case |
| -------- | -------- | --------- | -------------- | ---- |
| -8       | -5       | -13       | 3              | 1    |
| `[1000]` | `[1011]` | `[10011]` | `[0011]`       |      |
| -8       | -8       | -16       | 0              | 1    |
| `[1000]` | `[1000]` | `[10000]` | `[0000]`       |      |
| -8       | 5        | -3        | -3             | 2    |
| `[1000]` | `[0101]` | `[11101]` | `[1101]`       |      |
| 2        | 5        | 7         | 7              | 3    |
| `[0010]` | `[0101]` | `[00111]` | `[0111]`       | 3    |
| 5        | 5        | 10        | -6             | 4    |
| `[0101]` | `[0101]` | `[01010]` | `[1010]`       |      |
