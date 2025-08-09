#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 3
// The first version is 5 times faster!
// Since it accesses the matrix's values sequentially in memory
float averageMat_v1(int **mat, int n) {
    int i, j, total = 0;

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            total += mat[i][j];
        }
    }

    return (float)total / (n * n);
}


float averageMat_v2(int **mat, int n) {
    int i, j, total = 0;

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            total += mat[j][i];
        }
    }

    return (float)total / (n * n);
}

void initArr(int **mat, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            mat[i][j] = i + j;
        }
    }
}


int main(void) {
    int **mat;
    int i;
    float avg;
    mat = malloc(sizeof(int *) * N);
    for (i = 0; i < N; i++) {
        mat[i] = malloc(sizeof(int) * N);
    }

    initArr(mat, N, N);
    avg = averageMat_v1(mat, N);
    printf("Average is: %f\n", avg);
    free(mat);
    mat = NULL;

    return 0;

}
