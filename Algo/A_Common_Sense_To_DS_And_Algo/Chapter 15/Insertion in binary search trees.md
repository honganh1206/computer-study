---
tags:
  - "#study"
  - "#review"
  - "#programming"
  - "#algorithm"
cssclasses:
  - center-images
---

We do the same thing as searching *until we find a value that has no children*. At this point, if the to-be-inserted value is less or greater than the value no-child node, *we insert it as either the left or right node*. 

Insertion goes through the same steps as searching but *take fewer steps* compared to arrays.

> [!info] The Order of Insertion
> 
> Only when creating a tree out of randomly sorted data do trees usually wind up being well-balanced. However, **if we insert sorted data into a tree, it can become imbalanced.**

Best-case scenario is $O(\log(N))$ and worst-case scenario is $O(N)$



