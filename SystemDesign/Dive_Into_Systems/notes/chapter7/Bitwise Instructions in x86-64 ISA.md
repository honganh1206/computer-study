One way the compiler uses bitwise operations is for certain *optimizations*. An example is the compiler uses `77 & 3` to implement `77 mod 4` instead of the expensive `idiv` instruction

| Instruction | Translation  |
| ----------- | ------------ |
| `and S, D`  | S `&` D → D  |
| `or S, D`   | S `\|` D → D |
| `xor S, D`  | S `^` D → D  |
| `not D`     | `~`D → D     |

> Use bitwise operations wisely only when needed. Most compilers nowadays are smart enough to replace simple arithmetic operations with bitwise operations, so we should prioritize code readability whenever possible.

