---
tags:
  - "#study"
  - "#review"
  - "#computer"
  - "#programming"
  - "#math"
cssclasses:
  - center-images
---
For bit vectors, the simplest case would be $w=1$, but in general cases there are $2^w$ bit vectors of length $w$.

*Boolean algebra share many traits with arithmetic over integers*. For example, in integer arithmetic we can write $a * (b + c) = a*b + a*c$ and in Boolean algebra we can write `a & (b|c) = (a & b) | (a & c)` 

When considering operations `^, &, ~` on bit vectors of length $w$, we use **Boolean ring** as a different mathematical form. For example, the `^` property works as the *additive inverse $-x$ of a specific variable $x$*, so in integer arithmetic we have $x + -x = 0$ and `a ^a=0` in Boolean algebra.


> [!info] 
> We use 0 to represent **a bit vector of all zeros** in Boolean algebra.



