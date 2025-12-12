from stack import Stack


class StringReverse:
    def __init__(self):
        self.stack = Stack()

    def reverse_string(self, str):
        for char in (char for char in str):
            self.stack.push(char)
        reversed_str = ""
        """
        In Python, non-empty objects are considered truthy, so even if the stack is empty, self.stack will evaluate to True, leading to an infinite loop. => Use `is_empty()`
        """
        while not self.stack.is_empty():
            reversed_str += self.stack.pop()

        return reversed_str


string_reverse = StringReverse()
print(string_reverse.reverse_string("abc"))
