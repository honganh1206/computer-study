---
tags:
  - "#study"
  - "#review"
  - "#programming"
  - "#computer"
cssclasses:
  - center-images
---
For some programs, data types **must be encoded using representations with specific sizes**. For example, in programs used for computers communicating over the internet according to a standard protocol, data types used must be compatible with those specified by the protocol. 

As we know, the C standards *only specifies the minimum ranges* and not the exact ranges, and the file `stdint.h` introduces both 32 and 64-bit versions of fixed-size integer types. This file defines a set of data types in the form of `intN_t` (signed) and `uintN_t` (unsigned) for different values of `N`. While `N` is implementation-dependent, most compilers allow values of 8/16/32/64. 

We also have *a set of macros* defining the maximum and minimum values for each value of `N` namely `INTN_MIN, INTN_MAX, UINT_MAX`