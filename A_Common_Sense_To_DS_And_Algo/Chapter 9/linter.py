from .stack import Stack


class Linter:
    def __init__(self):
        self.stack = Stack()

    def lint(self, text):
        for char in (char for char in text):
            # Add the opening brace to the stack
            if self.is_opening_brace(char):
                self.stack.push(char)
            # Pop the opening brace off the stack if we encounter its closing counterpart
            elif self.is_closing_brace(char):
                popped_opening_brace = self.stack.pop()
                # If the popped element does not exist, the opening brace does not have a closing counter part
                if not popped_opening_brace:
                    return f"{char} does not have an opening brace"
                # Or if it has a mismatched counterpart
                if self.is_not_a_match(popped_opening_brace, char):
                    return f"{char} has mismatched opening brace"
        # if we get to the end of the line, and the stack is not empty, that means we have no corresponding closing brace
        if self.stack.read():
            return f"{self.stack.read()} does not have a closing brace"
        return True

    def is_opening_brace(self, char):
        return char in ["(", "[", "{"]

    def is_closing_brace(self, char):
        return char in [")", "]", "}"]

    def is_not_a_match(self, opening_brace, closing_brace):
        braces_map = {"(": ")", "[": "]", "{": "}"}
        return closing_brace != braces_map.get(opening_brace)


linter = Linter()
print(
    linter.lint(
        """
(var x = {y: [1, 2, 3]})
"""
    )
)
