# Binary Search

- Input: A **sorted** list of elements
- Output: The **position** of the element you are looking for

```ad-info
With the binary search, you **guess the middle number** and **eliminate half the remaining numbers everytime**

![[Pasted image 20231018151041.png]]

```

```ad-info
title: Logarithms
Logs are the flips of exponentials.


$$
\log(100) = 2
$$

```

```ad-attention
When we talk about running time in Big O notation, log **always mean $\log_2(x)$** (base 2)

```

## Running time

- Binary search runs in **logarithmic time** (or **log** time) => $O(\log(n))$

# Big O notation

- A special notation that tells you **how fast an algorithm is**

```ad-info
title: Big O establishes a worst-case runtime
Big O notation is about the *worst-case* scenario e.g. Simple/Linear search takes $O(n)$ time

```

- Algorithm speed is measured in **growth of the number of operations**
- The focus is on **how quickly the runtime of an algorithm increases** as the size of the input increases
- Runtime of algorithms is expressed in Big O notation

# The traveling salesperson

```ad-info
title: Permutation
Refers to **the arrangement of elements in a specific order**. Each permutation is a **unique** arragement of the elements in the set.

For example, consider the set {1, 2, 3}. The permutations of this set are:

1. (1, 2, 3)
2. (1, 3, 2)
3. (2, 1, 3)
4. (2, 3, 1)
5. (3, 1, 2)
6. (3, 2, 1)

For a set of $n$ elements, there are $n!$ possible permutations

```


---
# Exercises

1.1. 7 steps

1.2. 8 steps

1.3. $O(\log(n))$

1.4. $O(n)$

1.5. $O(n)$

1.6. $O(n)$