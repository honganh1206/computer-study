class CustomQueue:
    def __init__(self):
        self.data = []

    def is_empty(self):
        return len(self.data) == 0

    def enqueue(self, element):
        self.data.append(element)

    def dequeue(self):
        return self.data.pop(0)

    def read(self):
        if not self.is_empty():
            return self.data[0]
        else:
            return None


class Vertex:
    def __init__(self, value):
        self.value = value
        self.adjacent_vertices = []

    def add_adjacent_vertex(self, vertex):
        # Ensure no infinite loop of adding each other
        if vertex in self.adjacent_vertices:
            return
        self.adjacent_vertices.append(vertex)
        self.add_adjacent_vertex(self)

    def dfs_traverse(self, vertex, visited_vertices=None):
        if vertex is None:
            print("Cannot start DFS traversal from a None vertex.")
            return
        if visited_vertices is None:
            visited_vertices = {}
        visited_vertices[vertex.value] = True
        print(vertex.value)
        for adjacent_vertex in vertex.adjacent_vertices:
            if adjacent_vertex.value in visited_vertices:
                continue
            self.dfs_traverse(adjacent_vertex, visited_vertices)

    def dfs(self, vertex, search_value, visited_vertices=None):
        if vertex is None:
            raise ValueError("Cannot start DFS traversal from a None vertex.")
        if search_value is None:
            raise ValueError("Cannot start DFS with a None search value.")
        if visited_vertices is None:
            visited_vertices = {}
        if vertex.value == search_value:
            return vertex
        visited_vertices[vertex.value] = True
        for adjacent_vertex in vertex.adjacent_vertices:
            if adjacent_vertex.value in visited_vertices:
                continue
            if adjacent_vertex.value == search_value:
                return adjacent_vertex
            vertex_searching_for = self.dfs(
                adjacent_vertex, search_value, visited_vertices
            )
            if vertex_searching_for:
                return vertex_searching_for
        return None

    def bfs_traverse(self, starting_vertex):
        queue = CustomQueue()
        visited_vertices = {}
        visited_vertices[starting_vertex.value] = True
        queue.enqueue(starting_vertex)
        while queue.read() is not None:
            current_vertex = queue.dequeue()
            print(current_vertex.value)
            for adjacent_vertex in current_vertex.adjacent_vertices:
                if adjacent_vertex.value not in visited_vertices:
                    visited_vertices[adjacent_vertex.value] = True
                    queue.enqueue(adjacent_vertex)

    def bfs(self, starting_vertex, search_value):
        if starting_vertex.value == search_value:
            return starting_vertex
        queue = CustomQueue()
        visited_vertices = {}
        visited_vertices[starting_vertex.value] = True
        queue.enqueue(starting_vertex)
        while queue.read() is not None:
            current_vertex = queue.dequeue()
            if current_vertex.value == search_value:
                return current_vertex
            for adjacent_vertex in current_vertex.adjacent_vertices:
                if adjacent_vertex.value not in visited_vertices:
                    visited_vertices[adjacent_vertex.value] = True
                    queue.enqueue(adjacent_vertex)
        return None


# Create vertices
a = Vertex("A")
b = Vertex("B")
c = Vertex("C")
d = Vertex("D")
e = Vertex("E")
f = Vertex("F")
g = Vertex("G")
h = Vertex("H")
i = Vertex("I")
j = Vertex("J")
k = Vertex("K")
l = Vertex("L")
m = Vertex("M")
n = Vertex("N")
o = Vertex("O")
p = Vertex("P")

# Add adjacent vertices
a.add_adjacent_vertex(b)
a.add_adjacent_vertex(c)
a.add_adjacent_vertex(d)

b.add_adjacent_vertex(a)
b.add_adjacent_vertex(e)
b.add_adjacent_vertex(f)

c.add_adjacent_vertex(a)
c.add_adjacent_vertex(g)

d.add_adjacent_vertex(a)
d.add_adjacent_vertex(h)
d.add_adjacent_vertex(i)

e.add_adjacent_vertex(b)
e.add_adjacent_vertex(j)

f.add_adjacent_vertex(b)
f.add_adjacent_vertex(j)

g.add_adjacent_vertex(c)
g.add_adjacent_vertex(k)

h.add_adjacent_vertex(d)
h.add_adjacent_vertex(l)
h.add_adjacent_vertex(m)

i.add_adjacent_vertex(d)
i.add_adjacent_vertex(m)
i.add_adjacent_vertex(n)

j.add_adjacent_vertex(e)
j.add_adjacent_vertex(f)
j.add_adjacent_vertex(o)

k.add_adjacent_vertex(g)

l.add_adjacent_vertex(h)

m.add_adjacent_vertex(h)
m.add_adjacent_vertex(i)

n.add_adjacent_vertex(i)
n.add_adjacent_vertex(p)

o.add_adjacent_vertex(j)

p.add_adjacent_vertex(n)

# # Exercise 2
# a.dfs_traverse(a)

# # Exercise 3
# a.bfs_traverse(a)

# Exercise 4
print(a.bfs(a, "A"))
