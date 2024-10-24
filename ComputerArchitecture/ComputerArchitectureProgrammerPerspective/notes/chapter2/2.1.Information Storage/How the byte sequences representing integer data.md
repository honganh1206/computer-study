---
tags:
  - "#study"
  - "#review"
  - "#computer"
  - "#programming"
cssclasses:
  - center-images
---
Given this line:

```
4004d3: 01 05 43 0b 20 00 add %eax,0x200b43(%rip)
```

We can see the byte sequence `01 05 43 0b 20 00` is a **byte-level representation** of an **instruction**. This instruction is to *add a word of data* to a value stored at a specific address. This address is computed by *adding `0x200b43` to the current value of the program counter aka the next instruction to be executed.*

The last 4 bytes (`43 0b 20 00`) could be *written in reverse* then we *remove the leading zero*, we have `0x200b43` which is **the value written on the right side** (little endian).

Naturally, we write byte sequences with the *lowest-numbered byte on the left and highest on the right*. This is in contrast with how we write numbers (most significant digit on the left and least to the right like 12345 - thousands to units)