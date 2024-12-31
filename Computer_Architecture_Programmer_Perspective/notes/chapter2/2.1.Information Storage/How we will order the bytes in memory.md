---
tags:
  - "#study"
  - "#review"
  - "#programming"
  - "#computer"
cssclasses:
  - center-images
---
We have two common conventions:

1. **Little endian** - Least significant byte comes first: A $w$-bit integer will have a representation of $[x_{w-1}, x_{w_{-2},}\dots, x_{1}, x_{0}]$ with $x_{w-1}$ as the *most significant bit* and $x_{0}$ as *the least*
2. **Big endian** - Most significant byte comes first: Assuming $w$ is a multiple of 8, the most significant byte will have bits of $[x_{w-1}, x_{w-2},\dots, x_{w-8}]$ and the least significant byte will have bits of $[x_{7}, x_{6, \dots, x_{0}}]$

Some machines choose to follow the #1 convention, while others prefer #2 convention.

## Example

Suppose we have a variable `int x` at address `0x100` and it has a hexadecimal value of `0x1234567`. This will be the ordering of the bytes:

![[{AFB476C0-34A0-45C3-BD91-EFF74880C675}.png|The bytes are scattered from `0x100` to `0x103` depending on the types of the machines]]


[[How big corps order the bytes]]


[[Aside - Origin of the word endian]]


> [!important] Choosing what convention?
> Either convention is fine, as long as after one of them is selected, the chosen convention is adhered to consistently.


[[Byte ordering inside the machines]]