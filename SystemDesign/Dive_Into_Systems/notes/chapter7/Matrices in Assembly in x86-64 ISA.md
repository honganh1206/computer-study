## Recall

A matrix in C can be statically allocated as a two-dimensional array `M[n][m]` or dynamically allocated with `malloc`, or (again) dynamically allocated as *an array of arrays* ([[Two-Dimensional Arrays]])

```c
//statically allocated matrix (allocated on stack) 
int M1[4][3]; 

//dynamically allocated matrix (programmer friendly, allocated on heap) 
int **M2, i; M2 = malloc(4 * sizeof(int*)); 
for (i = 0; i < 4; i++) { M2[i] = malloc(3 * sizeof(int)); }

//dynamic matrix (allocated on heap, memory efficient way) 
#define ROWS 4 
#define COLS 3 
int *M3; M3 = malloc(ROWS * COLS * sizeof(int));
```

![[image-29.png|Statically allocated M1 and dynamically allocated M2 3x4 matrix]]

We can access elements in `M1` and `M2` using double-indexing syntax `M[i][j]`.

> While both types of arrays store their elements contiguously in memory in their primary array, `M1` stores all the rows contiguously in memory, while the rows in `M2` are not contiguous (each of them has a different address, the primary array just stores the addresses)

For `M3`, we must index the element using the format `M3[i*COLS + j]`

[[Contiguous 2D arrays]]

[[Noncontiguous matrices]]

