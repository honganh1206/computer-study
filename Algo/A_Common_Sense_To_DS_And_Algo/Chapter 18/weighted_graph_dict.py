"""
Think of the data structure like this
self.edges = {
    1: {2: 3, 3: 5},
    2: {3: 4}
}
"""
import custom_min_heap

class WeightedGraph:
    def __init__(self, edge_list):
        self.edges = {}
        for parent_vertex, child_vertex, weight in edge_list:
            # The parent vertex is a key with value as { "child_vertex" : "weight" }
            if parent_vertex not in self.edges:
                self.edges[parent_vertex] = {}
            # Inner + outer dictionaries are used here
            self.edges[parent_vertex][child_vertex] = weight

    def get_weight(self, parent_vertex, child_vertex):
        return self.edges[parent_vertex][child_vertex]

    def dijkstra_shortest_path(self, start_vertex, end_vertex):
        # Store (distance, vertex) pairs
        priority_queue = custom_min_heap.MinHeap()
        priority_queue.insert((0, start_vertex))
        # Store the shortest known distance to each vertex
        weights = { vertex: float('infinity') for vertex in self.edges }
        weights[start_vertex] = 0
        # Store the previous vertex on the shortest path
        previous_vertices = { vertex: None for vertex in self.edges }
        while not priority_queue.is_empty():
            current_weight, current_vertex = priority_queue.delete()
            if current_vertex == end_vertex:
                return self.build_shortest_path(start_vertex, end_vertex, current_vertex, previous_vertices, weights)
            # Check if the weight from the priority queue is smaller than the already recorded smallest weight
            if current_weight > weights[current_vertex]:
                continue
            self.find_next_vertex(current_vertex, current_weight, weights, previous_vertices, priority_queue)
        return None, float('infinity')

    def build_shortest_path(self, start_vertex, end_vertex, current_vertex, previous_vertices, weights):
      shortest_path = []
      while previous_vertices[current_vertex] is not None:
          shortest_path.insert(0, current_vertex)
          current_vertex = previous_vertices[current_vertex]
      shortest_path.insert(0, start_vertex)
      return shortest_path, weights[end_vertex]

    def find_next_vertex(self, current_vertex, current_weight, weights, previous_vertices, priority_queue):
        for adjacent_vertex, weight in self.edges.get(current_vertex, {}).items():
          new_weight = current_weight + weight
          # Calculate and update the smallest weight
          if adjacent_vertex not in weights or new_weight < weights[adjacent_vertex]:
            weights[adjacent_vertex] = new_weight
            previous_vertices[adjacent_vertex] = current_vertex
            priority_queue.insert((new_weight, adjacent_vertex))

    def __str__(self):
        edges_str = "\n".join(
            f"{parent} -> {child} (weight: {weight})"
            for parent, children in self.edges.items()
            for child, weight in children.items()
        )
        return f"WeightedGraph:\n{edges_str}"

    def __repr__(self):
        return f"WeightedGraph({self.edges})"


edge_list = [
    ("Atlanta", "Boston", 100),
    ("Atlanta", "Denver", 160),
    ("Boston", "Chicago", 120),
    ("Boston", "Denver", 180),
    ("Chicago", "El Paso", 80),
    ("Denver", "Chicago", 40),
    ("Denver", "El Paso", 140),
]

g = WeightedGraph(edge_list)

# print(g)
# repr(g)

# print(g.get_weight("A", "C"))
path, weight = g.dijkstra_shortest_path("Atlanta", "El Paso")
print(f"Shortest path: {path}, Distance: {weight}")
