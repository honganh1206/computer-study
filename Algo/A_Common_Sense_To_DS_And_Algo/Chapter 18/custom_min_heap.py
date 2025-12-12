class MinHeap:
    def __init__(self):
        self.heap = [] # Each element in the heap is in the tuple form of (distance, vertex)

    def _parent(self, index):
        return (index - 1) // 2

    def _left_child(self, index):
        return 2 * index + 1

    def _right_child(self, index):
        return 2 * index + 2

    def _has_left(self, index):
        return self._left_child(index) < len(self.heap)

    def _has_right(self, index):
        return self._right_child(index) < len(self.heap)

    def _swap(self, i, j):
        self.heap[i], self.heap[j] = self.heap[j], self.heap[i]

    def _get_distance(self, index):
        return self.heap[index][0]

    def _heapify_up(self, index):
        '''When adding a new element, the new element will be bubbled up to its correct position'''
        parent_index = self._parent(index)
        # Compare the distances of two vertices
        if index > 0 and self._get_distance(index) < self._get_distance(parent_index):
          self._swap(index, parent_index)
          self._heapify_up(parent_index)

    def _heapify_down(self, index):
        '''When removing the root node, bubbling down the last element (as root as we remove the old root) to its correct position'''
        smallest = index
        left = self._left_child(index)
        right = self._right_child(index)
        if self._has_left(index) and self._get_distance(left) < self._get_distance(smallest):
          smallest = left
        if self._has_right(index) and self._get_distance(right) < self._get_distance(smallest):
          smallest = right
        if smallest != index:
            self._swap(index, smallest)
            self._heapify_down(smallest)

    def insert(self, item):
        self.heap.append(item)
        self._heapify_up(len(self.heap) - 1)

    def delete(self):
        if self.is_empty():
            raise IndexError("Pop from empty heap")
        self._swap(0, len(self.heap) - 1)
        item = self.heap.pop()
        self._heapify_down(0)
        return item

    def is_empty(self):
        return len(self.heap) == 0
