
| Instruction | Translation                                             |
| ----------- | ------------------------------------------------------- |
| `mov S, D`  | S → D (copies value of S into D)                        |
| `add S, D`  | S + D → D (adds S to D and stores result in D)          |
| `sub S, D`  | D - S → D (subtracts S _from_ D and stores result in D) |

```assembly
# Copy the value M[%rbp-0x4] at location %rbp-0x4 to register %eax
mov -0x4(%rbp),%eax
# Add the value 0x2 to register %eax, and store the result in %eax
add $0x2,$eax
```

[[Stack management instructions]]

[[How the execution stack works]]
