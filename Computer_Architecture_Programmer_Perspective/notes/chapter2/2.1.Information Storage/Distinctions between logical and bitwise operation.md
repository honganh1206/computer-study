---
tags:
  - "#study"
  - "#review"
  - "#computer"
  - "#programming"
cssclasses:
  - center-images
---
The logical operators like `||, &&` do **not** evaluate their second argument if *the result of the expression is also the result of evaluating the first argument*.

For example, the `a && 5/a` will be false, so the division by zero if `a = 0` will not happen. Similarly, the `p || *p++` will never cause the dereferencing of a null pointer as `p` is true.


