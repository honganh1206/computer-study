---
tags:
  - "#study"
  - "#review"
cssclasses:
  - center-images
---
## PP 2.1

A. 0010|0101|1101|1001|1011|0010
B. 0xC97B
C. 1010|1000|1011|0011|1101
D. 0x322D96


## PP 2.2

| $n$ | $2^n$ in decimal | $2^n$ in hexadecimal |
| --- | ---------------- | -------------------- |
| 23  | 8,388,608        | 0x800000             |
| 15  | 32768            | 0x8000               |
| 13  | 8192             | 0x2000               |
| 6   | 64               | 0x40                 |
| 8   | 256              | 0x100                |
## PP 2.3

| Decimal | Binary    | Hexadecimal |
| ------- | --------- | ----------- |
| 0       | 0000 0000 | 0x00        |
| 158     | 1001 1110 | 0x9E        |
| 76      | 0100 1011 | 0x4C        |
| 145     | 1001 0001 | 0x91        |
| 174     | 1010 1110 | 0xAE        |
| 60      | 0011 1100 | 0x3C        |
| 241     | 1111 0001 | 0xF1        |

## PP 2.4

1. 0x605c + 0x5 = 0x6061
2. 0x605c - 0x20 = 0x603C
3. 0x605c + 32 = 0x607C
4. 0x60fa - 0x605c = 0x9e

## PP 2.5

```c
// little 
show_bytes(ap, 1); // 78 - 12
show_bytes(ap, 2); // 78 56
show_bytes(ap, 3); // 76 56 34
```


## PP 2.6

| Hexa       | Decimal   | Binary                                  |
| ---------- | --------- | --------------------------------------- |
| 0x0027c8f8 | 2607352   | 0000 0000 0010 0111 1100 1000 1111 1000 |
| 0x4a1f23e0 | 3510593.0 | 0100 1010 0001 1111 0010 0111 1110 0000 |

## PP 2.7


```
 6d
 6e
 6f
 70
 71
 72
Total byte length: 6
```

## PP 2.8

|         | Bit Vector   | Integer Arithmetic          |
| ------- | ------------ | --------------------------- |
| `a`     | `[01001110]` | $A=\{1,2,3,6\}$             |
| `b`     | `[00011110]` | $B=\{0,5,6,7\}$             |
| `~a`    | `[10110001]` | $\lnot A = \{0,4,5,7\}$     |
| `~b`    | `[00011110]` | $\lnot A = \{1,2,3,4\}$     |
| `a & b` | `[01000000]` | $A\cap B=\{6\}$             |
| a \| b  | `[11101111]` | $A\cap B=\{0,1,2,3,5,6,7\}$ |
| a ^ b   | `[10101111]` | $A\cap B=\{0,1,2,3,5,7\}$   |

## PP 2.9

Blue | Green = 011 => Cyan

Yellow & Cyan = 010 => Green

Red ^ Magenta = 001 => Blue

## PP 2.10

| Step   | `*x` | `*y`  |
| ------ | ---- | ----- |
| Base   | a    | b     |
| Step 1 | a    | a ^ b |
| Step 2 | b    | a ^ b |
| Step 3 | b    | a     |

## PP 2.11

A. `first` would be 2k and `last` would be 0 in the final iteration.
B. In the 3rd iteration as we have `first <= last`, the `first` and `last` variables will both be equal to 2, and we have `*x = *y = 3` but at that point `3^3=0` (exclusive or - if both are true then it is false) so we have the values of `*x` and `*y` reset to 0.
C. Change `<=` to `<`


## PP 2.12

A. Usual masking `x & 0xFF`
B. `x ^ ~0xFF`. The result of `~0xFF = 0xFFFFFF00` which flips all the bits from 0 to 1 and vice versa. In that way, the XOR operation will return the bits necessary to complement the most significant 6 bits of `x`, resulting in `0x789ABC21`
C. `x | 0xFF`. If the least significant byte is going to be `FF` then the `0xFF` must return true. Therefore we need the OR operation to flip the least significant byte of `x = 0x87654321` to `FF`


## PP 2.13


```c
// Bit set
int bis(int x, int m) {
  return x | m;
};

// Bit clear
int bic(int x, int m) {
  return x & ~m;
};

// x | y
int bool_or(int x, int y) {
 int result = bis(x, y);
 return result;
}

// x ^ y
int bool_xor(int x, int y) {
  int result = bis(bic(x, y), bic(y, x));
  return result;
}

```


