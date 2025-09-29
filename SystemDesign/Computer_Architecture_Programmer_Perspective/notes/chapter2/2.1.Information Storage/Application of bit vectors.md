---
tags:
  - "#study"
  - "#review"
  - "#math"
  - "#programming"
  - "#computer"
cssclasses:
  - center-images
sr-due: 2025-09-26
sr-interval: 1
sr-ease: 230
---
Bit vectors can be used to *represent finite sets*. We can encode any subset $A \subseteq \{0,1,\dots ,w-1\}$ ($A$ is a subset of a set) with a bit vector $[a_{w-1},\dots, a_{1}, a_{0}]$ where $a_{1}=1$ *if and only if* $i\in A$.

For example, we have bit vector `a = [01101001]` encoding the set $A = \{0,3,5,6\}$ ($0\in A$ as the bit `1` is present at the 7th index of the bit vector) and bit vector `b = [01010101]` encoding the set $B = \{0,2,4,6\}$. The operation `a & b` yields the bit vector of `[01000001]` while $A\cap B=\{0,6\}$.

The encoding of sets by bit vectors could be applied in *signals* that can interrupt the execution of a program (More on chapter 8).

