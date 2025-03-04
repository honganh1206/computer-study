---
tags:
  - "#study"
  - "#review"
cssclasses:
  - center-images
---
With a value $x$ as a power of 2 ($x = 2^n$) for some non-negative integer $n$, we can write $x$ in hexadecimal form by remembering that *the representation of $x$ is simply 1 followed by $n$ zeros*.

For $n$ written in the form of $i + 4j$ where $0 \leq i \leq 3$, the value of $i$ determines the **first hexadecimal digit** (1 if $i=0$, 2 if $i=1$, 4 if $i=2$ and 8 if $i=3$) and the value of $j$ determines *how many zeros following the leading digit*

> [!example] 
> If we have $x = 2048 = 2^{11}$ then $n=11=3 + 4 * 2$. If we write $n$ in the form of $i + 4j$ then $i=3$ and $j=2$, we can make the hex representation of $x$ as `0x800`

