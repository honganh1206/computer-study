Two types: **Virtual addresses** refer to storage locations in a process's virtual address space, and **physical addresses** refer to locations in RAM

## Physical Memory

If two processes P1 and P2 run the same program, they will have separate copies of the `x` variable, each stored at a different location in RAM

Each process gets its own separate physical storage locations.

![[01-Areas/Computer/SystemDesign/Dive_Into_Systems/notes/chapter13/image-20.png]]

## Virtual Memory and Virtual Addresses

If two processes run the same binary executable, their function code and global variables will have *exactly the same virtual addresses* in their address spaces.

> Since two processes have runtime differences, the virtual addresses of space in heap and local variables on the stack may vary slightly.

![[01-Areas/Computer/SystemDesign/Dive_Into_Systems/notes/chapter13/image-21.png]]

Assembly and machine code's instructions refer to virtual addresses, so when the CPU executes instructions with identical virtual addresses when two processes execute the same `a.out`.

## Translation from Virtual to Physical

When the CPU executes an instruction, the virtual address from the CPU must be translated to its corresponding physical address in RAM.

*Processors provide some hardware support for virtual memory*, and the OS makes use of this to perform translation instead of handling it itself. The translation is done by [[Memory management unit (MMU)]]

> [!question] How can the OS protects processes from accessing one another's memory spaces?
> The OS **swaps per-process address mapping state** on the occasion of a context switch, and in that way the virtual addresses of processes do not get tangled up.