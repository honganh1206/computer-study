Each instruction has an **operation code** (or opcode) to specify *what it does*, **operands** to tell the instruction how to do it.

For example: The instruction `add $0x2, %eax`, has the opcode `add`  and the operands `$0x2` and `%eax`

Different *types of operands*:

- **Constants/Literal values** are preceded by the `$` sign. Example is `$0x2` corresponding the hexadecimal value `0x2`
- **Register** forms (`%`) refer to different registers
- **Memory** forms (`()`) correspond to values inside main memory (RAM) and are commonly used for *address lookup*

## Examples with operands in x86-64 ISA

Suppose that memory and registers hold these values:
   
| Address | Value |
| ------- | ----- |
| 0x804   | 0xCA  |
| 0x808   | 0xFD  |
| 0x80c   | 0x12  |
| 0x810   | 0x1E  |

| Register | Value |
| -------- | ----- |
| %rax     | 0x804 |
| %rbx     | 0x10  |
| %rcx     | 0x4   |
| %rdx     | 0x1   |

The following table shows the operands evaluating to the values shown above

> The notation `M[x]` (used by operand of type Memory) denotes the *value* at the memory location specified by address `x`

| Operand         | Form     | Translation                    | Value | Note                                       |
| --------------- | -------- | ------------------------------ | ----- | ------------------------------------------ |
| %rcx            | Register | %rcx                           | 0x4   | Indicate the value stored in register %rcx |
| (%rax)          | Memory   | M[%rax] or M[0x804]            | 0xCA  | `%rax` is treated as an address here       |
| $0x808          | Constant | 0x808                          | 0x808 |                                            |
| 0x808           | Memory   | M[0x808]                       | 0xFD  |                                            |
| 0x8(%rax)       | Memory   | M[%rax + 8] or M[0x80c]        | 0x12  |                                            |
| (%rax, %rcx)    | Memory   | M[%rax + %rcx] or M[0x808]     | 0xFD  |                                            |
| 0x4(%rax, %rcx) | Memory   | M[%rax + %rcx + 4] or M[0x80c] | 0x12  |                                            |
| 0x800(,%rdx,4)  | Memory   | M[0x800 + %rdx*4] or M[0x804]  | 0xCA  | Scaling operation #1                       |
| (%rax, %rdx, 8) | Memory   | M[%rax + %rdx*8] or M[0x80c]   | 0x12  | Scaling operation #2                       |

> Not all forms can be used interchangeably.

Constant forms like `5` and `0x10` can only be read, not written to. Since it is part of the instruction encoding itself

```
mov $5, %rax    ; OK — move constant 5 to register RAX
mov $5, $6      ; INVALID — both are constants, and constants can't be destinations
```

A memory address cannot be used as both a source and the destination. We need to involve at least one register

```
mov (%rax), %rbx      ; OK — read from memory to register
mov %rbx, (%rax)      ; OK — write from register to memory
mov (%rax), (%rbx)    ; INVALID — both operands are memory addresses
```