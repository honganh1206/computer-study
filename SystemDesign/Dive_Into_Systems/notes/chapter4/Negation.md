To negate an $N$-bit value, determine its complement with respect to $2^N$ so that $X + Y =2^N$

Quick and dirty way: *Flip all the bits and add 1*

```js
100000000 (256)
- 00001101 (13)

// Think of 256 as 255 + 1
011111111 (255) + 00000001 (1)
- 00001101 (13)
```


See more [[2.3.3 Two-Complement Negation]]