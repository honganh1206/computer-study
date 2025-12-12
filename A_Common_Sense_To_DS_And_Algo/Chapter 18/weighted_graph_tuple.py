class Edge:
    def __init__(self, parent_child_tuple, weight):
        parent_vertex, child_vertex = parent_child_tuple
        self._from = parent_vertex
        self._to = child_vertex
        self._weight = weight

    def __repr__(self):
        return f"from {self._from} to {self._to} weighted {self._weight}"


class Graph:
    def __init__(self, edge_list=None):
        self._vertices = []
        self._edges = []
        if edge_list is not None:
            self.add_edges(edge_list)

    def add_vertex(self, vertex):
        self._vertices.append(vertex)

    def add_edge(self, parent_child_tuple, weight):
        parent_vertex, child_vertex = parent_child_tuple
        if parent_vertex not in self._vertices:
            self._vertices.append(parent_vertex)
        if child_vertex not in self._vertices:
            self._vertices.append(child_vertex)
        new_edge = Edge(parent_child_tuple, weight)
        self._edges.append(new_edge)

    def add_edges(self, edge_list):
        for parent_child_tuple, weight in edge_list:
            self.add_edge(parent_child_tuple, weight)

    # Return vertices and edges as a string when printing the graph
    def __str__(self):
        return f"{self._vertices}\n{self._edges}"


edge_list = [((0, 2), 4), ((0, 1), 2), ((0, 3), 3), ((2, 3), 2), ((3, 0), 3)]
g = Graph(edge_list)

print(g)
