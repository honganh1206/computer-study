Programs tend to access data that is nearby (data's memory address) other e.g., if a program access data at address `N` and `N + 4` it's likely to access `N + 8`

Accesses to the array's contents also benefit from spatial locality: A modern system loads *more than one `int` at a time from memory to the CPU cache* i.e., accessing the first array index fills the cache with both the first integer and also the next few integers. 

However, the number of additional integers moved into the cache depends on the *cache's block size*. For example, a 16-byte block size can be used to copy four integers from memory to the cache at a time, so when we access the first integer in the cache, the other three are served out of cache and thus reducing cost.

Consider the following example:

```c
float averageMat_v1(int **mat, int n) {
    int i, j, total = 0;

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            total += mat[i][j];
        }
    }

    return (float)total / (n * n);
}


int averageMat_v2(int **mat, int n) {
    int i, j, total = 0;

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            total += mat[j][i];
        }
    }

    return (float)total / (n * n);
}
```

In [[Two-Dimensional Arrays]], the *row-major order organization of a matrix in memory*  means the first version *accesses the matrix's values sequentially in memory*. 

On the other hand, the second version *jumps between rows across nonsequential memory addresses*, and that means it *never* reads from the same cache block in subsequent memory accesses. Thus, the 1st version is 5 times faster than the second one.
