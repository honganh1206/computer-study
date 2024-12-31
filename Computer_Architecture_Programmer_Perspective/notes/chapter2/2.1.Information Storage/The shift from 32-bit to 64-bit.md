---
tags:
  - "#study"
  - "#review"
  - "#computer"
cssclasses:
  - center-images
---
The shift first occurred to high-end machines designed for large-scale applications, followed by desktops and lastly smartphones.

A 32-bit word size limits virtual address spaces to 4 GB, while scaling up to 64-bit allows 16 *exabytes* ($1.84 * 10^{19}$)


> [!info] Running programs on 32-bit and 64-bit machines
> Most 64-bit machines can run programs compiled on a 32-bit machine as a form of **backward compatibility**.

```shell
linux> gcc -m32 prog.c # This can be run on both 32-bit and 64-bit machines
linux> gcc -m64 prog.c # This can be run ONLY on 64-bit machines
```
