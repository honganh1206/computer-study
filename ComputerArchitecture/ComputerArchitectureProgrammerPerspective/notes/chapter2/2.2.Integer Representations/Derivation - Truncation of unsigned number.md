Tags: #review #computer 

$$
\begin{aligned}
B2U_w([x_{w-1}, x_{w-2}, \ldots, x_0]) \mod 2^k \\=
\left[\sum_{i=0}^{w-1} x_i 2^i\right] \mod 2^k \\=
\sum_{i=0}^{k-1} x_i 2^i \\=
B2U_k([x_{k-1}, x_{k-2}, \ldots, x_0])
\end{aligned}
$$

Note that the lower $k$ bits ($i<k$) *directly contribute* to the value, while the higher-order bits ($i \geq k$) vanish under the modulus operation