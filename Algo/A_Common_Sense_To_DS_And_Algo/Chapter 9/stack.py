class Stack:
    def __init__(self):
        self.data = []

    def is_empty(self):
        return len(self.data) == 0

    def push(self, item):
        self.data.append(item)

    def pop(self):
        if not self.is_empty():
            return self.data.pop()
        else:
            raise IndexError("pop from an empty stack")

    def read(self):
        if not self.is_empty():
            return self.data[-1]
        else:
            return None

    def size(self):
        return len(self.data)
