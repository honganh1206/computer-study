---
tags:
  - "#study"
  - "#review"
cssclasses:
  - center-images
---

> [!summary]
> Big O Notation only concerns itself with **general categories** of algorithm speeds, as it only cares about the **long-term trajectory** of the algorithm's steps as the data increases

- When comparing between $O(n^2)$ and $O(n)$, the two efficiencies are so different we do not bother to check if $O(n)$ is actually $O(2n)$ or $O\left( \frac{n}{2} \right)$
## Practical example

```python
def print_numbers_version_one(upperLimit):
	number = 2
	while number <= upperLimit:
	# If number is even, print it:
		if number % 2 == 0:
			print(number)
		number += 1
def print_numbers_version_two(upperLimit):
	number = 2
	while number <= upperLimit:
		print(number)
	# Increase number by 2, which, by definition,
	# is the next even number:
		number += 2
```

- While the 1st version takes $N$ steps (the loop runs $N$ times), the 2nd one takes $\frac{N}{2}$ steps, but we need to **drop the constants and reduce the expression** to $O(N)$

## Significant steps

- All steps are significant