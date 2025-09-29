---
tags:
  - "#study"
  - "#review"
  - "#programming"
  - "#computer"
cssclasses:
  - center-images
sr-due: 2025-09-26
sr-interval: 1
sr-ease: 230
---
There are two forms of the right shift `x >> k`:

**Logical**: Filling the left end with $k$ zeros $[0,\dots,0,x_{w-1}, x_{w-2}, \dots, k_{k}]$

**Arithmetic**: Filling the left end with $k$ **repetitions** of the **most significant bit** $[x_{w-1}, \dots,x_{w-1},x_{w-2},\dots,x_{k}]$

| Operation           | Value 1         | Value 2         |
| ------------------- | --------------- | --------------- |
| Argument x          | 01100011 (0x63) | 10010101 (0xA5) |
| x << 4              | 00110000 (0x30) | 01010000 (0x50) |
| x >> 4 (logical)    | 00000110 (0x06) | 00001001 (0x0A) |
| x >> 4 (arithmetic) | 00000100 (0x06) | 11111001 (0xFA) |

Note that the C language does not precisely define which type of right shift should be used with *signed* numbers, meaning *any code assuming either form of right shift will eventually encounter portability problems*. Most of the time, signed data uses arithmetic right shift while unsigned data uses logical right shift.