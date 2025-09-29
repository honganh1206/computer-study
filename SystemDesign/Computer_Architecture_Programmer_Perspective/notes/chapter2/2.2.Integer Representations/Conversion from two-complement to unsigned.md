---
tags:
  - "#study"
  - "#review"
  - "#computer"
  - "#programming"
cssclasses:
  - center-images
sr-due: 2025-09-26
sr-interval: 1
sr-ease: 230
---
## Principle

For $x$ such that $TMin_{w} \leq x \leq TMax_{w}$:

$$
T 2 U_{w}(x) = 
\begin{array}{rcl} 
    & x + 2^{w} &\mbox{for} & x < 0 \\
    & x &\mbox{for} & x \geq 0
\end{array}  \quad \text{(2.5)}
$$

Example: $T 2 U_{16}(-12,345) = -12,345 + 2^{16}=53,191$ 

## Derivation

$$
B 2 U_{w}(\vec{x}) - B 2 T_{w}(\vec{x}) = x_{w-1}2^w
$$
Note that this equation has its weighted sums for bits from $0$ to $w-2$ *cancel each other*. Therefore with $x \geq 0$ or $x < 0$ we have:

$$
B 2 U_{w}(T 2 B_{w}(x)) = T 2 U_{w}(x) = x + x_{w-1}2^{w} \quad \text{(2.6)}
$$

The negative values in two’s-complement representation increase by $2^{4}=16$ with an unsigned representation.

![[Figure 2-17.png]]