## PP 2.14

| Expression | Value           |
| ---------- | --------------- |
| a          | 0x55 (01010101) |
| b          | 0x46 (01000100) |
| a & b      | 0x88            |
| a && b     | 0x01            |
| a \| b     | 0x57            |
| a \|\| b   | 0x01            |
| ~a \| ~b   | 0xBB            |
| !a \|\| !b | 0x00            |
| a & !b     | 0x00            |
| a && ~b    | 0x01            |

## PP 2.15


```c
// Longer way to check equal instead of x == y
int equal(int x, int y) {
  // If EVERY bit of x matches with every bit of y (x equal y) then x ^ y = false
  return !(x ^ y);
}
```


## PP 2.16

| x    | x << 2 | x >> 3 (Logical) | x >> 3 (Arithmetic) |
| ---- | ------ | ---------------- | ------------------- |
| 0xD4 | 0x50   | 0x1A             | 0xFA                |
| 0x64 | 0x90   | 0x0C             | 0x0C                |
| 0x72 | 0xC8   | 0x0E             | 0x0E                |
| 0x44 | 0x10   | 0x08             | 0x08                |

## PP 2.17


| Hexadecimal | Binary | $B 2 U_{4}(\vec{x})$ | $B 2 T_{4}(\vec{x})$ |
| ----------- | ------ | -------------------- | -------------------- |
| 0xA         | 1010   | 10                   | -6                   |
| 0x1         | 0001   | 1                    | 1                    |
| 0xB         | 1011   | 11                   | -5                   |
| 0x2         | 0010   | 2                    | 2                    |
| 0x7         | 0111   | 7                    | 7                    |
| 0xC         | 1100   | 12                   | -4                   |

## PP 2.18


| Hex   | Decimal |
| ----- | ------- |
| 0x2e0 | 736     |
| -0x58 | -88     |
| 0x28  | 40      |
| -0x30 | -48     |
| 0x78  | 120     |
| 0x88  | 136     |
| 0x178 | 504     |
| 0x8   | 8       |
| 0xc0  | 152     |
| -0x48 | -72     |

## PP 2.19 & 2.20

| $x$ | $T 2 U_{4}(x)$ |
| --- | -------------- |
| -1  | 15             |
| -5  | 11             |
| -6  | 10             |
| -4  | 12             |
| 1   | 15             |
| 8   | 8              |
Four first entries apply to $x < 0$ case where $T 2 U_{w}(x) = x + 2^w$, and the other two apply for $x \geq 0$ where $T 2 U_{w}(x) = x$


## PP 2.21


| Expression                   | Type     | Evaluation |
| ---------------------------- | -------- | ---------- |
| -2147483647-1 == 2147483648U | Unsigned | 1          |
| -2147483647-1 < 2147483647   | Signed   | 0          |
| -2147483647-1U < 2147483647  | Unsigned | 0          |
| -2147483647-1 < -2147483647  | Signed   | 0          |
| -2147483647-1U < -2147483647 | Unsigned | 1          |

## PP 2.22

A. $-1 \times 2^{3}+ 1 \times 2^{2} + 0 + 0 = -4$
B. $-1 \times 2^{4} + 1 \times 2^{3} + 1 \times 2^{2} + 0 + 0 = -4$
C. $-1 \times 2^{5} + 1 \times 2^{4} + 1 \times 2^{3} + 1 \times 2^{2} + 0 + 0 = -4$


## PP 2.23

A.

| w          | `fun1(w)` | `fun2(w)` |
| ---------- | --------- | --------- |
| 0x00000076 | 118       | 118       |
| 0x87654321 | 33        | 33        |
| 0x000000C9 | 201       | -55       |
| 0xEDCBA987 | 135       | -121      |

B. TLDR: `fun1()` allows casting AFTER both the left shift and right shift operations have been executed, while `fun2()` allows casting after the left shift is executed only. 

`fun1()` shifts the left bits by 24 bits to the left, then 24 bits to the right and the casting will happen at the end. It then converts the unsigned value but at this point, the if the MSB is 0 then the number will NOT be treated as a negative number. The right shift will also be performed logically.

`fun(2)` will convert the value to signed BEFORE the left shifting happens, meaning if the MSB is 1 then the value will be treated as negative. If so, the arithmetic shift will be performed when doing the right shift (filling the vacated bits on the left with 1) 


