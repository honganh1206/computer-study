---
tags:
  - "#study"
  - "#review"
  - "#programming"
  - "#computer"
cssclasses:
  - center-images
---
## Principle

For $u$ such that $0 ≤ u ≤UMax_w$:

$$
U 2 T_{w}(u) = 
\begin{array}{rcl} 
    & u &\mbox{for} & u \leq TMax_{w} \\
    & u - 2^{w} &\mbox{for} & u > TMax_{w}
\end{array} \quad \text{(2.7)}
$$

![[Figure 2-18.png]]

## Derivation

For $\vec{u} = U 2 B_{w}(u)$:

$$
U 2 T_{w}(u) = -u_{w-1}2^{w}+ u
$$

For small ($\leq TMax_{w}$) numbers, the conversion to signed preserves the numeric value, while large $(>TMax_{w})$ numbers are converted to negative values.

