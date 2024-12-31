---
tags:
  - "#study"
  - "#review"
  - "#programming"
  - "#computer"
cssclasses:
  - center-images
---
**Ones’ complement**: The sign bit has the weight of $-(2^{w-1}-1)$ instead of $-2^{w-1}$

$$
B 2 O_{w}(\vec{x}) \doteq -x_{w-1}(2^{w-1}-1) + \sum^{w-2}_{i=0}x_{i}2^i
$$

**Sign magnitude**: The sign bit determines whether the remaining bits should be given negative or positive weight. This is used to represent floating-point numbers more.

$$
B 2 S_{w}(\vec{x}) = (-1)^{x_{w-1}}\times(\sum^{w-2}_{i=0}x_{i}2^i)
$$
