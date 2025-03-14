---
id: Compiling C to Assembly and compiling and linking Assembly and code
aliases:
  - Compiling C to Assembly and compiling and linking Assembly and code
tags: []
---

# Compiling C to Assembly and compiling and linking Assembly and code

A compiler compiles C code into Assembly, and it also compiles Assembly into a binary form that links into a binary executable program

We use IA32 assembly and `gcc`

```bash
gcc -m32 -S simpleops.c # Run the assembler to create a .s text file
gcc -m32 -c simpleops.s # Compile to a relocatable object binary file .o
gcc -m32 -o simpleops simpleops.o # Create a 32-bit executable

```

## Writing and compiling assembly code

Write a `.s` file and a `.c` file with a prototype as the function implemented in the `.s` file

[[Handwritten Assembly Code]]
