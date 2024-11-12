---
tags:
  - "#study"
  - "#review"
  - "#programming"
  - "#computer"
cssclasses:
  - center-images
---
For a vector $\vec{x} = [x_{w-1},x_{w-2},\dots,x_{0}]$, we have

$$
B2T_{w}(\vec{x}) \doteq -x_{w-1}2^{w-1} + \sum_{i=0}^{w-2}x_{i}2^{i}=2^w-1
$$

We have $x_{w-1}$ (the most significant bit) as the *sign bit* and its weight is $2^{w-1}$. The sign bit denotes whether the value is negative or non-negative with 1 and 0 respectively. Here is an example of the function

$$
B2T_{4}([1001]) = -1 \times 2^{3} + 0 \times 2^{2}+ 0 \times 2^{1}+ 1 \times 2^{0} = -5
$$


In the figure below, the total numeric value of a bit vector is the *combination* of the leftward-pointing gray bar and the rightward-pointing blue bar:

![[Figure 2-13.png|The values differ greatly when the most significant bit is 1]]


The *least representable* value given by a bit vector of $[10\dots0]$ (sign bit sets the negative weight and clear all other bits) has the integer value of $TMin_{w} \doteq -2^{w-1}$

Meanwhile, the *greatest value* given by a bit vector of $[01\dots1]$ (clear all the sign bit and set others) has the integer value of $TMax_{w}\doteq \sum_{i=0}^{w-2}2^{i}$

For example:

$$TMin_{4} = B2T_{4}[1000]=-2^{3}= 8$$
$$
TMax_{4} = B2T_{4}[0111] = 2^{2}+ 2^{1}+2^{0}= 7
$$


We can define the mapping of bit patterns for the two’s-complement encoding here:

$$
B2T_{w}:\{0,1\}^{w} \to \{TMin_{w},\dots\,TMax_{w}\}
$$

