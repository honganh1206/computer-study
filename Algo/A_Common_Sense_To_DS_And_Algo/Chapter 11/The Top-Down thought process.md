---
tags:
  - "#study"
  - "#review"
cssclasses:
  - center-images
---
1. Imagine the function you are writing has been implemented by someone else
2. Identify the **sub-problem** of the problem
3. See what happens when you call the function on the sub-problem and go from there

#### Example: Array Sum

- Pseudo code: `return array[0] + sum(the remainder of the array)` => Use someone’s function + Identify the sub-problem (the remainder of the array)


> [!warning] An easy overlook - Using someone's function
> 
> Whenever we write code that calls another function, we assume that the function will return the correct value without necessarily understanding how its internals work.