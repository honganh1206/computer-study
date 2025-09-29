[[Heap]]

[[Stack]]

The stack space grows when the process makes function calls and shrinks when we return from functions. The heap space grows when the process dynamically allocates memory space via `malloc` and shrinks when the process frees dynamically allocated memory space via `free`.

> [!important]
> `malloc` and `free` only make changes to how much of the heap and stack parts are being used by the process, not the actual capacity of heap and stack.

The OS can change the total capacity of heap (`brk`, `sbrk`, and `nmap`) and stack space, but programmers do not usually directly invoke such commands.
