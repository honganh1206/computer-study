---
tags:
  - "#study"
  - "#review"
  - "#algorithm"
  - "#programming"
cssclasses:
  - center-images
---
A **mask** is a *binary number* used to manipulate specific bits of another binary number. The mask determines *which bits to keep* and *which bits to ignore* when using bitwise operations like AND, OR and NOT.

For example, the mask `0xFF` (11111111 - covering all bits in a single byte) indicates the **low-order/rightmost bytes** of a word. When you use `0xFF` with the bitwise operation AND `&`, it can help you **extract the least significant/leftmost bytes from a larger number while setting all other bits to 0**

An example would be `x & 0xFF` which is equal to `0x12345678 & 0xFF`. In binary format things look like this:


```
00010010001101000101011001111000 
AND 
00000000000000000000000011111111 
----------------------------------- 
= 00000000000000000000000001111000 (0x78)

```

You can see the result `0x78` extracted from the value `x`