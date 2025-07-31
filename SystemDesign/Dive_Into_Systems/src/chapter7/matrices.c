#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 3
#define M 4

int sumConMax(int *m, int rows, int cols)
{
    int i, j, total = 0;
    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
        {
            total += m[i * cols + j];
        }
    }
    return total;
}

// 1st param is the address of an array of integer pointers
int sumNonconMax(int **m, int rows, int cols)
{
    int i, j, total = 0;

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            total += m[i][j];
        }
    }
    return total;
}

void initConMatrix(int *m)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            m[i * M + j] = i + j;
        }
    }
}

void initNonConMatrix(int **m)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            m[i][j] = i + j;
        }
    }
}

int main(void)
{
    // Contiguous matrix
    int *con_m;
    con_m = malloc(sizeof(int) * N * M);
    if (con_m == NULL)
    {
        printf("ERROR: malloc failed!\n");
        exit(1);
    }

    initConMatrix(con_m);

    int total = 0;
    total = sumConMax(con_m, N, M);
    printf("Total for con matrix: %d\n", total);

    free(con_m);
    con_m = NULL;

    // Non-contiguous matrix
    int **non_con_m;
    int i;

    non_con_m = malloc(sizeof(int *) * N);
    for (i = 0; i < N; i++)
    {
        non_con_m[i] = malloc(sizeof(int) * M);
    }

    initNonConMatrix(non_con_m);

    total = sumNonconMax(non_con_m, N, M);
    printf("Total for non-con matrix: %d\n", total);

    for (i = 0; i < N; i++)
    {
        free(non_con_m[i]);
        non_con_m[i] = NULL;
    }

    free(non_con_m);
    non_con_m = NULL;

    return 0;
}
