---
tags:
  - "#study"
  - "#review"
  - "#programming"
  - "#algorithm"
cssclasses:
  - center-images
---
The DEVAX computer, instead of using Boolean operations, had instructions `bis` (bit set) and `bic` (bit clear). Both instructions take a data word `x` and a mask word `m` and the result `z` containing the bits of **`x` modified according to bits of `m`**. 

The `bis` will *set `z` to 1 at each bit position where `x` or `y` is 1*. We can see that the `bis` operation is quite similar to the OR operation `x | y` - A bit will be set in `z` if *either this bit is set in `x` or `y`*.

Meanwhile, the `bic` will *set `z` to 0 at each bit position where `x` or `y` is 0*. To do so, we must first *set all the bit of either `x` or `y` to zero with `~x` or `~y`* then use the AND operation to clear the bits `x & ~y`