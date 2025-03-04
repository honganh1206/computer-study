#include <stdio.h>
#include <stdlib.h>

// We only pass the base address here
// But we can still access the large block of contiguous memory on the heap
// As the function can access by dereferencing the pointer parameter
void init_array(int *arr, int size) {
  int i;
  for (i = 0; i < size; i++) {
    arr[i] = i; // Dereferencing happen here. This is equivalent to *(arr + i)
  }
}

int main() {
  /*int i;*/
  /*int s_array[20]; // Statically declared array*/
  /*int *d_array;    // Dynamically allocated array*/
  /**/
  /*d_array = malloc(sizeof(int) * 20);*/
  /**/
  /*if (d_array == NULL) {*/
  /*  printf("Error: malloc failed\n");*/
  /*  exit(1);*/
  /*}*/
  /**/
  /*for (i = 0; i < 20; i++) {*/
  /*  s_array[i] = i;*/
  /*  d_array[i] = i;*/
  /*}*/
  /**/
  /*printf("%d %d \n", s_array[3], d_array[3]);*/
  /**/
  /*free(d_array);*/
  /*d_array = NULL;*/
  /**/

  int *arr1;

  arr1 = malloc(sizeof(int) * 10);

  if (arr1 == NULL) {
    printf("malloc error\n");
    exit(1);
  }

  init_array(arr1, 10);

  for (int i = 0; i < 10; i++) {
    printf("%d\n", arr1[i]);
  }

  free(arr1);
  arr1 = NULL;
  return 0;
}
