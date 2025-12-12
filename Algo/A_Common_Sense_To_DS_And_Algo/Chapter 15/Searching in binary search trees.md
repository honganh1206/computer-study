---
tags:
  - "#study"
  - "#review"
  - "#programming"
  - "#algorithm"
cssclasses:
  - center-images
---
> [!summary]
> We first set the root node as the **current node**. If the node we are looking for is smaller than the current node, we search for it in the left subtree and vice versa. We repeat looking at subtrees until we find what we are looking for.
> 

Steps:
1. Designate a node to be the **current node** (Most of the time it is the root node)
2. Inspect the value at the current node
3. Three scenarios:
	3.1. If we have found the value what we are looking for => Great!
	3.2. If the value < the current node, search for it in the left sub-tree
	3.3. If the value > the current node, search for it in the right sub-tree
4. Repeat from 1 to 3
### Efficiency

As each step eliminates HALF of the remaining nodes from our search, and if there are $N$ nodes in a balanced binary tree, there will be about $\approx\log(N)$ levels/rows. Also, as each step of the search causes us to move down a level, we **take up to as many steps** as there are levels in the tree => Searching a binary tree takes $O(\log(N))$