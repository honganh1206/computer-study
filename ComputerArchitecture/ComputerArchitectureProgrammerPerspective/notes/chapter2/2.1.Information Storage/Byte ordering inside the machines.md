---
tags:
  - "#study"
  - "#review"
  - "#programming"
  - "#computer"
cssclasses:
  - center-images
---
Usually the byte orderings used by the machines are **invisible**. But sometimes, byte ordering becomes an issue:

1. [[Binary data is communicated over a network between machines of different types]]
2. [[How the byte sequences representing integer data]]
3. [[Programs circumventing the normal type system]]

Here we have the output of C code that *use casting* and *print the byte representations* of different value types namely `int, float, *pointer`:

![[{806A50E3-4330-482E-A84B-6B3E04762293}.png]]

Linux 32, Windows and Linux are little-endian machines while Sun machines are big-endian. The pointer values, on the other hand, are completely different as *different machines use different conventions for storage allocation*.

Notice that although the floating-point and the integer data both encode the value `12345` , they have **different byte patterns**, as these two formats **use different encoding schemes**.

![[{925E335D-3554-457E-B3B7-61AC56A886D7}.png|Here we can see a sequence of 13 matching bits]]


[[Aside - Naming data types with `typedef`]]

[[Aside - Formatted printing with `printf`]]

[[Aside - Pointers and arrays in C]]

