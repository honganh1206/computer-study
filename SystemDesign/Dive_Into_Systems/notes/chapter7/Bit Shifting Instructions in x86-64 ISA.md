Bit shifting offers the compiler a shortcut for multiplicands and divisors that are *the power of 2*

Example: To compute `77 * 4` most compilers will translate this operation to `77 << 2` to avoid using `imul` instruction

|Instruction|Translation|Arithmetic or Logical?|
|---|---|---|
|`sal v, D`|D `<<` v → D|arithmetic|
|`shl v, D`|D `<<` v → D|logical|
|`sar v, D`|D `>>` v → D|arithmetic|
|`shr v, D`|D `>>` v → D|logical|

Each shift instruction takes two operands: One is usually a register and the other is a shift value (which could be a constant or store in register `%cl`)