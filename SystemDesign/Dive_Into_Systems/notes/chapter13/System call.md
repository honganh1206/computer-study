A way for applications to communicate with the OS.

If a program wants to know the current time of day, it can invoke `gettimeofday` system call from the OS.

System calls are implemented using *special trap instructions* defined as part of the [[Instruction Set Architecture]]

## How do they work?

1. The OS associates each of the system calls with a *unique identification number*.
2. When an application wants to invoke a system call, it places the call's number in a *known location* (vary according to the ISA) + issues a *trap instruction* to interrupt the OS (from its sleep?)
3. The trap instruction triggers the CPU to *stop executing instructions from a program* + *start executing OS instructions* to handle the trap.
4. The trap handler (OS instructions) reads the call number and executes the corresponding system call.

Example of a system call:

```c
/* C code */
ret = write(fd, buff, size);

# IA32 translation
write:

...            # set up state and parameters for OS to perform write
movl $4, %eax  # load 4 (unique ID for write) into register eax
int  $0x80     # trap instruction: interrupt the CPU and transition to the OS
addl $8, %ebx  # an example instruction after the trap instruction
```