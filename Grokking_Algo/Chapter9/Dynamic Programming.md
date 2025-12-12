
```ad-summary
- Dynamic programming is useful when you’re trying to **optimize something given a constraint**.
- You can use dynamic programming when **the problem can be broken into discrete subproblems**.
- Every dynamic-programming solution involves a **grid**.
- The values in the cells are usually what you’re trying to optimize.
- Each cell is a subproblem, so think about how you can **divide your problem into sub-problems**.
- There’s **no single formula** for calculating a dynamic-programming solution.
```


# Revisiting the knapsack problem

- Simple solution: Try **every** possible set of goods and choose the one giving you the most value
- Drawback: Slow + Using approximation algorithm from Chapter 8 is just *close* to the optimal solution

# Dynamic programming definition

- Definition: Solving sub-problems and building up to solving the big problems
- Every dynamic-programming algorithm starts with a grid

![[Pasted image 20231126194459.png]]

- Formula to calculate cell's value

![[Pasted image 20231126200400.png]]

- Example: Stereo (R2C4) + Current Item as Laptop + Value of remaining space (1 lb)
![[Pasted image 20231126202400.png]]

# Questions and answers

1. Change the order of the rows => The order does not matter
2. Fill in the grid column-wise instead of row-wise => For the current problem, it does not make a difference
3. Add a smaller item with weight of 0.5 lb => Change the grid for finer *granularity* (the scale of level of detail)

![[Pasted image 20231126204514.png]]


```ad-tip
title: Handling items depending on each other
Dynamic programming only works when each sub-problem is discrete - when it does not depend on other sub-problems

```



---
# Exercises

9.1. No, Laptop and Guitar (R4C4) is $3500, still higher than previous cell of Guitar and MP3 (R4C3) of $2500

9.2. Water, Camera, and Food