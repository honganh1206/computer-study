---
id: What is a bit
aliases: []
tags: []
---

Ultimate output from storage device is **a sequence of electrical signals**

Each signal is **binary**, taking either state of no voltage (zero) and presence of voltage (one)

Each signal corresponds to one **bit**

The number of unique values doubles for each additional bit in a bit sequence. A sequence of $N$ bits can represent $2^N$ unique values

```js
# Bits        Values                             # Values
  1           [ 0 ] [ 1 ]                         2^1 → 2

  2           [ 00 ] [ 01 ] [ 10 ] [ 11 ]         2^2 → 4

  3           [ 000 ] [ 001 ] [ 010 ] [ 011 ]
              [ 100 ] [ 101 ] [ 110 ] [ 111 ]     2^3 → 8

  4           [ 0000 ] [ 0001 ] [ 0010 ] [ 0011 ]
              [ 0100 ] [ 0101 ] [ 0110 ] [ 0111 ]
              [ 1000 ] [ 1001 ] [ 1010 ] [ 1011 ]
              [ 1100 ] [ 1101 ] [ 1110 ] [ 1111 ] 2^4 → 16

  N           [ ... ]                             2^N
```

The interpretation of a sequence if bit is interesting, since **bits have no inherent meaning**: We can interpret a bit's two values as up and down/black and white/yes and n, etc.

Which interpretation is correct depends on the context