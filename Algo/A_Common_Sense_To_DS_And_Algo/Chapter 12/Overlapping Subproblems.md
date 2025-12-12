---
tags:
  - "#study"
  - "#review"
  - "#programming"
  - "#algorithm"
cssclasses:
  - center-images
---

```python
def fib(n):
	if n == 0 or n == 1:
		return n
	return fib(n-2) + fib(n-1) # The fib() function calls itself twice
```

Overlapping sub-problems occur when **the same sub-problems are solved multiple times** during the computation of the overall problem

In the above example, computing $F(5)$ requires computing $F(4)$ and $F(3)$, while computing $F(4)$ requires computing $F(3)$ AGAIN and $F(2)$
