Tags: #review #computer 

Similar to the [[Derivation - Truncation of unsigned number]], we have:

$$
B 2 T_{w}([x_{w-1},x_{w-2},\dots,x_{0}])\text{mod}2^{k}= B 2 U_{k}([x_{k-1},x_{k-2},\dots,x_{0}])
$$
Converting this to two's-complement number gives

$$
x'=U 2 T_{k}(x\text{mod}2^k)
$$

### Example

Let $\vec{x}=[1,0,1,1,0,1]$ and $w=6$. We have $x=B 2 T_{6}(\vec{x})=-19$

We truncate $\vec{x}$ to 4 bits and by then we have $\vec{x'}=[1,1,0,1]$. We have $x'=B 2 U_{4}(\vec{x'})=11$

We can see that $x\text{mod}2^k=-19\\text{mod}2=-19-16\times l\left\lfloor  -\frac{19}{16}  \right\rfloor=-19+32=11$, thus proving that $x'=U 2 T_{k}(x\text{mod}2^k)$
