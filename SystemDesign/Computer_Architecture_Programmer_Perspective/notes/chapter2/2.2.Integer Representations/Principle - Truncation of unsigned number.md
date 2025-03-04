Tags: #review #computer #clang 

## Principle

Let $\vec{x}=[x_{w-1},x_{w-2},\dots,x_{0}]$ and $\vec{x'}$ be the truncation of $\vec{x}$ by $k$ bits with $\vec{x'}=[x_{k-1}, x_{k-2},\dots,x_{0}]$ 

Let $x=B 2 U_{w}(\vec{x})$ and $\vec{x'}=B 2 U_{k}(\vec{x'})$, then $$x'=x\text{mod}2^k$$

Why? The truncated bits have weights in the form of $2^i$ where $i\geq k$, and each of these weights reduces to zero under the modulus operation.

### Example

Supposed we have a 6-bit vector $\vec{x}=[1,0,1,1,0,1]$ of weight representing the numerical value $45$. After truncating it to 4 bits $\vec{x'}=[1,1,0,1]$, the value after the truncation would be $13$. As $k=4$, we have $x\text{mod}2^k=45\text{mod}16=13$
