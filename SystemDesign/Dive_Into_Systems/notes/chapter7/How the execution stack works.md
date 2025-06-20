```c
int adder2(int a) {
	return a + 2;
}
```

`adder2` function compiled to Assembly:

```assembly
0000000000001149 <adder2>:
    1149:       f3 0f 1e fa             endbr64 
    114d:       55                      push   %rbp
    114e:       48 89 e5                mov    %rsp,%rbp
	# Store the parameter a to the component register %edi (part of %rdi)
    1151:       89 7d fc                mov    %edi,-0x4(%rbp)
    1154:       8b 45 fc                mov    -0x4(%rbp),%eax
	# Component register %eax is used for the return value
    1157:       83 c0 02                add    $0x2,%eax
	# End for a + 2
    115a:       5d                      pop    %rbp
    115b:       c3                      ret    
```

![[image-3.png|Execution stack of adder2]]

> The `%rip` (instruction pointer) goes from the instruction from the top to the bottom.

![[image-4.png]]


`0x526`: The 1st instruction `push %rbp` places a *copy* of the value in `%rbp` i.e., `0xd40` on top of the stack. For that the stack grows by 8 bytes/the stack pointer decrements by 8 (`0x28`), resulting new value of `%rsp` is `0xd20`

![[image-5.png]]

`0x527`: The instruction updates the value of `%rbp` with the value in `%rsp` to `0xd20`

![[image-6.png]]

`0x52a`: We store the 1st parameter to any function is stored in `%rdi` (See more in [[Registers in x86-64 architecture]]). The `-0x4(%rbp)` translates to `M[%rbp-0x4]` and this evaluates to `M[0xd1c]`. The `mov` instruction thus copies the value `0x28` to the location `0xd1c` on the stack

![[image-7.png]]

Similarly, the `0x52d` instruction copies the value inside `0xd1c` and stores it in the register `%eax`

![[image-10.png]]

Instruction `0x530` adds the value `$0x2` to the value inside `%eax` (`0x28`) and stores the result `0x2A` inside `%eax`

![[image-9.png]]


The `pop` instruction removes the value off the top of the stack `M[0xd20]` and places it inside `%rbp`, resulting in the value of `%rbp` as `0xd40`
The stack pointer also grows toward lower addresses by incrementing by 8 resulting in the value `0xd28`


The `retq` prepares the calls tack for returning from a function. The return value in this case is stored in the component register `%eax`, which is holding the value `0x2A` which evaluates to 42

> Surprisingly, the values in registers `%rsp` and `%rbp` are `0xd28` and `0xd40` respectively, which are **the same values as when the function started executing**. This is a normal behavior, since the purpose of the call stack is to store temporary variable and data, and it should return to the state it was before the function is invoked.

We commonly see these instructions at the start and the end of a function call to update and restore the state of the call stack

```assembly
push %rbp
mov %rsp, %rbp

pop %rbp
retq
```