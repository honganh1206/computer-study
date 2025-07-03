| Instruction   | Translation                                   | Note                |
| ------------- | --------------------------------------------- | ------------------- |
| `cmp R1, R2`  | Compares R2 with R1 (i.e., evaluates R2 - R1) |                     |
| `test R1, R2` | Computes R1 & R2                              | Perform bitwise AND |
`test %rax, %rax` performs bitwise AND and the result is 0 only when `%rax` contains zero. This is equivalent to `cmp $0, %rax`

Both instructions modify *a series of single-bit values* known as **[[Condition code]] flags**. Example is `cmp` will modify the code flags based on the value of `R2 - R1` whether it is positive (great) / negative (less) / zero (equal)

| Flag | Translation                                  | Condition                                                             |
| ---- | -------------------------------------------- | --------------------------------------------------------------------- |
| `ZF` | Is equal to zero (1: yes; 0: no)             | R1 and R2 are equal                                                   |
| `SF` | Is negative (1: yes; 0: no)                  | R2 is less than R1                                                    |
| `OF` | Overflow has occurred (1:yes; 0: no)         | R2 - R1 results in integer overflow (useful for signed comparison)    |
| `CF` | Arithmetic carry has occurred (1: yes; 0:no) | R2 - R1 results in a carry operation (useful for unsigned comparison) |
