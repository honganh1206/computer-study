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
def max(array):
	# Base case
	if (len(array) == 1):
		return array[0]
	# First element greater than the maximum of the rest of the array
	if array[0] > max(array[1:]):
		return array[0]
	else:
		return max(array[1:]) # Each time we call max(), we trigger an ENTIRE AVALANCHE of recursive calls
```

In the above example, supposed we have an array of length 4, every time `max(array[1:])` is called, *a new slice of array is created*. 

```
max([a, b, c, d])
  -> compares a with max([b, c, d])
    -> max([b, c, d])
      -> compares b with max([c, d])
        -> max([c, d])
          -> compares c with max([d])
            -> max([d]) returns d

```

Also, a full series of recursive calls is triggered for **every comparison**, and it is inefficient is the array is large.

[[The Little Fix for unnecessary recursive calls]]