class WeightedGraphVertex:
    def __init__(self, value):
        self.value = value
        self.adjacent_vertices = {}

    def add_adjacent_vertex(self, vertex, weight):
        self.adjacent_vertices[vertex] = weight

    def dijkstra_shortest_path(self, starting_vertex, destination_vertex):
        # Init tables to track smallest weights and previous vertices
        smallest_weight_table = {} # Map vertices to their smallest known weight
        smallest_previous_vertex = {} # Map vertices to the previous vertex in the shortest path
        unvisited_vertices = [] # Array for fastest access to the smallest unvisited option + performance for insertion and finding min vertex
        visited_vertices = {} # Hash table for lookup
        smallest_weight_table[starting_vertex.value] = 0
        current_vertex = starting_vertex
        while current_vertex:
            self.mark_vertex_as_visited(current_vertex, visited_vertices, unvisited_vertices)
            for adjacent_vertex, weight in current_vertex.adjacent_vertices.items():
                self.process_adjacent_vertex(adjacent_vertex, weight, current_vertex,
                                          smallest_weight_table, smallest_previous_vertex,
                                          visited_vertices, unvisited_vertices)
            # Move to the next unvisited vertex with the smallest weight
            current_vertex = self.get_next_vertex(unvisited_vertices, smallest_weight_table)
        return self.build_shortest_path(destination_vertex, starting_vertex, smallest_previous_vertex)

    def mark_vertex_as_visited(self, vertex, visited_vertices, unvisited_vertices):
        visited_vertices[vertex.value] = True
        if vertex in unvisited_vertices:
            unvisited_vertices.remove(vertex)

    def process_adjacent_vertex(self, adjacent_vertex, weight, current_vertex,
                                smallest_weight_table, smallest_previous_vertex,
                                visited_vertices, unvisited_vertices):
        """Process an adjacent vertex and update tables if a shorter path is found."""
        if adjacent_vertex.value not in visited_vertices:
            unvisited_vertices.append(adjacent_vertex) # Possible for a singular vertex to exist multiple times in this array
        # Calculate the weight to get from the starting vertex to the adjacent vertex
        # Using the current vertex as the second-to-last stop
        weight_starting_to_adjacent = smallest_weight_table[current_vertex.value] + weight
        # Update the tables if the new weight is smaller
        if adjacent_vertex.value not in smallest_weight_table or weight_starting_to_adjacent < smallest_weight_table[adjacent_vertex.value]:
                  smallest_weight_table[adjacent_vertex.value] = weight_starting_to_adjacent
                  smallest_previous_vertex[adjacent_vertex.value] = current_vertex.value

    def get_next_vertex(self, unvisited_vertices, smallest_weight_table):
      """Find the next unvisited vertex with the smallest weight."""
      return min(
            (vertex for vertex in unvisited_vertices if vertex.value in smallest_weight_table),
            key=lambda vertex: smallest_weight_table[vertex.value],
            default=None)

    def build_shortest_path(self, destination_vertex, starting_vertex, smallest_previous_vertex):
        """Construct the shortest path by backtracking from the destination."""
        shortest_path = []
        current_vertex_value = destination_vertex.value
        while current_vertex_value is not starting_vertex.value:
            shortest_path.append(current_vertex_value)
            current_vertex_value = smallest_previous_vertex[current_vertex_value]
        shortest_path.append(starting_vertex.value)
        return shortest_path[::-1]



atlanta = WeightedGraphVertex("Atlanta")
boston = WeightedGraphVertex("Boston")
chicago = WeightedGraphVertex("Chicago")
denver = WeightedGraphVertex("Denver")
el_paso = WeightedGraphVertex("El Paso")

atlanta.add_adjacent_vertex(boston, 100)
atlanta.add_adjacent_vertex(denver, 160)
boston.add_adjacent_vertex(chicago, 120)
boston.add_adjacent_vertex(denver, 180)
chicago.add_adjacent_vertex(el_paso, 80)
denver.add_adjacent_vertex(chicago, 40)
denver.add_adjacent_vertex(el_paso, 140)

print(atlanta.dijkstra_shortest_path(atlanta, el_paso))
