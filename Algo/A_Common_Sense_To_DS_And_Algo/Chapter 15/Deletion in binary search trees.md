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
> If the to-be-deleted node *has no or 1 child*, we can simply *delete it and plug it’s child node into the deleted node’s spot*. However, when we *delete a node with 2 children*, we must find a **successor/predecessor** (as a leaf node) than replace the value of the deleted node with the value of the successor/predecessor.



![Binary Search Tree Deletion](https://youtu.be/DkOswl0k7s4)

### Node with 1 child

If the node being deleted has no children, we can just delete it. Otherwise, we must **delete the node and plug the child node into the deleted node’s spot.**

### Node with 2 children

We have 2 approaches: We can either find the **successor node** or the **predecessor node**.

The successor node is the *smallest node in the right subtree* of the node we are about to delete, while the predecessor node is the *largest node in the left subtree*. After that we can replace the value of the deleted node with the value of the successor/predecessor node.

