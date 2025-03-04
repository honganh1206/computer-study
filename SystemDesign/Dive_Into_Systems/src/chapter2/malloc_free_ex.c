#include <stdio.h>
#include <stdlib.h>
int main() {
  int *p;
  p = malloc(sizeof(int)); // Allocate heap memory for an int

  if (p == NULL) {
    printf("Bad malloc error\n");
    exit(1);
  }

  *p = 6; // The heap memory p points to the value 6
  printf("%d\n", *p);
  free(p);
  p = NULL;
  return 0;
}
