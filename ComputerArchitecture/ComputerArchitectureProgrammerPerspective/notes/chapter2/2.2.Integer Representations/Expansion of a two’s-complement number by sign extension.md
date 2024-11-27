Tags: #review #computer #clang 


## Principle

For 2 bit vectors $\vec{x} = [x_{w-1}, x_{w-2}, \dots, x_{0}]$ of width $w$ and $\vec{x'}= [x_{w-1}, \dots, x_{w-1}, x_{w-2}, \dots, x_{0}]$ of width $w'$ where $w' > w$ , we will have:

$$
B 2 T_{w}(\vec{x}) = B 2 T_{w'}(\vec{x'})
$$

**KEY IDEA**: Sign extension **preserves** the original number's value regarding two's-complement implementation, as the additional most significant bits (MSBs) help *maintain the correct negative weight*.

While the bit representations of signed and unsigned values could be the same for 16-bit word-size, the representations will differ on 32-bit word-size 

![[Figure 2-20.png]]

### Explanation

With the original bit vector `[101]` ($w=3$) and the MSB as `1`, we can calculate the value while treating the MSB as $-2^{w-1} = 4$ as $-4 + 0 + 1 = -3$.

When we extend `[101]` to 4 bits, the MSB is *copied to a higher bit position* resulting in a new bit vector of `[1101]`. The value is now $-1 \times 2^{3}+ 1 \times 2^{2}+ 0 + 1 \times 2^{0}= -3$, matching the original value.


## Derivative

Let $w' = w + k$.  We need to prove that:
$$
B 2 T_{w + k}(\vec{x}) = B 2 T_{w'}(\vec{x'})
$$

As sign extending by 1 bit preserves the numeric value (explained above), the value remains equal to the original value even if we extend by an arbitrary number of bits. Therefore we will have:

$$
B 2 T_{w}([x_{w-1}, x_{w-2}, \dots, x_{0}]) = B 2 T_{w + 1}([x_{w-1}, x_{w-1},x_{w-2}, \dots, x_{0}])
$$


 Here is how to prove this:

$$ \begin{aligned} B2T_{w+1}([x_w, x_{w-1}, x_{w-2}, \ldots, x_0]) &= -x_w 2^w + \sum_{i=0}^{w-1} x_i 2^i \\ &= -x_w 2^w + x_w 2^{w-1} - x_w 2^{w-1} + \sum_{i=0}^{w-2} x_i 2^i \\ &= -x_w \left( 2^w - 2^{w-1} \right) + \sum_{i=0}^{w-2} x_i 2^i \\ &= -x_w 2^{w-1} + \sum_{i=0}^{w-2} x_i 2^i \\ &= B2T_w([x_{w-1}, x_{w-2}, \ldots, x_0]) \end{aligned} $$


The key property here is $2^{w}- 2^{w-1} = 2^{w-1}$, where adding a negative weight  of $-2^w$ and converting the weight $-2^{w-1}$ to positive help preserving the original value.

