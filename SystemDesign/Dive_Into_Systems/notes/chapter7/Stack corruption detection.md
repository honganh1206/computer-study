Recent versions of GCC use a **canary** that works as a guard between the buffer and other elements of the stack.

What is a canary? A value stored in a non-writable section of memory that can be compared to a value on a stack. If the canary "dies" during a program's execution, the program will know it's under attack and will abort with an error message.

However, the attacker can still replace the canary to prevent the program from detecting a stack corruption.

