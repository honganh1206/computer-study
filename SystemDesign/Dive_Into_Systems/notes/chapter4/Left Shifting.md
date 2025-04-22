---
id: Left Shifting
aliases:
  - Left Shifting
tags: []
---

# Left Shifting

Shifting to the left **increases** the value, since bits move toward digits that contribute larger powers of two to the value of the number

```bash
0000 0101 # 5
0000 0101 << 1 → 0000 1010 # 10
```

With a fixed number of bits, shifting can truncate some bits and decrease the value

```bash
1111 0101 # 245
1111 0101 << 1 -> 1110 1010 # 234
```
