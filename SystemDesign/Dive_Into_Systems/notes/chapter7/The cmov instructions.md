While `cmp, jmp, test` implement a *conditional transfer of control* in a program, `cmov` implements a *conditional transfer of data*: Both `then_statement` and `else_statement` of the conditional are executed, and the data is placed in the appropriate register *based on the result of the condition*

Where? The use of C's ternary expression often results in the compiler generating a `cmov` instruction

```c
int getSmallest_cmov(int x, int y) {
    return x > y ? y : x;
}
```

```asm
0x4005d7 <+0>:   push   %rbp             #save %rbp
0x4005d8 <+1>:   mov    %rsp,%rbp        #update %rbp
0x4005db <+4>:   mov    %edi,-0x4(%rbp)  #copy x to %rbp-0x4
0x4005de <+7>:   mov    %esi,-0x8(%rbp)  #copy y to %rbp-0x8
0x4005e1 <+10>:  mov    -0x8(%rbp),%eax  #copy y to %eax
0x4005e4 <+13>:  cmp    %eax,-0x4(%rbp)  #compare x and y
0x4005e7 <+16>:  cmovle -0x4(%rbp),%eax  #if (x <=y) copy x to %eax
0x4005eb <+20>:  pop    %rbp             #restore %rbp
0x4005ec <+21>:  retq                    #return %eax
```

No jumps. `x` moves to the return register if `x <= y`

| Signed              | Unsigned            | Description                        |
| ------------------- | ------------------- | ---------------------------------- |
| `cmove` (`cmovz`)   |                     | move if equal (==)                 |
| `cmovne` (`cmovnz`) |                     | move if not equal (!=)             |
| `cmovs`             |                     | move if negative                   |
| `cmovns`            |                     | move if non-negative               |
| `cmovg` (`cmovnle`) | `cmova` (`cmovnbe`) | move if greater (>)                |
| `cmovge` (`cmovnl`) | `cmovae` (`cmovnb`) | move if greater than or equal (>=) |
| `cmovl` (`cmovnge`) | `cmovb` (`cmovnae`) | move if less (<)                   |
| `cmovle` (`cmovng`) | `cmovbe` (`cmovna`) | move if less than or equal (<=)    |
The compiler is *very cautious* about optimizing jump instructions into `cmov` instructions, especially when *side effects and pointer values are involved*

```c
// Two versions of increment function

int incrementX(int *x) {
	if (x != NULL) {
		return (*x)++;
	} else {
		return 1;
	}
}

int incrementX2(int **x) {
	return x ? (*x)++ : 1;
}
```

Assembly versions are similar

```asm
incrementX:
.LFB6:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	cmpq	$0, -8(%rbp)
	je	.L2
	movq	-8(%rbp), %rax
	movl	(%rax), %eax
	leal	1(%rax), %ecx
	movq	-8(%rbp), %rdx
	movl	%ecx, (%rdx)
	jmp	.L3

incrementX2:
.LFB7:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	cmpq	$0, -8(%rbp)
	je	.L5
	movq	-8(%rbp), %rax
	movq	(%rax), %rax
	leaq	4(%rax), %rcx
	movq	-8(%rbp), %rdx
	movq	%rcx, (%rdx)
	jmp	.L7

```