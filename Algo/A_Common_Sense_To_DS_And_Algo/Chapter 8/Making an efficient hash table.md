---
tags:
  - "#study"
  - "#review"
cssclasses:
  - center-images
---

- The efficiency depends on three factors:
	- Amount of data
	- Number of cells
	- Choice of hash function


[[The great balancing act]]

## Hash Tables for Organization

Some applications of hash tables: Fast-food menus, tracking votes of candidates, status codes, etc.

## Hash Tables for Speed

- Given an array of numbers and your job is to search for a number in the array => Hashing the numbers with a Boolean value as the value

```js
hash_table = {61 => true, 30 => true, 91 => true,
11 => true, 54 => true, 38 => true, 72 => true}
```

=> We can go from $O(N)$ to $O(1)$