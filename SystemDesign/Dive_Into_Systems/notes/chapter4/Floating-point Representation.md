
A value's binary point is **not fixed** into a predefined position.

The interpretation of a binary sequence must encode *how it can represent the split between the whole and fractional parts*. 

We will focus on the position defined by IEEE standard 754

![[Pasted image 20250414131109.png]]

**Significand/Mantissa** ($d_{22}\space -\space d_{0}$) - The largest region of bits, serving as the foundation for the value

Example: `0b110000...0000` means the 1st bit represents $1 \times 2^{-1} = 0.5$, and the 2nd bit represents $1 \times 2^{-2} = 0.25$ and the significand contributes $1.75$

**Exponent** ($d_{30} \space\text{to}\space d_{23}$) scales the significand's value to a wide representable range

The significant gets multiplied by $2^{\text{exponent} - 127}$

**Sign bit** $d_{31}$ determines whether the value is positive or negative