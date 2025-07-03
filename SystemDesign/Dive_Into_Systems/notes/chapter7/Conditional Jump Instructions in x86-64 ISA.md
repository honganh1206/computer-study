The behavior of conditional jump instructions will depend on the condition code registers set by [[Conditional Comparison Instructions in x86-64 ISA]]

| Signed Comparison | Unsigned Comparison                        | Description                        |
| ----------------- | ------------------------------------------ | ---------------------------------- |
| `je` (`jz`)       |                                            | jump if equal (==) or jump if zero |
| `jne` (`jnz`)     |                                            | jump if not equal (!=)             |
| `js`              |                                            | jump if negative                   |
| `jns`             |                                            | jump if non-negative               |
| `jg` (`jnle`)     | `ja` (`jnbe` - Jump if not below or equal) | jump if greater (>)                |
| `jge` (`jnl`)     | `jae` (`jnb` - Jump if not below)          | jump if greater than or equal (>=) |
| `jl` (`jnge`)     | `jb` (`jnae` - Jump if not above or equal) | jump if less (<)                   |
| `jle` (`jng`)     | `jbe` (`jna` - Jump if not above)          | jump if less than or equal (<=)    |
To remember them easier:

| Letter | Word                            |
| ------ | ------------------------------- |
| `j`    | jump                            |
| `n`    | not                             |
| `e`    | equal                           |
| `s`    | signed                          |
| `g`    | greater (signed interpretation) |
| `l`    | less (signed interpretation)    |
| `a`    | above (unsigned interpretation) |
| `b`    | below (unsigned interpretation) |

> Terms like greater and less instruct the CPU to interpret the numerical comparison as a signed value, whereas terms like above and below indicate that the numerical comparison is unsigned