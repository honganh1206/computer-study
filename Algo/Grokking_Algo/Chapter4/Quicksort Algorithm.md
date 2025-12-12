
```ad-quote
When a good algorithmist comes across such a problem, they don’t just give up. **They have a toolbox full of techniques they use on the problem, trying to come up with a solution.**

```


```ad-summary
1. D&C works by **breaking a problem down into smaller and smaller pieces**. If you’re using D&C on a list, the base case is probably **an empty array or an array with one element**.
2. If you’re implementing quicksort, choose a random element as the pivot. The average runtime/best-case scenario time of quicksort is $O(n\log(n))$
3. The constant in Big O notation can matter sometimes. That’s why **quicksort is faster than merge sort**.
4. **The constant almost never matters for simple search versus binary search**, because $O(\log(n))$ is so much faster than $O(n)$ when your list gets big.

```


# Divide & Conquer

## Definition

- D&C algorithms = Recursive algorithms with two steps:
	1. **Figure out the base case** aka Simplest possible case
	2. Divide and decrease your problem **until it becomes the base case**
- Example: Divide a farm of 1680m x 640m into **equal segments**

![[Pasted image 20231025103330.png]]


=>  If you find **the biggest box** that will work for this size, that will be the biggest box
that will **work for the entire farm.**

```ad-info
title: Euclid's Algorithm
- A method to find **the greatest common divisor (GCD)** of two numbers
- Steps:
	1. Choose two numbers
	2. Divide and Find Remainder (If A is divisible by B, then B is the GCD - Base case)
	3. Swap and repeat: Set A=B and B=the remainder from step 2
	4. Repeat Until Zero Remainder: Keep repeating step 2 and 3 until there is no remainder (Recursion)

=> **The last non-zero remainder is the GCD**

```

## Problem: Get the sum of an array using recursion

![[Pasted image 20231025111518.png]]

- Step 1: Figure out the base case - Get an array with 0 or 1 element
- Step 2: Move closer to an empty array with every recursive call

![[Pasted image 20231025112226.png]]

# Quicksort

- Arrays with <2 elements do not need sorting => Base case
- How quicksort works:
	- Pick an element as a **pivot**
	- Find elements that are smaller & larger than the pivot, then putting them into two separate arrays => **Partitioning**
	- Sort the sub-arrays with recursion, then combine the `left array + pivot + right array`

![[Pasted image 20231027165119.png]]

```ad-important
No matter what pivot you pick, you can **call quicksort recursively** on the two sub-arrays.

```


```python
def quick_sort(arr):
	# Base case for no elem/1 elem only
	if len(arr) < 2:
		return arr
	else:
		# Recursive case
		pivot = arr[0]
		less = [i for i in arr[1:] if i < pivot]
		greater = [j for j in arr[1:] if j > pivot]

		return quick_sort(less) + [pivot] + quick_sort(greater)

quick_sort([5, 2, 77, 100])
```

```ad-summary
title: Inductive proofs
- Inductive proofs are one way to prove that your algorithm works.
- Each inductive proof has two steps: the base case and the inductive case. 
	- Base case: Supposed that my legs are on rung 1 => I can climb the entire ladder, going up one rung at a time.
	- Inductive case: If my legs are on a rung, I can put my legs on the next rung


```


# Big O Notation revisited

## Merge sort vs. Quicksort

- Quicksort has a smaller constant than merge sort (If both are $O(n\log(n))$ time, quicksort is still faster)

## Average case vs. Worst case

```ad-summary
In the worst case, quicksort takes $O(n^2)$ time due to:
1. Unlucky Pivot Selection: If you always choose the smallest/largest element in the array as the pivot, **the algorithm essentially behaves like selection sort**
2. Already sorted array

```

### Worst-case

![[Pasted image 20231027180030.png]]

- Scenario: You choose the 1st element as the pivot for the _already sorted array_
- Worst-case is when the height of the call stack = the number of elements $n$

- Best-case scenario of quicksort is $O(\log(n))$ and worst-case one is $O(n^2)$

```ad-important
If you always choose a random element in the array as the pivot, quicksort will complete in $O(n\log(n))$ time on average.

```



---

# Exercises

4.1.

```python
def sum(arr):
	if arr == []:
		return 0
	return arr[0] + sum(arr[1:])
```

4.2.

```python
def count(list):
	if arr == []:
		return 0
	return 1 + count(arr[1:])
```

4.3. 

```python
def find_maximum(list):
	if len(list) == 2: # Base case with two elements only
		if list[0] > list[1]:
			return list[0]
		else:
			return list[1]
	# Cut the 1st elem out of the list RECURSIVELY until there are only two elements (Reaching the base case)
	# NOTE: The list[1:] only CREATES a new list without the first element
	max_num = find_maximum(list[1:]) # list[1:] refers to the smaller list without the 1st element
	if list[0] > max_num: # Recursive phase
		return list[0]
	else:
		return max_num
```

4.4.

```python
def binary_search(arr, target, low=0, high=None):
	if high is None:
		high = len(arr) - 1

	if low > high: # Base case to handle empty list/target element not in the list
		return -1
	
	if len(arr) == 1:
		if arr[0] == target:
			return 0;
			
	mid = (low + high) // 2
	
	guess = arr[mid]
	
	if guess == target:
		return mid
	elif guess > target:
		return binary_search(arr, target, low, mid - 1)
	else:
		return binary_search(arr, target, mid + 1, high)
	
```

4.5. $O(n)$

4.6. $O(n)$

4.7. $O(1)$

4.8. $O(n^2)$

