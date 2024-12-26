Tags: #review #computer 

## Principle

For $x, y$ in the range $T\text{Min}_{w} \leq x, y \leq T\text{Max}_{w}$, let $s \doteq x +^{t}_{w} \\ y$. If $x > 0, y > 0$ but $s \leq 0$ then the computation of $s$ has had *positive overflow*. On the other hand, the computation of $s$ has a negative overflow if and only if $x < 0, y < 0$ but $s \geq 0$.

![[Figure 2-26.png]]

## Derivation

Conversely, positive overflow requires  $x > 0$ and $y > 0$ (otherwise, $x + y < T\text{Max}_{w}$) *and* $s \geq 0$. A similar set of arguments holds for negative flow.

