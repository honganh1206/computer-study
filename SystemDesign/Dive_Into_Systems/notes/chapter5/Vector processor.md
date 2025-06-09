An architecture that implement ILP through *special vector instructions*

Vector instructions take one-dimensional arrays (vectors) of data as their operands. A CPU with vectors instructions can do multiple operations in *one step*

```c
// All ADD operations are executed in one step
[2, 5, 7] + [1, 3, 4] = [3, 8, 11]
```

Vector instructions are executed *in parallel* by a vector processor on *multiple execution units*. Each unit performs an arithmetic operation on single elements of its vector operands

GPUs are optimized for performing computation on image data stored in 1D arrays



