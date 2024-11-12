---
tags:
  - "#study"
  - "#review"
  - "#computer"
cssclasses:
  - center-images
---
Computers and compilers support *different ways to encode data of different lengths*. Many machines also have instructions for manipulating **single bytes** and **integers represented as 2-, 4- and 8-byte quantities** and **floating-point numbers represented as 4- or 8-byte quantities**

The C language *supports multiple data formats* as below

![[{5473B111-1E38-48AD-BD5C-54F80C1E01B0}.png]]



> [!tip] Using `char` to store integer values
> While `char` is mostly used to store a single character in a text string, it can also be used to store integer values.

ISO C99 introduces a class of data types where **the data sizes are fixed** regardless of compilers or machine settings e.g., `int32_t` and `int64_t`

[[Data type `char` as an exception]]

[[Ordering keywords in C]]