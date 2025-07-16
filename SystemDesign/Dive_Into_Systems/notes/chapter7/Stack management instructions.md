
| Instruction | Translation                                                                                                               |
| ----------- | ------------------------------------------------------------------------------------------------------------------------- |
| `push S`    | Pushes a copy of S onto the top of the stack. Equivalent to:<br><br>`sub $0x8, %rsp`<br>`mov S, (%rsp)`                   |
| `pop D`     | Pops the top element off the stack and places it in location D. Equivalent to:<br><br>`mov (%rsp), D`<br>`add $0x8, %rsp` |
`%rsp` and `%rbp` are stack pointer and frame pointer respectively, and they are reserved by the compiler for call stack management (Refer to [[Stack pointer and frame pointer]])

On x86-64 systems, the execution stack grows toward **lower** addresses.

Operations occur at the "top" of the stack

![[image-1.png|444x558]]

[[Processes]] have their own regions of memory called the **call stack**

> The call stack is located in process/virtual memory, unlike registers which are located on the CPU