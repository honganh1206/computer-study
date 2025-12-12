---
tags:
  - "#study"
  - "#review"
cssclasses:
  - center-images
---
EX1.

| $N$ elements | $O(N)$ | $O(\log N)$ | $O(N^2)$ |
| ------------ | ------ | ----------- | -------- |
| 100          | 100    | 6.64        | 10000    |
| 2000         | 2000   | 11          | 4000000  |

EX2. 16 elements

EX3. $O(N^2)$

EX4. 

```python
def find_greatest_number(array):
    greatest_number = array[0] # Suppose that the 1st value is the greatest
    for i in array:
        if i > greatest_number:
            greatest_number = i
    return greatest_number
```