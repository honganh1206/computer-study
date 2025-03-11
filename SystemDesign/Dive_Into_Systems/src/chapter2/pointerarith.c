#include <stdio.h>
#include <stdlib.h>
#define N 10
#define M 20

int main() {
  char letters[N];
  int numbers[M];
  int matrix[N][M];

  char *cptr = NULL;
  int *iptr = NULL;

  // Both point to the 1st element
  cptr = &(letters[0]);
  /*iptr = numbers;*/
  /**/
  /*// Init letters and number arrays*/
  /*for (int i = 0; i < N; i++) {*/
  /*  *cptr = 'a' + 1;*/
  /*  *iptr = i * 3;*/
  /**/
  /*  // Use pointer arithmetic to set each pointer to point to the NEXT
   * element*/
  /*  cptr++; // Point to the next char address*/
  /*  iptr++; // Point to the next int address*/
  /*}*/
  /**/
  /*printf("\n array values using indexing to access: \n");*/
  /*for (int i = 0; i < N; i++) {*/
  /*  printf("letters[%d] = %c, numbers[%d] = %d\n", i, letters[i], i,*/
  /*         numbers[i]);*/
  /*}*/
  /**/
  /*// Use pointer arithmetic to print values*/
  /*cptr = letters; // Point to the first elem of the array*/
  /*iptr = numbers;*/
  /*printf("\n array values using pointer arithmetic to access: \n");*/
  /*for (int i = 0; i < N; i++) {*/
  /*  printf("letters[%d] = %c, numbers[%d] = %d\n", i, *cptr, i, *iptr);*/
  /*  cptr++;*/
  /*  iptr++;*/
  /*}*/

  iptr = &(matrix[0][0]);
  // Fill the entire matrix with numbers from 0 to (N*M -1)
  for (int i = 0; i < N * M; i++) {
    *iptr = i;
    iptr++;
  }

  printf("\n 2D array values init using pointer arithmetic: \n");
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      printf("%3d ", matrix[i][j]);
    }
    // A new line after each row
    printf("\n");
  }

  return 0;
}
