[Ref](https://diveintosystems.org/book/C7-x86_64/basics.html#_advanced_register_notation)

We have separate [[Registers]] for data, instructions and addresses. The Intel CPU has 16 registers to store 64-bit data: `%rax`, `%rbx`, `%rcx`, `%rdx`, `%rdi`, `%rsi`, `%rsp`, `%rbp`, and `%r8` to `%r15`

All registers, except `%rsp` and `%rbp`, can hold general-purpose 64-bit data.

A program may interpret contents from a register as an integer or an address, *the register itself makes no distinction*.

Programs can read from/write to *all 16 registers*

[[Stack pointer and frame pointer]]

Compilers typically store the first six parameters in registers `%rdi`, `%rsi`, `%rdx`, `%rcx`, `%r8` and `%r9`, respectively. What does this mean? When a function is called, the first six integer/pointer parameters are passed *via registers* instead of the stack for performance (Caller → Register → ALU)

Register `%rax` stores the *return value* from a function

`%rip` is the **instruction pointer**, sometimes called the **program counter**. It points to the next instruction to be executed by the CPU

> Programs can NOT directly write to `%rip`

