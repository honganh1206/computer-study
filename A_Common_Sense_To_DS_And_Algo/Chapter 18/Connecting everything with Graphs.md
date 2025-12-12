# Connecting everything with Graphs

> [!summary] 3-sentence summary
> - A graph shows how data is connected, and while all trees can be graphs, not all graphs are trees.
> - While BFS caters towards queue-like behaviors (traversing far away from the starting vertex), DFS has a more recursive approach (coming back to the starting vertex at the end).
> - The Dijkstra’s algorithm can be used for weighted graphs to calculate the shortest route from one vertex to another by constantly searching for adjacent vertices to reach with the minimum weight.


## Graphs

- A data structure specializing in **relationships** (how data is connected)

![[Pasted image 20240808000511.png]]


### Graphs vs. Trees

 - While all trees are graphs, not all graphs are trees.
 - If a graph is a tree:
 	- It should not have **cycles** (nodes referencing each other) 
 	- All of its nodes must be connected.

### Graph Jargon

- For graphs, we call each piece of data a **vertex**
- The lines between vertices are **edges**
- Vertices connected by edges are called **adjacent**
- A graph where all vertices are connected in some ways is called a **connected** graph.


## Directed Graphs

- Sometimes, relationships are not mutual => Use arrows to indicate the directions of the relationships

![[Pasted image 20240808002510.png]]

## Undirected Graphs

- Where all friendships are mutual (When A adds B as a friend, B adds A as a friend too) => All the vertices are connected


> [!note] Adjacency List vs. Adjacency Matrix
> 
> - Use an array to store a vertex’s adjacency vertices => Adjacency list
> - Use two-dimensional array to store adjacency vertices => Adjacency matrix


## Graph Search

> [!tip] Search in connected graphs
> 
> If we have access to one vertex in a graph, we must find another vertex connected to this vertex => Search can be used to find **any** vertex within the entire graph, even if we have access to just one random vertex

- Graph search can be used to find vertices or whether two vertices are connected or not


## Depth-First search

- Main goal: **Recursively traversing the graph with connected vertices** (with cycles) >< file system traversal (without cycles)
- Keep track visited vertices with a **hash table** with key = vertex and value = boolean value
- Traversing flow:
	1. Start at a random vertex
	2. Add the current vertex to the hash table
	3. Iterate through the current vertex’s adjacent vertices
	4. If we go through an already visited vertex => Ignore it
	5. If not => **Recursively** perform DFS on that vertex

## Breadth-First Search

- BFS uses **the queue** instead of recursion
- Flow:
	1. Start at any vertex
	2. Mark the starting vertex as visited
	3. Add the starting vertex to the queue
	4. Start a loop that runs while the queue is NOT empty
	5. In the loop, remove the first/current vertex from the queue
	6. Iterate through all adjacent vertices of the current vertex
	7. If the adjacent vertex was visited => Ignore it
	8. If not => Mark it as visited
	9. Repeat the loop from step 4 until the queue is empty


> [!info] DFS or BFS?
> 
> - Which one to use depends on the **nature of the graph you are searching and what you are searching for**.
> - BFS gradually moves away from the starting vertex (queue), while DFS immediately moves away from the starting vertex and only comes back to it until reaching the base case (recursion).
> - The answer depends on whether we want to stay close to the starting vertex (BFS) or we want to move far away from it (DFS).


## The efficiency of Graph Search

- In both search methods, the worst case would be **we are intending to do a full-graph traversal** or **the vertex we are looking for does not exist/last in the graph**
- However: In both algorithms, for each vertex we traverse, we also **iterate over all of its adjacent vertices by checking if they have been visited**
- We need two variables: One to represent the number of vertices $V$, and the other to represent the total number of adjacent neighbors $E$
$$
O(V+E)
$$


> [!hint]
> 
> While graph search touches each edge **more than once** depending on what the current vertex is, the Big O notation still remains $O(V+E)$ instead of $O(V+2E)$ as we drop the constants.


## Weighted Graphs

- Weighted = Additional information to the edges of the graph

![[Pasted image 20240815230913.png|A weighted graph representing several major cities in the US]]

### The Shortest Path problem

- An algorithm that finds the **cheapest price** to get to the destination

## Dijkstra’s Algorithm

### Setup

```python
cheapest_prices_table = {
    "Atlanta": 0,
    "Boston": 100,
    "Chicago": 200,
    "Denver": 160,
    "El Paso": 280,
}

# adjacent vertex - current vertex
cheapest_previous_stopover_city_table = {
    "Boston": "Atlanta",
    "Chicago": "Denver",
    "Denver": "Atlanta",
    "El Paso": "Chicago"
}
```

### Steps

1. Visit the starting vertex as the current vertex
2. Check the weight from the current vertex to its adjacent vertices
3. If the price to an adjacent vertex **from the starting vertex** is cheaper than the price in the `cheapest_prices_table` (or the adjacent vertex is not yet in the table), we can:
	1. Update the `cheapest_prices_table`
	2. Update the `cheapest_previous_stopover_city_table`, making the adjacent vertex the key + current vertex as value
4. Go to whichever unvisited vertex that has the cheapest price from the starting vertex, marking it as the current vertex
5. Repeat the step 2 → 4


### Efficiency

- The code implementation has a **considerable** effect on the algorithm’s time complexity
	- $O(V^2)$ => Each vertex has an edge leading to **every other vertex** within the graph
	- Faster with a priority queue to check unvisited vertices

## Exercises

1. Nail polish, pins, needles and hammer
2. 