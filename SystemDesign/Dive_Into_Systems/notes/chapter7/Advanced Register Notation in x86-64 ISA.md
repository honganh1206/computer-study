[Ref](https://diveintosystems.org/book/C7-x86_64/basics.html#_advanced_register_notation)

Since x86-64 is an *extension* of the 32-bit x86 architecture,  each register has *sub-portions* that can be accessed directly, enabling *manipulation of smaller data sizes*

Thus the ISA provides mechanisms to *access the lower 32 bits and 16 bits and lower bytes of each register* 

[[Understanding x86-64 register notation]]

## First 8 registers

| 64-bit Register | 32-bit Register | Lower 16 Bits | Lower 8 Bits |
| --------------- | --------------- | ------------- | ------------ |
| `%rax`          | `%eax`          | `%ax`         | `%al`        |
| `%rbx`          | `%ebx`          | `%bx`         | `%bl`        |
| `%rcx`          | `%ecx`          | `%cx`         | `%cl`        |
| `%rdx`          | `%edx`          | `%dx`         | `%dl`        |
| `%rdi`          | `%edi`          | `%di`         | `%dil`       |
| `%rsi`          | `%esi`          | `%si`         | `%sil`       |
| `%rsp`          | `%esp`          | `%sp`         | `%spl`       |
| `%rbp`          | `%ebp`          | `%bp`         | `%bpl`       |

Access the lower 32-bit registers by replacing the `r` in the register name with `e`

Access the 16-bit registers by referencing *the last two letters* of the register name

![[image.png]]

## Last 8 registers `%r8` to `%r15`

| 64-bit Register | 32-bit Register | Lower 16 Bits | Lower 8 Bits |
| --------------- | --------------- | ------------- | ------------ |
| `%r8`           | `%r8d`          | `%r8w`        | `%r8b`       |
| `%r9`           | `%r9d`          | `%r9w`        | `%r9b`       |
| `%r10`          | `%r10d`         | `%r10w`       | `%r10b`      |
| `%r11`          | `%r11d`         | `%r11w`       | `%r11b`      |
| `%r12`          | `%r12d`         | `%r12w`       | `%r12b`      |
| `%r13`          | `%r13d`         | `%r13w`       | `%r13b`      |
| `%r14`          | `%r14d`         | `%r14w`       | `%r14b`      |
| `%r15`          | `%r15d`         | `%r15w`       | `%r15b`      |

Originally not part of the IA32 ISA

To access the lower 32 bits, 16 bits, or byte, append the letter `d`, `w` or `b` respectively


