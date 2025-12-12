```ad-summary
- Greedy algorithms optimize **locally**, hoping to end up with a global optimum.
- NP-complete problems have NO known fast solution.
- If you have an NP-complete problem, your best bet is to use an **approximation algorithm**.
- Greedy algorithms are **easy to write** and **fast to run**, so they make good approximation algorithms.

```


# The class scheduling problem

- Scenario: Suppose you have a classroom and want to **hold as many classes here as possible**, but some of them **overlap**

![[Pasted image 20231110172151.png]]

- Solution:
	1. Pick the class that ends the soonest
	2. Pick the class that ends **after the first class** + ends the soonest

```ad-summary
A greedy algorithm is simple: at each step, pick the **optimal** move.

```

# The knapsack problem

```ad-important
Sometimes all you need is an algorithm that solves the problem **pretty well**. And that’s where greedy algorithms shine, because they’re **simple to write** and **usually get pretty close**.

```

# The set-covering problem

## Scenario

- Suppose you’re starting a radio show. You want to reach listeners in all 50 states => You have to **decide what stations to play on to reach all those listener**s.
- Each station covers a region, and there’s **overlap**.
- It costs money to be on each station => Find the **smallest set of stations** to cover all states


![[Pasted image 20231115210201.png]]

## Solution

1. List **every possible subset of stations** => The **power set** contains $2^n$ possible subsets
2. Pick the set with **the smallest number of stations** that covers all 50 states



```ad-info
title: Power Set and its properties
For a given set $S$, a **Power Set** of $P(S)$ or $2^S$ represents a set **containing all possible subsets of $S$** as its elements

$$
S = \{1, 2, 3\} \\
$$
$$
P(S) = \{\emptyset, \{1\}\, \{2\}, \{3\},\{1,2\}\, \{2,3\}, \{1,3\},\{1,2,3\}\}
$$

```

```ad-warning
title: About sets
Sets CANNOT have duplicates

```

### Approximation algorithm

-  When calculating the exact solution will take too much time, an approximation algorithm will work.
- Approximation algorithms are judged by:
	- How **fast** they are
	- How **close** they are to the *optimal solution*

![[Pasted image 20231119152022.png]]

# NP (non-deterministic polynomial time)-complete problems

## Travelling salesperson, step by step

- It is up to **YOU** to compute the optimal path and start location for the traveling salesperson
- Number of routes with $n$ cities is calculated by *factorial function*:
	- $n=2$ => 2 routes
	- $n=3$ => 6 routes
	- $n=4$ => 24 routes (4 different start cities, the remaining path is similar to $n=3$, so $4\cdot6=24$)
	- $n=5$ => 120 routes

![[Pasted image 20231119155112.png]]

## Approximating

- Arbitrarily pick a start city, then pick the closest unvisited city

## Identify a NP-complete problem

- Scenario: Jonah is picking players for his fantasy football team, with each player fulfilling some abilities. However, Jonah needs a team that **fulfills all/most of the abilities with limited team size**

![[Pasted image 20231119161133.png]]

- Solution: Approximation algorithm
	1. Find the player who **fulfills the most abilities** that have not been fulfilled
	2. **Repeat** until the team fulfills all abilities/running out of space on the team

```ad-info
title: Signs of a NP-problem
1. The algorithm runs fast with small number of items, but slow as the number of items goes up
2. "All combinations of X"
3. The need to calculate "every possible version of X" as you cannot break it down to smaller sub-problems
4. Problem involving a **sequence** such as a sequence of cities (traveling salesperson)
5. Problem involving a **set**
6. The problem can be restated to set-covering/traveling salesperson problem

```


---

# Exercises

8.1. - Pick the largest box, then pick the boxes that are lighter than the previous one + the heaviest one of the remaining => NOT the optimal solution

8.2. - Pick the activity with the highest point value, then keep picking the highest one of the remaining activities with all the time you have left => NOT the optimal solution

8.3. No

8.4. Yes

8.5. Yes

8.6. Yes

8.7. Yes

8.8. Yes