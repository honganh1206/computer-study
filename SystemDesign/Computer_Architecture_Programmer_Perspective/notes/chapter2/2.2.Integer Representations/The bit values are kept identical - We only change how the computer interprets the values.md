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
We have two functions: $U 2 B_{w}$ to map numbers to their bit representation in their unsigned form ($0 < x < UMax_{w}$) and $T 2 B_{w}$ to map numbers in two’s-complement form ($TMin_{w} \leq x \leq TMax_{w}$). 

To convert signed numbers to unsigned, we have 

$$
T2U_{w}(x)\doteq B2U_{w}(T 2 B_{w}(x))
$$
that *takes a number between $TMin_{w}$ and $TMax_{w}$ and returns a number between $0$ and $UMax_{w}$*.

Similarly, we convert an unsigned number to signed with the function 

$$
U 2 T_{w}(x) \doteq B 2 T_{w}(U 2 B_{w}(x))
$$

We can see the relationship here:

$$
|x| + B 2 U_{w}(T 2 B_{w}(x)) = 2^w
$$

