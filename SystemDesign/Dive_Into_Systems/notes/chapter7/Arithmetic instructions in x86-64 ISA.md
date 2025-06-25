| Instruction | Translation                                       | Note                                                                                      |
| ----------- | ------------------------------------------------- | ----------------------------------------------------------------------------------------- |
| `add S, D`  | S + D → D                                         |                                                                                           |
| `sub S, D`  | D - S → D                                         |                                                                                           |
| `inc D`     | D + 1 → D                                         |                                                                                           |
| `dec D`     | D - 1 → D                                         |                                                                                           |
| `neg D`     | -D → D                                            |                                                                                           |
| `imul S, D` | S × D → D                                         | If the product requires more than 64 bits to represent, the value is truncated to 64 bits |
| `idiv S`    | `%rax` / S: quotient → `%rax`, remainder → `%rdx` | Calling `idid` on operand S divides the contents of `%rax` by S                           |