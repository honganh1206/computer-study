Multiple-input versions of gates can be built by **chaining together** multiple two-input `AND`/`OR` gates

An example is a three-input `AND` gate built from two two-input `AND` gates. The 1st `AND` gate takes two inputs and the 2nd `AND` gate takes one input and the output of the 1st `AND` gate as an input

```
(X AND Y) AND Z == X AND Y AND Z
```