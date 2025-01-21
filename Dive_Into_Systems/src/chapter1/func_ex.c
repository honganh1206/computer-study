#include <stdio.h>

// Function prototype
int max(int x, int y);

int max(int x, int y) {
  int bigger;
  if (x < y) {
    bigger = y;
    y = x;
  }
  printf("before return x: %d, y: %d\n", x, y);

  return bigger;
}

void print_table(int start, int stop);

void print_table(int start, int stop) {
  int i;
  for (i = start; i <= stop; i++) {
    printf("%d\t", i * i);
  }

  printf("\n");
}

int main() {
  int a, b, res;
  printf("Enter two integer values: ");
  scanf("%d%d", &a, &b);
  res = max(a, b);
  printf("The larger value of %d and %d is %d\n", a, b, res);

  print_table(a, res);
  return 0;
}
