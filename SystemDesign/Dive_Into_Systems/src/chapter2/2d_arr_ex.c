#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define COLS (100)
#define N 3
#define M 4

void init_matrix(int m[][COLS], int rows) {
  int i, j;
  for (i = 0; i < rows; i++) {
    for (j = 0; j < COLS; j++) {
      m[i][j] = i * j;
      printf("%d\n", m[i][j]);
    }
  }
}

void init2d(int *two_d_arr) {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      two_d_arr[i * M + j] = 0;
    }
  }
}

/*rows: the bounds on the outermost array (the array of row arrays)*/
/*cols: the bounds on the inner arrays (the array column values for each row)*/
void init2d_method2(int **two_d_arr, int rows, int cols) {
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      two_d_arr[i][j] = 0;
    }
  }
}

int main() {
  // Statically allocated arrays
  /*int matrix[50][COLS];*/
  /*int bigger[90][COLS];*/
  /**/
  /*init_matrix(matrix, 50);*/
  /*init_matrix(bigger, 90);*/

  // Dynamically allocated arrays
  int *two_d_arr;

  // Method 1
  two_d_arr = malloc(sizeof(int) * N * M);
  if (two_d_arr == NULL) {
    printf("ERROR: malloc failed!\n");
    exit(1);
  }

  init2d(two_d_arr);

  free(two_d_arr);
  two_d_arr = NULL;

  // Method 2
  int **two_d_array; // A pointer to int *
  int i;
  // Allocate an array of N poiinters to ints
  // malloc returns the address of this array as a pointer to (int *)'s'
  two_d_array = malloc(sizeof(int *) * N);

  // For each row, we malloc space for its column elements
  // Then add it to the array of arrays
  for (i = 0; i < N; i++) {
    two_d_array[i] = malloc(sizeof(int) * M);
  }

  init2d_method2(two_d_array, N, M);

  for (i = 0; i < N; i++) {
    free(two_d_array[i]); // Free each row's allocated array
    two_d_array[i] = NULL;
  }

  free(two_d_array);
  two_d_array = NULL;

  return 0;
}
