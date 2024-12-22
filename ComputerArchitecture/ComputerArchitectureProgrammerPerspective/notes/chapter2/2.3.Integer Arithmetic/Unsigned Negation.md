Tags: #review #computer  

Let us consider a set of $w$-bit unsigned numbers with addition operation $+^{u}_{w}$.

For every value $x$, there must be some value $-^{u}_{w}x$  such that $-^{u}_{w}x  +^{u}_{w}x=0$

## Principle

For any number $x$ that is $0 \leq x <2^w$, its $w$-bit unsigned negation is given such that:

$$
-^{u}_{w}x = 
\begin{array}{rcl}
& x, & x=0 \\
& 2^{w}-x, & x>0
 \end{array}
$$


## Derivation

With $x>0$, we can see that $0<2^{w}- x < 2^w$ and we can also see that $(x+2^{w}- x)\text{mod}2^{w}=2^{w}\text{mod}2^{w}=0$

