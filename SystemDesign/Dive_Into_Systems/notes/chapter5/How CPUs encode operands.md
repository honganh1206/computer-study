Different CPU architectures may have different approaches towards encoding operands in machine instructions

Some might encode the operands **directly in the instructions**: 

 ```
[Opcode][Operand1: Immediate 6][Operand2: Immediate 8]

# Binary example
0001 0110 1000
^    ^    ^
|    |    |
|    |    8 (Operand 2)
|    6 (Operand 1)
ADD opcode

```

Other CPUs might require *loading values into registers first* then we can reference those registers

```
MOV R1, 6
MOV R2, 8

ADD R1, R2

# Instruction format
[Opcode][Reg1: 001][Reg2: 010]
```

Operands could also reside in RAM so we fetch them via their addresses\

```
ADD [0x1000], [0x1004]

# Instruction format
[Opcode][MemAddr1][MemAddr2]
```

