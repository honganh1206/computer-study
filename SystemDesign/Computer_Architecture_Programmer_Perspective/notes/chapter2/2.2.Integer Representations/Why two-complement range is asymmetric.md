---
tags:
  - "#study"
  - "#review"
  - "#programming"
  - "#computer"
cssclasses:
  - center-images
---

> [!note] Dropping the length
> Special values like $UMax_{w}$, $TMin_{w}$ and $TMax_{w}$ will be further discussed without the length $w$ as we can inferred from context, so they will be referred to as $UMax$, $TMin$ and $TMax$


The two’s-complement range is *asymmetric*: $|TMin| = |TMax| + 1$ (Absolute of $TMin$ is larger by 1 compared to absolute of $TMax$). Here are some examples:

![[Pasted image 20241103164824.png]]


But why this? 

1. Half the bit patterns (sign bit set to 1) represents negative numbers, while half (sign bit set to 0) represents non-negative numbers. For example, the bit vector $[1000]$ has $|-x_{w-1}\times 2^{w-1}| - |x_{w-2}\times 2^{w-2}| = 1$
2. The maximum unsigned value is *just over twice* the maximum two’s-complement value: $U Max = 2TMax + 1$ 

