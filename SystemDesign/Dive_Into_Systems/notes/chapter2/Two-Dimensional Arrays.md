---
id: Two-Dimensional Arrays
aliases:
  - Two-Dimensional Arrays
tags: []
---

# Two-Dimensional Arrays

Structure: `array[row][column]`

```c
int val;
short num;

val = matrix[3][7]; // get int value in row 3, column 7 of matrix
num = little[8][4]; // get short value in row 8, column 4 of little
```

We use nested loops to access values in the arrays

```c
int i, j;

for (i = 0; i < 50 i++) { // Iterate each row
  for (j = 0; j < 100; j++) { // Iterate each column
    matrix[i][j] = 0;
  }
}
```

The base address of a 2D array is also `&arr[0][0]` - the address of the very first element

> [!IMPORTANT]
> For multidimensional array parameters, you must indicate that the parameter is a multidimensional array, but *you can leave the size of the 1st dimension unspecified* 

[[Row-major order]]

[[Dynamically allocated 2D arrays]]
