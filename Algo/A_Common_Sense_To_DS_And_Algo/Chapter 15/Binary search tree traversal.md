---
tags:
  - "#study"
  - "#review"
  - "#algorithm"
  - "#programming"
cssclasses:
  - center-images
---

> [!summary]
> 
> When we say traversing a binary tree, we mean *we will access every single node of the tree*. In detail, we do traversing with recursion until we hit a node without a left child, after that we visit the node then continue until we hit a node without a right child

Traversing means we visit every single node in the tree. To do so, we must ensure that we *traverse the tree in alphabetically ascending order* with a recursive function `traverse()` and the base case = a child that does not exist:
1. Select a node and call it the current node
2. Call the `traverse()` function recursively on the current node until we hit a node without a left child
3. Visit the current node node
4. Call the `traverse()` function recursively again until we hit a node without a right child


```
inOrderTraverse(node): 
	if node is not NULL: 
		inOrderTraverse(node.left) 
		print(node.value) 
		inOrderTraverse(node.right)

```
