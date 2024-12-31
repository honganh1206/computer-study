Tags: #review #computer 

## Principle

For $0 \leq x, y < 2^w$, we characterize the truncated sum operation $+^u_{w}$ as follow:

$$
x +^{u}_{w} y = 
\begin{array}{rcl}
 & x + y &\text{for} & x + y < 2^{w} & \text{Normal}\\
 & x + y - 2^{w}&\text{for} & 2^{w}\leq x + y \leq 2^{w+1} & \text{Overflow}
\end{array}
$$

The normal case *preserves* the value of $x + y$ while the overflow case *decrements* the sum by $2^w$

## Derivation

If $x + y<2^w$, the *leading bit* in the $(w+1)$-bit representation of the sum will be 0, so discarding that 0 will not change the numeric value. However, if $2^w\leq x+y<2^{w+1}$ then the leading bit $(w+1)$-bit representation of the sum will be 1, hence *discarding the leading bit of 1 will also subtract $2^{w}$ from the result*.

![[Figure 2-23.png]]

At that point, the truncated sum would be $(x+y)\text{mod}2^w$