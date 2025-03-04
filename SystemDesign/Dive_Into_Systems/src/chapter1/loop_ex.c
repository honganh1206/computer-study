#include <stdio.h>
int main() {
  // This works just fine but add complexity
  int i, j;

  for (i = 0, j = 0; i < 10; i += 1, j += 10) {
    printf("i + j = %d\n", i + j);
  }

  return 0;
}
