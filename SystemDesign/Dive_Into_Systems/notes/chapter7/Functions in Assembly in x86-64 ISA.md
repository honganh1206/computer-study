Recall certain concepts: 

[[Stack pointer and frame pointer]]

[[Stack management instructions]]

[[Address space]]

Content:

[[Stack frame and frame record]]

[[Function Parameters]]

## Tracing through a function call

```c
#include <stdio.h>

int assign(void) {
    int y = 40;
    return y;
}

int adder(void) {
    int a;
    return a + 2;
}

int main(void) {
    int x;
    assign();
    x = adder();
    printf("x is %d\n", x);
    return 0;
}

```

Assembly version (from my own computer):

```asm

0000000000001149 <assign>:
    1149:	f3 0f 1e fa          	endbr64 
    114d:	55                   	push   %rbp
    114e:	48 89 e5             	mov    %rsp,%rbp
    1151:	c7 45 fc 28 00 00 00 	movl   $0x28,-0x4(%rbp)
    1158:	8b 45 fc             	mov    -0x4(%rbp),%eax
    115b:	5d                   	pop    %rbp
    115c:	c3                   	ret    

000000000000115d <adder>:
    115d:	f3 0f 1e fa          	endbr64 
    1161:	55                   	push   %rbp
    1162:	48 89 e5             	mov    %rsp,%rbp
    1165:	8b 45 fc             	mov    -0x4(%rbp),%eax
    1168:	83 c0 02             	add    $0x2,%eax
    116b:	5d                   	pop    %rbp
    116c:	c3                   	ret    

000000000000116d <main>:
    116d:	f3 0f 1e fa          	endbr64 
    1171:	55                   	push   %rbp
    1172:	48 89 e5             	mov    %rsp,%rbp
    1175:	48 83 ec 10          	sub    $0x10,%rsp
    1179:	e8 cb ff ff ff       	call   1149 <assign>
    117e:	e8 da ff ff ff       	call   115d <adder>
    1183:	89 45 fc             	mov    %eax,-0x4(%rbp)
    1186:	8b 45 fc             	mov    -0x4(%rbp),%eax
    1189:	89 c6                	mov    %eax,%esi
    118b:	48 8d 05 72 0e 00 00 	lea    0xe72(%rip),%rax        # 2004 <_IO_stdin_used+0x4>
    1192:	48 89 c7             	mov    %rax,%rdi
    1195:	b8 00 00 00 00       	mov    $0x0,%eax
    119a:	e8 b1 fe ff ff       	call   1050 <printf@plt>
    119f:	b8 00 00 00 00       	mov    $0x0,%eax
    11a4:	c9                   	leave  
    11a5:	c3                   	ret    
```


![[image-12.png]]


Call stack grows toward lower addresses (`%rsp` storing the stack address `0xd48` and `%rbp` storing the stack address `0x830` - *both are made up*). And since we use integer data, we use component registers `%eax` and `%edi`

![[image-13.png]]

We first push `0x830` onto the stack. And since the stack grows toward lower addresses, the stack pointer `%rsp` has its value updated to `0xd40` (8 bytes less)

![[image-14.png]]

`sub` instruction subtracts `0x10` from the address of our stack pointer `%rip` (allocating 16 bytes of stack space)

![[image-15.png]]

`callq <assign>` pushes the value inside `%rip` (`0x55f`) onto the top of the stack as the *return address* of the function `assign`. From this point we switch the active frame to the callee i.e., `assign`

> -- Call to `assign` starts here --

![[image-16.png]]

Push the value stored by `%rbp` onto the stack of the callee i.e., `0xd40` - beginning of the stack frame for `main` (to restore the caller's frame when we are done executing `assign`)

![[image-17.png]]

Update the value of `%rbp` with the one of `%rsp` i.e., `0xd20`, *marking the beginning of the stack frame for `assign`*

![[image-18.png]]

Push the value 40 to the stack at address `-0x4(%rbp)` 

![[image-19.png]]

Put the value 40 into register `%eax` representing the variable `y`

![[image-20.png]]

The `pop` instruction restores `%rbp` to its previous value and modify the `%rsp` to `0xd28`

![[image-21.png]]

When `retq` executes, the return address (resume execution on `main`) is popped off the stack and sent to `%rip`

> -- Call to `assign` ends here

![[image-22.png]]

We now return to the state *before we invoke `assign`* with the stack pointer and the frame pointer restored to their values prior to their invocation -> Stack frame for `main` is again the active one

The values on the previous active frame of `assign` is still on the stack (`0x554`)

> -- Call to `adder` starts here -- 

![[image-23.png]]

The call to `adder` *overwrites* the old return address (`0x55f`) with the new return address (`0x554`), which point to *the next instruction to be executed after `adder` is done executing*. 

[ Skipping some instructions... ]

The last two instructions `0x53d` and `0x540` are equivalent to `int a; return a + 2;`

> -- Call to `adder` ends here -- 

![[image-24.png]]


[ Skipping instructions to 0x55c... ]

The code segment with memory `0x400604` is the base address of the string `"x is %d\n"`

![[image-25.png]]

Reset the value of `%eax` to 0

![[image-26.png]]

The `printf` function has the following signature: `int printf(const char * format, ...)` with the first argument being *a pointer to a string*. This string is the format we saved in the address `0x400604`

![[image-27.png]]

The `leaveq` instruction allows the CPU to overwrite the stack pointer with the frame pointer. The stack and frame pointers then return to their original values before `main` executes.