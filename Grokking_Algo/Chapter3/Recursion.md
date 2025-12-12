- Used when it makes the solution clearer

```ad-quote
“Loops may achieve a performance gain for your program. Recursion may achieve a performance gain for your programmer. Choose which is more important in your situation!

```

- Every recursive function has two parts: The **base** case and the **recursive** case

```python
def count_down(i):
	print i
	if i <= 0: # base case
		return
	else:
		count_down(i-1) # recursive case
```

# The stack

- Has only two actions: *push* (insert) and *pop* (remove and read)

## The call stack

```ad-important
when you call a function from another function, the calling function is paused in **a partially completed state**

```

## The call stack with recursion

```python
def factorial(x):
	if x == 1:
		return 1
	else:
		return x * fact(x-1)
```

![[Pasted image 20231022232615.png]]
![[Pasted image 20231022232700.png]]

```ad-important
Using the stack is convenient because **you don’t have to keep track of a pile of boxes yourself**—the stack does it for you. However, **saving all that info can take up a lot of memory**

```

# Longest common substring

```ad-tip
title: Takeaways
- Dynamic programming is useful **when you are trying to optimize something given a constraint** 
- Use DP when **the problem can be broken into discrete sub-problems and non-dependent**

```

- General tips
	- Every DP solution involves **a grid**
	- The values in the cell are **what you are trying to optimize**
	- Each cell is a sub-problem divided from the big one

## The solution for the *hish* problem


![[Pasted image 20231129150944.png]]


```python
if word_a[i] == word_b[j]:
	cell[i][j] = cell[i-1][j-1] + 1
else:
	cell[i][j] = 0
```

=> For the longest common substring problem, the solution is the **largest number in the grid**, and it may not be the last cell

## Longest common subsequence

### *fosh* is for *fish* or *fort*?

![[Pasted image 20231129152328.png]]

![[Pasted image 20231129154158.png]]

```python
# If the letters match
if word_a[i] == word_b[j]:
	cell[i][j] = cell[i-1][j-1] + 1
# The letters do not match
else:
	cell[i][j] = max(cell[i-1][j], cell[i][j-1])
```

- Use cases:
	- Find similarities in DNA strands
	- `git diff`
	- *Levenshtein distance* measuring how similar two strings are
	- Word wrap in Microsoft Word

---
# Exercises

3.1. Greet2
3.2. The stack overflows