# Keep your priorities straight with heaps


> [!tldr]
> 
> - Heap is a type of binary tree in which the values of the nodes are smaller/greater than the value of their parent, and nodes are filled from left to right.
> - The heap has two primary functions: Adding a new node and bubble it up (Insertion) and replace the root node with the smallest node and trickle down the smallest node (Deletion)
> - The heap works really well as a priority queue, as it allows us to quickly access the highest-priority item and insert new values.

## Priority queues

- A priority queue is a list whose deletions and access are just like a classic queue (from the front of the queue), but whose insertions are like an ordered array (data remains sorted in a specific order). => Used to implement the triage system in hospitals (treat people in the order of the severity)
- The end of the array = the front of the priority queue => Insert at the beginning ($O(N)$) + Delete at the end ($O(1)$)

## Heaps

- A type of **tree data structure** that can be leveraged to **keep tabs** on the greatest or least data element in the dataset
- Binary heap comes with the max-heap and the min-heap
- Conditions:
	1. The value of each node must be greater (max-heap) or smaller (min-heap) than each of its descendant nodes
	2. The tree must be complete (all levels of the tree are fully filled except possibly for the last level, which is filled from left to right.)

![[Pasted image 20240629144003.png|500]]



> [!question] Why is this still a complete tree?
> 
> 
> This would still be qualified as a complete tree, as there are no nodes present after the rightmost node at that level.
> 
```
        10
       /  \
      9    8
     / \  / \
    7  6 5   4
   / 
  3   

```


## Heap properties

- Heaps are **weakly ordered** compared to binary search trees
- The root node is the item with the **highest priority** as it will always have the **greatest (max-heap)/smallest (min-heap) value**
- The heap has two primary operations: inserting and deleting. An optional operation is reading (looking at the root node)
- The heap has a **last node** - The rightmost node in its bottom level and also the final element in the array.

![[Pasted image 20240629153643.png]]
## Heap insertion

Steps:

1. Create a node at the rightmost spot of the lowest level => The heap’s new last node
2. Compare the new node with its parent node
3. If new node > parent node, swap new node with the parent node
4. Continue with step 3 until the new node has a parent with a value greater than its => Trickling/Bubbling up the node

=> $O(\log(N))$ efficiency based on height of the heap + number of comparisons and swaps


## Looking for the last node & Problem of the last node

- It is **impossible** to efficiently find the heap’s last node without having to inspect each and every node

> [!question] 
> 
> - When inserting, why could not we insert new values elsewhere inside the heap? => As the new node will be inserted into the bottom leftmost node, we might **cause imbalance** if we do so.
> ![[Pasted image 20240629162414.png]]
> - When deleting, why could not we replace the root node with some other node other than the last node? => Doing this might **violate the properties of the heap (completeness and balance)** and **cause inefficiency** in the heap’s logarithmic time complexity.


## Heap deletion

- **We only ever delete the root node**
- Steps:
	1. Move the last node into where the root node was => Remove the original root node
	2. Trickle the root node down to its proper place (Trickling logic)

### Trickling logic

1. Check the children of the node to be trickled
2. If trickle node < the larger of the two child nodes, we swap the trickle node with the larger child node
3. Repeat step 1 + 2 until the trickle node has no children who are greater than it

![Visualization](https://www.youtube.com/watch?v=uescHE7Rw9k)

## Heap vs Ordered Array


|           | Ordered Array | Heap        |
| --------- | ------------- | ----------- |
| Insertion | $O(N)$        | $O(log(N))$ |
| Deletion  | $O(1)$        | $O(log(N))$ |

## Arrays as heaps

- Heaps are usually implemented using arrays to efficiently find the last node

![[Pasted image 20240629164051.png]]

### Root and Children Relationship

- **Root Node:** The root node is at index 0.
- We index each node from left to right

> [!info] Why we choose array to implement the heap?
> 
> The last node will ALWAYS be at the end of the array, as it is the item with the highest priority.

### Traversing an array-based heap

- **Left Child:** For any node at index $i$, the left child is at index $(2 * i) + 1$.
- **Right Child:** For any node at index $i$, the right child is at index $(2 * i) + 2$
- Parent: For any node at index $i$, the parent node is $\frac{i-1}{2}$


## Heaps as Priority queues

- The heap gives us access to the highest-priority item (root node)
- The heap’s weak ordering is an advantage, as it **allows us to insert new values at $O(\log N)$ time.**

## Exercises

### Ex1

![[Ex1]]

### Ex2

[![[02-Areas/Algo_DataStruct/Algorithm_Study_Notes/A_Common_Sense_To_DS_And_Algo/Chapter 16/Ex2]]


### Ex3

`[99, 22, 68, 10, 2, 34, 55]`

