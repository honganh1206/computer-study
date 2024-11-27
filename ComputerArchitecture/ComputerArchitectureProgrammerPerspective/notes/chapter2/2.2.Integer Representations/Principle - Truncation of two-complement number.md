Tags: #review #computer #clang 

For $\vec{x}=[x_{w-1}, x_{w-2}, \dots, w_{0}]$ and $\vec{x'}$ as the truncated version of $\vec{x}$ to $k$ bits. That means $\vec{x'}=[x_{k-1}, x_{k-2}, \dots, x_{0}]$.

Let $x = B 2 T_{w}(\vec{x})$ and $x'= B 2 T_{w}(\vec{x'})$ then we have $x'=U 2 T_{k}(x || 2^k)$. The result of $x||2^k$ will be between $0$ and $2^k-1$, and applying the function $U 2 T_{k}$ will convert the weight of the MSB $x_{k-1}$ from $2^{k-1}$ to $-2^{k-1}$  (see [[2.2.4. Conversion between Signed and Unsigned]])
## Example

For $x=53,191$ and $x$ is a 32-bit signed integer format. When we truncate $x$ to 16-bit, we apply $x||2^{16}=53,191$ so the remainder is $53,191$.

The result of $U 2 T_{16}=53,191-2^{16} = -12,345$
