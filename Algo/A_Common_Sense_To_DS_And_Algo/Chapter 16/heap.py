class Heap:
    def __init__(self):
        self.data = []

    def root_node(self):
        return self.data[0]

    def last_node(self):
        return self.data[-1]

    def left_child_index(self, index):
        return (index * 2) + 1

    def right_child_index(self, index):
        return (index * 2) + 2

    def parent_index(self, index):
        return (index - 1) // 2

    def insert(self, value):
        self.data.append(value)
        new_node_index = len(self.data) - 1
        parent_new_node_index = self.parent_index(new_node_index)
        while (
            new_node_index > 0
            and self.data[new_node_index] > self.data[parent_new_node_index]
        ):
            # Iteratively bubbling up the new node
            self.data[parent_new_node_index], self.data[new_node_index] = (
                self.data[new_node_index],
                self.data[parent_new_node_index],
            )
            new_node_index = parent_new_node_index

    def delete(self):
        self.data[0] = self.data.pop()
        trickle_node_index = 0
        # Trickling down the node
        while self.has_greater_child(trickle_node_index):
            larger_child_index = self.calculate_larger_child_index(trickle_node_index)
            self.data[trickle_node_index], self.data[larger_child_index] = (
                self.data[larger_child_index],
                self.data[trickle_node_index],
            )
            trickle_node_index = larger_child_index

    """
    Check whether the node at index has left + right children
    and if either of those child is larger than that node
    """

    def has_greater_child(self, index):
        left_index = self.left_child_index(index)
        right_index = self.right_child_index(index)

        left_child_exists = left_index < len(self.data)
        right_child_exists = right_index < len(self.data)

        left_child_greater = (
            left_child_exists and self.data[left_index] > self.data[index]
        )
        right_child_greater = (
            right_child_exists and self.data[right_index] > self.data[index]
        )

        return left_child_greater or right_child_greater

    def calculate_larger_child_index(self, index):
        left_index = self.left_child_index(index)
        right_index = self.right_child_index(index)
        if right_index >= len(self.data):  # Check if the right index is out of bound
            return left_index
        if self.data[right_index] > self.data[left_index]:
            return right_index
        else:
            return left_index


class TestHeap:
    def __init__(self):
        self.heap = Heap()

    def run_tests(self):
        self.test_insert()
        self.test_delete()
        self.test_root_node()
        self.test_last_node()
        self.test_left_child_index()
        self.test_right_child_index()
        self.test_parent_index()
        self.test_has_greater_child()
        self.test_calculate_larger_child_index()
        print("All tests passed!")

    def assert_equal(self, a, b):
        if a != b:
            raise AssertionError(f"Assertion failed: {a} != {b}")
        else:
            print(f"Assertion passed: {a} == {b}")

    def test_insert(self):
        self.heap = Heap()
        self.heap.insert(10)
        self.assert_equal(self.heap.data, [10])

        self.heap.insert(20)
        self.assert_equal(self.heap.data, [20, 10])

        self.heap.insert(15)
        self.assert_equal(self.heap.data, [20, 10, 15])

        self.heap.insert(30)
        self.assert_equal(self.heap.data, [30, 20, 15, 10])

    def test_delete(self):
        self.heap = Heap()
        values = [10, 20, 15, 30, 25, 5]
        for val in values:
            self.heap.insert(val)

        self.assert_equal(self.heap.data, [30, 25, 15, 10, 20, 5])

        self.heap.delete()
        self.assert_equal(self.heap.data, [25, 20, 15, 10, 5])

        self.heap.delete()
        self.assert_equal(self.heap.data, [20, 10, 15, 5])

        self.heap.delete()
        self.assert_equal(self.heap.data, [15, 10, 5])

    def test_root_node(self):
        self.heap = Heap()
        self.heap.insert(10)
        self.heap.insert(20)
        self.assert_equal(self.heap.root_node(), 20)

    def test_last_node(self):
        self.heap = Heap()
        self.heap.insert(10)
        self.heap.insert(20)
        self.heap.insert(30)
        self.assert_equal(self.heap.last_node(), 10)

    def test_left_child_index(self):
        self.assert_equal(self.heap.left_child_index(0), 1)
        self.assert_equal(self.heap.left_child_index(1), 3)

    def test_right_child_index(self):
        self.assert_equal(self.heap.right_child_index(0), 2)
        self.assert_equal(self.heap.right_child_index(1), 4)

    def test_parent_index(self):
        self.assert_equal(self.heap.parent_index(1), 0)
        self.assert_equal(self.heap.parent_index(2), 0)
        self.assert_equal(self.heap.parent_index(3), 1)
        self.assert_equal(self.heap.parent_index(4), 1)

    def test_has_greater_child(self):
        self.heap = Heap()
        self.heap.insert(10)
        self.heap.insert(20)
        self.assert_equal(self.heap.has_greater_child(0), True)
        self.assert_equal(self.heap.has_greater_child(1), False)

    def test_calculate_larger_child_index(self):
        self.heap = Heap()
        self.heap.insert(10)
        self.heap.insert(20)
        self.heap.insert(15)
        self.assert_equal(self.heap.calculate_larger_child_index(0), 1)


if __name__ == "__main__":
    tester = TestHeap()
    tester.run_tests()
