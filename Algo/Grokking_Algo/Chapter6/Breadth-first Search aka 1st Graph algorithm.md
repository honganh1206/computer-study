```ad-summary
Breadth-first search tells you if **there’s a path from A to B**. If there’s a path, breadth-first search will **find the shortest path**.
- If you have a problem like “find the shortest X,” try **modeling your problem as a graph**, and use **breadth-first search** to solve.
- A directed graph has **arrows**, and the relationship follows the direction of the arrow (rama -> adit means “rama owes adit money”).
- Undirected graphs don’t have arrows, and the relationship goes both
ways (ross - rachel means “ross dated rachel and rachel dated ross”).
- Queues are FIFO (First In, First Out) >< Stacks are LIFO (Last In, First Out).
- You need to check people in the order they were added to the search list, so the search list needs to be a queue. Otherwise, you won’t get the shortest path.
- Once you check someone, **make sure you don’t check them again**. Otherwise, you might end up in an infinite loop.

```


# What is a graph?

- A set of connections, made up of **nodes** and **edges**

![[Pasted image 20231029214800.png]]

# Breadth-first search definition

```ad-important

Answer 2 questions
1. Is there a path from node A to node B?
2. What is the shortest path?

```


## Finding the shortest path

- Scenario: Connect to a person who sells mango
- Step 1: Go through your list of friends (1st degree connection)

![[Pasted image 20231029215737.png]]

- Step 2: If there is no mango seller in your list of friends => Add all friends of those who do not (2nd degree connection)  => Each time you search for someone from the list, **add all of their friends to the list**

## Queues

- Only two options: _enqueue_ and _dequeue_
- Follow the _FIFO_ (First-In-First-Out) data structure >< *LIFO* (Last-In-First-Out) of stack

# Implementing the graph

```python
graph = {}
graph["you"] = ["alice", "bob", "claire"]
graph["bob"] = ["anuj", "peggy"]
graph["alice"] = ["peggy"]
graph["claire"] = ["thom", "jonny"]
graph["anuj"] = []
graph["peggy"] = []
graph["thom"] = []
graph["jonny"] = []
```

- *Directed graph*: The relationship is only **one way** >< *Undirected graph*

![[Pasted image 20231101162821.png]]

# Implement the algo

```ad-warning
Make sure to mark an element that has been checked already, so that the algo will not go into an infinite loop

```

# Running time

- Search the entire networks => $O(n)$ with $n$ being *the number of connections/edges*
- Add a node to the graph => $O(1)$
- Total run time: $O(V + E)$ with $V$ being *number of vertices/nodes* and $E$ being *number of edges*

# Topological sort

![[Pasted image 20231101174314.png]]

-  If task A depends on task B, task A shows up later in the list.

# Tree

A tree is a special type of graph, where **no edges ever point back**.

![[Pasted image 20231101174829.png]]



---
# Exercises

6.1. 2

6.2. 2

6.3. A - Invalid, B - Valid, C - Invalid

6.4. 
1.  Wake up
2. Brush teeth
3. Exercise
4. Eat breakfast
5. Shower
6. Pack lunch
7. Get dressed

6.5. A and C