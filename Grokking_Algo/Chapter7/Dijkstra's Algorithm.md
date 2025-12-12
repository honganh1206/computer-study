```ad-summary
- Breadth-first search is used to calculate the shortest path for an **unweighted** graph.
- Dijkstra’s algorithm is used to calculate the shortest path for a **weighted** graph.
- Dijkstra’s algorithm works when **all the weights are positive**.
- If you have negative weights, use the Bellman-Ford algorithm.

```

# Working with Dijkstra's Algo

```ad-important
title: 4 steps
1. Find the **"cheapest"** node - Node to get to in the least amount of time
2. **Update** the cost of nodes neighboring the cheapest node
3. Repeat Step 1-2 until you've done this to **every node**
4. Calculate the final path
```


## Step 1

![[Pasted image 20231104120314.png]]

- Find the cheapest node => Node B with 2 mins

## Step 2

- Calculate how long it will takes to get from start to **all of** node B's neighbor by **following all edges from B** + Find the shorter path
	- B -> A: 3 mins
		- Start -> B -> A: 5 mins **(Shorter)**
		- Start -> A: 6 mins
	- B -> Finish: 5 mins 
		- Start -> B -> Finish: 7 mins

![[Pasted image 20231104120509.png]]

## Step 3

- Step 1 again: Find the cheapest node => Node A with 5 mins
- Step 2 again: Update cheapest node with all neighboring nodes
	- A -> Finish (only neighbor): 1 mins => Start -> Finish: 6 mins

![[Pasted image 20231104122449.png]]

## Step 4

![[Pasted image 20231104122431.png]]

## Terminology

- Each edge in the graph has a *number associated with it* => **Weights**
	- Unweighted => Breadth-first search
	- Weighted => Dijkstra's Algo

![[Pasted image 20231104123701.png]]

- Graphs can also have *cycles*, and cycles *add more weight*

![[Pasted image 20231104123801.png]]

# Trading for a piano

![[Pasted image 20231104125605.png]]

```ad-todo
Make a table of the cost for each node before we start. The cost = how expensive it is to get to from the start

```

| Node   | Parent | Total Cost |
| ------ | ------ | ---------- |
| LP     | Book   | 5          |
| Poster | Book   | 0 (Cheapest)          |
| Guitar | LP     | 20 (Cheapest) => New Parent of both instruments is LP        |
| Drum   | LP     | 25         |
| Guitar | Poster | 30         |
| Drum   | Poster | 35         |
| Piano  | Guitar | 40         |
| Piano  | Drum       | 35 (Cheapest)           |


![[Pasted image 20231104150455.png]]

# Negative-weight edges

- Scenario: Supposed that Alex will give Rama $7 if Rama trades his LP for Alex's poster

![[Pasted image 20231104184449.png]]


```ad-warning
- You can’t use Dijkstra’s algorithm if you have negative-weight edges, as they *break the algorithm*
- For negative-weight edges, we should use *Bellman-Ford algorithm*..

```

- When updating the cost of LP (Poster), we have already processed that Poster node => *Once you process/visit a node, it means there's no cheaper way to get to that node/that node has been visited*

![[Pasted image 20231104185311.png|The node Poster has already processed when considering the price to Drums, so its cost cannot be updated]]


# Implementation

![[Pasted image 20231108154242.png]]


```
# Pseudo code 
node = find_lowest_cost_node(costs)
while node is not None:
	cost = costs[node]
	neighbors = graph[node]
	for n in neighbors.keys():
		new_cost = cost + neighbors[n]
		if costs[n] > new_cost: # find the cheaper path
			costs[n] = new_cost
			parents[n] = node # current node becomes parent of neighbor
	processed.append(node)
	node = find_lowest_cost_node(costs) # find the next node to process
		
```

```ad-tip
Full explanation + visuals of how `find_lowest_cost_node()` works is from p.135 - p.138

```

---
# Exercises

7.1
A - 8
B - 60
C - No shortest path (negative-weight)