## PP 2.24

4 bits to 3 bits

| Unsigned |     | Signed |     |
| -------- | --- | ------ | --- |
| 1        | 1   | 1      | 1   |
| 3        | 3   | 3      | 3   |
| 5        | 5   | 5      | 5   |
| 12       | 4   | -4     | 4   |
| 14       | 6   | -2     | 6   |

## PP 2.25

Using `<=` will lead to the off-by-one error: When `length = 0` the loop condition `i <= length` will cause an out-of-bounds array access.

We fix this by changing the condition to `i < length`

## PP 2.26

A. Cases that introduce incorrect result
1. Length of s < length of t
2. Length of s = 0
3. t string has an empty space
 B. As the data type of `size_t` is `unsigned`, the abstraction yields a positive result all the times. 
C. We cast the return value from `strlen()` to `int` to use signed values.


## PP 2.28

| $x$ |         | $-^{u}_{4}x$ |         |
| --- | ------- | ------------ | ------- |
| Hex | Decimal | Hex          | Decimal |
| 1   | 1       | F            | 15      |
| 4   | 4       | C            | 12      |
| 7   | 7       | 9            | 9       |
| A   | 10      | 6            | 6       |
| E   | 14      | 2            | 2       |
|     |         |              |         |

## PP 2.29

Refer to the 5-bit hexadecimal value table in [[What hexadecimal numbers are]]

Note that $x, y$ here are *negative* if the higher order bit is 1

| $x$       | $y$       | $x+y$      | $x +^t_{5} \\ y$ | Case |
| --------- | --------- | ---------- | ---------------- | ---- |
| -8        | -8        | -16        | -16              | 1    |
| `[11000]` | `[11000]` | `[110000]` | `[10000]`        |      |
| -9        | 8         | -1         | -1               | 2    |
| `[10111]` | `[01000]` | `[111111]` | `[11111]`        |      |
| 2         | 5         | 7          | 7                | 3    |
| `[00010]` | `[00101]` | `[000111]` | `[00111]`        |      |
| 12        | 4         | 16         | -16              | 4    |
| `[01100]` | `[00100]` | `[010000]` | `[10000]`        |      |

## PP 2.33

The bit patterns are the same as for unsigned negation in PP 2.28

Note that in two's-complement interpretation, the MSB is a negative number so while B in unsigned is 11, it is -5 in two's-complement.

| $x$ |         | $-^t_4 x$ |     |
| --- | ------- | --------- | --- |
| Hex | Decimal | Decimal   | Hex |
| 2   | 2       | -2        | E   |
| 3   | 3       | -3        | D   |
| 9   | 9       | -9        | 7   |
| B   | -5      | 5         | 5   |
| C   | -4      | 4         | 4   |

## PP 2.34
 
| Mode             | $x$ |         | $y$ |         | $x \times y$ |            | Truncated $x \times y$ |         |
| ---------------- | --- | ------- | --- | ------- | ------------ | ---------- | ---------------------- | ------- |
| Unsigned         | 4   | `[100]` | 5   | `[101]` | 20           | `[010100]` | 4                      | `[100]` |
| Two's-complement | -4  | `[100]` | -5  | `[101]` | 20           | `[110100]` | -4                     | `[100]` |
| Unsigned         | 2   | `[010]` | 7   | `[111]` | 14           | `[001110]` | 6                      | `[110]` |
| Two's-complement | 2   | `[010]` | -1  | `[111]` | -2           | `[111110]` | -2                     | `[110]` |
| Unsigned         | 6   | `[110]` | 6   | `[110]` | 36           | `[100100]` | 4                      | `[100]` |
| Two's-complement | -2  | `[110]` | -2  | `[110]` | 4            | `[000100]` | -4                     | `[100]` |

## PP 2.35 

We know that when we do multiplication for two n-bit integers, our machines *truncate* the result to `n` bits from `2n` bits 

Let us have $P_{true} = x \times y$ and $p = x \times_{m} y$ where $\times_{m}$ represents *machine multiplication*

Due to truncation, we can write: $P_{true} = p + t\times 2^{w}$ with $t$ as some integer and $2^{w}$ as the maximum value + 1 for $w$ bits

If there is no overflow, then $t=0$ and $P_{true} = p$ and if there is an overflow, $t\neq 0$ and $p$ represents the **lower $w$ bits of $P_{true}$**