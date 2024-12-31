---
tags:
  - "#study"
  - "#review"
cssclasses:
  - center-images
---
In C, the expression `1 << 2 + 3 << 4` means `1 << (2 + 3) << 4` and not `(1 << 2) + (3 << 4)` since *addition/subtraction have higher precedence than shifts*. Furthermore, the left-to-right associativity causes this to be `(1 << (2 + 3)) << 4`, giving value of 512 instead of 52.


> [!tip] 
> When in doubts, put in parentheses!



