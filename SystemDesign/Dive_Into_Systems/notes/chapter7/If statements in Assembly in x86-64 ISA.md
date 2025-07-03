Sample C code

```c
int getSmallest(int x, int y) {
    int smallest;
    if ( x > y ) {
        smallest = y;
    }
    else {
        smallest = x;
    }
    return smallest;
}
```

Compiled to Assembly:

```asm
 # Functions that are normally part of function creation are removed
# for readability
(gdb) disas getSmallest
Dump of assembler code for function getSmallest:
   0x40059a <+4>:   mov    %edi,-0x14(%rbp) # 1st parameter x
   0x40059d <+7>:   mov    %esi,-0x18(%rbp) # 2nd parameter y
   0x4005a0 <+10>:  mov    -0x14(%rbp),%eax # Copy x to %eax
   0x4005a3 <+13>:  cmp    -0x18(%rbp),%eax # Compare x and y
   0x4005a6 <+16>:  jle    0x4005b0 <getSmallest+26> 
   # Jump to 5b0 if x <= y
   0x4005a8 <+18>:  mov    -0x18(%rbp),%eax # Copy y to %eax
   0x4005ae <+24>:  jmp    0x4005b9 <getSmallest+35>
   # Jump to 5b9
   0x4005b0 <+26>:  mov    -0x14(%rbp),%eax # Copy x to %eax
   0x4005b9 <+35>:  pop    %rbp
   # Clean up the stack
   0x4005ba <+36>:  retq 
   # Return from the function call
```

When compiling C code to `goto` form, the results will be quite different

```c
// C if statement
if (condition) {
    then_statement;
}
else {
    else_statement;
}

// goto form by the compiler
    if (!condition) {
        goto else;
    }
    then_statement;
    goto done;
else:
    else_statement;
done:
```

[[The cmov instructions]]

