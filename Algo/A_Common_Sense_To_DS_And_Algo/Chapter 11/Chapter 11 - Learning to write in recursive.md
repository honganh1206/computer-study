
> [!summary] 3-sentence summary
> 
> - Two recursive categories: Compute the results from sub-problems then move upward (bottom-up) or solve the overall problem first then store the values from the sub-problems with memoization (top-down).
> - While both categories require dividing the overall problem to sub-problems (divide and conquer), the two categories differ in terms of computation order, implementation, memory usage, control flow and recursion overhead.
> - We should use the top-down approach when the problem is naturally recursive and the bottom-up one when we can describe the problem iteratively.

[[Bottom-Up Recursion - Smallest to overall]]


> [!info] In-Place modifications
> 
> Scenario: Double each number in an array => Two ways to do it
> #1: Create a new array with the doubled data + Leave the old array alone
> #2: Double values in the original array => In-place modification

[[Top-Down Recursion - Overall to smallest]]

[[Top-Down vs. Bottom-Up]]


> [!tip] Why using recursion?
> 
> Indeed, you may not need a new mental strategy for simpler computations. However, when it comes to more complex functions, you may find that the recursive mindset makes the writing of code much easier.

[[The Staircase Problem]]

[[Anagram Generation]]


