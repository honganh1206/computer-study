---
tags:
  - "#study"
  - "#review"
  - "#programming"
  - "#computer"
cssclasses:
  - center-images
---
For a vector $\vec{x} = [x_{w-1},x_{w-2},\dots,x_{0}]$, the function $B2U_{w}$ (binary to unsigned) will look like this (using the sum notation):

$$
B2U_{w}(\vec{x}) \doteq \sum_{i=0}^{w-1}x_{i}2^i
$$

This function *maps strings of zeroes and ones of length $w$ to non-negative integers*:

$$
B2U_{4}([0001]) = 0 \times 2^{3} + 0 \times 2^{2}+ 0 \times 2^{1}+ 1 \times 2^{0} = 1 
$$


The least value will be denoted by bit vector $[00\dots0]$ and the greatest value will be denoted by bit vector $[11\dots1]$ with the value of:

$$
U{Max}_{w}(\vec{x}) \doteq \sum_{i=0}^{w-1}2^{i}=2^w-1
$$

For example, in the 4-bit case, we have $U{Max}_{4} = B2U_{4}([1111]) = 15$

Thus, we can define the function $B2U_{w}$ as this mapping:

$$
B2U_{w}:\{0,1\}^{w}\to \{0,\dots,U{Max}_{w}\}
$$

with $\{0,1\}^{w}$ as a **set** of binary strings of length $w$



