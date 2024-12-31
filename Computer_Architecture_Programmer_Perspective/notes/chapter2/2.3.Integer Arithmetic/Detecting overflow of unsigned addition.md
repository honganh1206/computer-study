Tags: #review #computer 

## Principle

For $x, y$ in range $o \leq x,y<U\text{Max}_{w}$, let $s = x +^{u}_{w}y$. The computation of $s$ will overflow *if and only if* $s<x$ or $s<y$

## Derivation

If $s$ did not overflow, we will surely have $s \geq x$. Otherwise if $s$ did overflow, we will have $s=x+y-2^w$ and given that $y < 2^w$, we will have $y-2^w=0$ and thus $s=x+(y-2^{w)}< 0$