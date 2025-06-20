

```assembly
 1149:       f3 0f 1e fa             endbr64 
```

Each line contains 3 parts:
- An instruction's 64-bit address in the memory
- The bytes corresponding to the instruction
- The plain-text representation of the instruction

For example, `55` is the *machine-code representation* of the instruction `push %rbp`, and this instruction is at the address `0x114d` (shortened for readability) in program memory

> A single line of C code can often translates to *multiple instructions* in Assembly.

[[Registers in x86-64 architecture]]

In the Assembly example above, the compiler references component register `%eax` instead of `%rax` since `int` types typically take up 32 bits (four bytes) of space on 64-bit machines. If we use `long`type the compiler would use `%rax` instead (More in [[Understanding x86-64 register notation]])

[[Advanced Register Notation in x86-64 ISA]]

[[Instruction Structure in x86-64 ISA]]

[[Instruction Suffixes]]
