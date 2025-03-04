---
tags:
  - "#study"
  - "#review"
  - "#programming"
  - "#computer"
cssclasses:
  - center-images
---
The C standard set the *lower bounds* on the numeric ranges of different data types e.g., `signed int` on a 32-bit system has a lower bound of $2^{-31} = -2147483648$. However, **there are no upper bounds** i.e., implementations of C can provide **larger ranges** as long as they meet the minimum requirements set by the standards (`long int` can store a larger value than $2^{31} - 1$ on 64-bit systems)

Yet there are **fixed-size types** like `int32_t` with their sizes *fixed across all platforms*.