graph = {}
graph["start"] = {} # This hash table has MORE hash tables inside
graph["start"]["a"] = 6
graph["start"]["b"] = 2
graph["a"] = {}
graph["b"] = {}
graph["a"]["fin"] = 1
graph["b"]["fin"] = 5
graph["b"]["a"] = 3
graph["fin"] = {} # Finish node does not have any neighbor

# Cost hash table to represent total time taken to go from start -> fin
infinity = float("inf")
total_cost = {}
total_cost["a"] = 6
total_cost["b"] = 2
total_cost["fin"] = infinity

# Hash table for the parents
parents = {}
parents["a"] = "start"
parents["b"] = "start"
parents["fin"] = None

processed = []

def find_lowest_cost_node(total_cost):
    lowest_cost = float("inf")
    lowest_cost_node = None
    for node in total_cost: 
        '''
        Loop through each node and compare them to the previously examined node
        How it works: 
        1. Get cost for node A and compare it to node Fin => Node A has smaller weight
        2. Set node A as lowest cost node + Cost to node A as lowest cost
        3. Iterate to node B => Node B is the smallest after iterate through all nodes
        4. Return node B as the smallest of all
        '''
        cost = total_cost[node]
        if cost < lowest_cost and node not in processed:
            lowest_cost = cost
            lowest_cost_node = node
    return lowest_cost_node

def find_shortest_path():
    lowest_cost_node = find_lowest_cost_node(total_cost)
    while lowest_cost_node is not None:
        cost = total_cost[lowest_cost_node]
        neighbors = graph[lowest_cost_node]
        '''
        Loop through the neighbors of the lowest cost node
        Update the cost to the lowest cost node + Set the parent for the lowest cost node
        How it works:
        1. Current lowest cost node is node B => Iterate to node A (n) as the 1st neighbor
        2. Update the total cost to get to node A
        3. Compare cost from Start -> A with cost from Start -> B -> A => Latter one is shorter
        4. Set the lowest cost path as Start -> B -> A + B as parent of A
        5. Same thing for node Fin (Start -> B -> Fin takes 7 mins) => Break from the loop
        6. Mark node B as processed
        7. Set lowest cost node as node A
        8. Repeat with Node A to Node Fin as the only left path
        '''
        for n in neighbors.keys():
            new_cost = cost + neighbors[n]
            if total_cost[n] > new_cost:
                total_cost[n] = new_cost
                parents[n] = lowest_cost_node
        processed.append(lowest_cost_node)
        lowest_cost_node = find_lowest_cost_node(total_cost)

if __name__ == "__main__":
    find_shortest_path()
    print(total_cost["fin"])