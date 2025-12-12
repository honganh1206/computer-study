---
tags:
  - "#study"
  - "#review"
cssclasses:
  - center-images
---
- Recursion is **tricky** for computers => The computer did not yet complete executing `factorial(3)`, yet it’s starting to run `factorial(2)` while still in the middle of `factorial(3)`.

- In order to track that the computer is still in the middle of `factorial(3)`, the computer **pushes that information onto a call stack**

![[Adding methods to call stack.excalidraw|200]]


- When the base case `factorial(1)` is called, `factorial(2)` is popped off the stack => **LIFO**

> [!info] Stack Overflow
> 
> In the case of infinite recursion, the computer just shuts down the recursion and says, “I refuse to call the function again, because I’m running out of memory!”