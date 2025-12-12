---
tags:
  - "#study"
  - "#review"
  - "#programming"
  - "#algorithm"
cssclasses:
  - center-images
sr-due: 2025-09-28
sr-interval: 3
sr-ease: 250
---
We can **call `max()` only once** within our code and **save the result to the variable**:

```python
def max(array):
	if len(array) == 1:
		return array[0]
	max_of_remainder = max(array[1:])
	if array[0] > max_of_remainder:
		return array[0]
	else:
		return max_of_remainder # This only calls max() depending on the number of elements in the array
```