#include <stdio.h>
#include <stdlib.h>

void print_array(int *p, int size, char *name) {
  // Check for null pointer
  if (p == NULL || name == NULL) {
    printf("Error: Null pointer passed to print_array\n");
    return;
  }

  // Check for invalid size
  if (size <= 0) {
    printf("Error: Invalid array size\n");
    return;
  }

  printf("%s = [", name);

  for (int i = 0; i < size; i++) {
    printf("%d", p[i]);
    if (i < size - 1) {
      printf(", ");
    }
  }

  printf("]\n");
}

int main(int argc, char *argv[]) {
  int *bigfish, *littlefish, i;

  bigfish = (int *)malloc(sizeof(int) * 10);
  littlefish = (int *)malloc(sizeof(int) * 10);

  if (!bigfish || !littlefish) {
    printf("Error: malloc failed\n");
    exit(1);
  }

  for (i = 0; i < 10; i++) {
    bigfish[i] = 10 + i;
    littlefish[i] = i;
  }

  print_array(bigfish, 10, "bigfish");
  print_array(littlefish, 10, "littlefish");

  // Heap memory access error: Write beyond bounds
  for (i = 0; i < 13; i++) {
    // This overwrites memory between the heap mem location of the last elem of
    // bigfish And the 1st elem of littlefish
    bigfish[i] = 66 + i;
  }

  printf("\nafterloop:\n");
  print_array(bigfish, 10, "bigfish");
  print_array(littlefish, 10, "littlefish");

  free(bigfish);
  free(littlefish);
  return 0;
}
