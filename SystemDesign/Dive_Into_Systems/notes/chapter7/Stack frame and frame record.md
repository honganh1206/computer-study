 The **stack frame** a.k.a **activation frame/record** refers to the portion of the stack (as a block of memory) allocated to a single function call. Think of it like a "workspace" where a function stores its things.
 
The memory between stack pointer and base pointer is used for *local variables*. Before the function `fname` is called, it saves the previous function's frame pointer `%rbp` (in this case the previous function is `main` as the caller) as the **saved frame pointer**.

> Why do we have frame pointers? Every push/pop or sub/add operation changes the **stack pointer (`%rsp`)**, so the addresses of local variables or arguments would keep shifting during execution. `%rbp` equals the **stack pointer value at the start of the frame**, so locals and arguments always sit at fixed offsets relative to `%rbp`

The callee also sets its own `%rbp` at the address `0x418` holding the value `0x42c`

![[image-11.png|main as the caller function and fname as the callee function]]


The active stack frame of `fname` is *bounded* below by the base pointer `fname` at stack address `0x418`. What is stored at `0x418`? The value of `%rbp` i.e., `0x42c` which is an address *indicating the bottom of the activation frame for the `main` function.*

The top of the activation frame of `main`  is bounded by the **return address** (the address where execution should resume after the callee function returns by using jump instructions)

> The return address points to code segment memory like the instruction pointer, not stack memory. See [[Stack management instructions]]

While the stack pointer moves as local variables are pushed to/popped off the stack, *the frame pointer stays relatively constant*, only pointing to the beginning (bottom) of the stack -> As the frame pointer is a stable reference point, and compilers use it to address variables on the stack

