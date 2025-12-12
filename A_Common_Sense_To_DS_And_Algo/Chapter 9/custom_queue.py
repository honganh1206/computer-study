class Queue:
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
