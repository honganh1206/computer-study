 `%rsp` is the **stack pointer** and `%rbp` is the **frame pointer/base pointer**. Both registers are *reserved* by the compiler for operations that *maintain the layout of the program stack* 

`%rsp` *always* points to the top of the stack

In the past, `%rbp` was used to track the base of the active stack and help to reference parameters. But this pointer has been less frequently used in x86-64

[[Stack frame and frame record]]

[[Common function management instructions]]

