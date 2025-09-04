Switch the order of inner and outer loops in nested loops to *maximize cache locality*

The GCC has `-floop-interchange` flag but it is not available by default.

> Programmers should pay close attention to *how their code is accessing memory-composite data structures* like arrays and matrices

```c
void matrixVectorMultiply(int ** mat, int * vec, int ** res, int row, int col){
    int i, j;
    // Cycle through every matrix column
    // in inner-most loop (inefficient)
    for (j = 0; j < col; j++){
        for (i = 0; i < row; i++){
            res[i][j] = mat[i][j] * vec[j];
        }
    }
}

void matrixVectorMultiply_v2(int ** mat, int * vec, int ** res, int row, int col){
    int i, j;
    // Cycle through every row
    // in inner-most loop 
    for (i = 0; i < row; i++){
        for (j = 0; j < col; j++){
            res[i][j] = mat[i][j] * vec[j];
        }
    }
}
```

The first version is inefficient as it does not take advantage of the [[Row-major order]]: Since modern CPUs fetch memory in chunks (cache lines), when we access `matrix[0][0]` the CPU automatically loads `matrix[0][0]` and `matrix[0][3]` into fast cache memory (Refer to [[Cache behavior and terminology]])

**Row-wise access (efficient):**

- Access `[0][0]` → CPU loads `[1,2,3,4]` into cache
- Access `[0][1]` → Already in cache! ✓
- Access `[0][2]` → Already in cache! ✓
- Access `[0][3]` → Already in cache! ✓

**Column-wise access (inefficient):**

- Access `[0][0]` → CPU loads `[1,2,3,4]` into cache
- Access `[1][0]` → Cache miss! CPU loads `[5,6,7,8]` ✗
- Access `[2][0]` → Cache miss! CPU loads `[9,10,11,12]` ✗
- Access `[3][0]` → Cache miss! CPU loads `[13,14,15,16]` ✗