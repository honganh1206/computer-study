
> [!summary] 3-sentence summary
> 
> - Stacks is similar to a vertical array and follow the LIFO principle
> - Queues follow the FIFO principle

[[Stacks]]

[[Queues]]

[[The importance of Constrained DS]]

## Exercises

1. Queue
2. 5 and 6
3. 1 and 2
4. Code:

```python
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
```