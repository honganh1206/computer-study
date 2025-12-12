---
tags:
  - "#study"
  - "#review"
cssclasses:
  - center-images
---

$$
F(n) = F(n-1) + F(n-2)
$$

Base case: $F(0)$ and $F(1)$

1. Add up all numbers to $n$ 
2. Recurrence relation: $F(n) = F(n-1) + F(n-2)$
3. Solving order: From $F(0)$ and $F(1)$ to $F(n)$
4. Compute Solutions:
    - Initialize an array `fib` of size n+1n+1n+1.
    - Set `fib[0] = 0` and `fib[1] = 1`.
    - Iterate from 2 to $n$, setting `fib[i] = fib[i-1] + fib[i-2]`.
5. Final Solution: `fib[n]`.

```python
def fibonacci(n):
    if n <= 1:
        return n
    fib = [0] * (n + 1)
    fib[1] = 1
    for i in range(2, n + 1):
        fib[i] = fib[i-1] + fib[i-2]
    return fib[n]
```