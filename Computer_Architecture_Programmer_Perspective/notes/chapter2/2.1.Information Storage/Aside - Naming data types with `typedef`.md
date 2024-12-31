---
tags:
  - "#study"
  - "#review"
  - "#programming"
  - "#clang"
cssclasses:
  - center-images
---
We use `typedef` in C to give a name to a data type. This helps improve code readability as *deeply nested type declarations can be difficult to decipher*. 

We declare a type in the same way we declare a variable, only *replace the variable name with the type name*


```c
typedef int *int_pointer;
int_pointer ip;

// Direct declaration
int *ip

```
