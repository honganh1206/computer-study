A fast way to *compute the address of a location in memory*

 How is `lea` different from `mov`? While `mov` is required to treat the contents in the source operand as a memory location if it is in a memory form, `lea` performs the same operand arithmetic **without the memory lookup**. The compiler can cleverly use `lea` as a substitution for some types of arithmetic

```asm
# Access the memory address rax +4 to get the value
# Memory lookup happen
mov rbx, [rax + 4]

# Compute rax + 4 and store the result in rbx
# Just address arithmetic, no access to memory
lea rbx, [rax + 4]
```

`lea` simply performs arithmetic regardless of the type of data contained in the operand

Example with register `%rax` containing the constant `0x5`, `%rdx` containing `0x4` and `%rcx` containing `0x808` as an address

| Instruction                     | Translation                      | Value          |
| ------------------------------- | -------------------------------- | -------------- |
| `lea 8(%rax), %rax`             | 8 + `%rax` → `%rax`              | 13 → `%rax`    |
| `lea (%rax, %rdx), %rax`        | `%rax` + `%rdx` → `%rax`         | 9 → `%rax`     |
| `lea (,%rax,4), %rax`           | `%rax` × 4 → `%rax`              | 20 → `%rax`    |
| `lea -0x8(%rcx), %rax`          | `%rcx` - 8 → `%rax`              | 0x800 → `%rax` |
| `lea -0x4(%rcx, %rdx, 2), %rax` | `%rcx` + `%rdx` × 2 - 4 → `%rax` | 0x80c → `%rax` |
