#include <stddef.h>
#include <stdio.h>

int change(int *input, int amt) {
  int val;
  val = *input;  // Receive the value that input points to
  *input += amt; // Update the value of input pointer

  return val;
}

int main() {
  // int *ptr1, *ptr2, x, y;

  // x = 8;
  // ptr2 = &x;
  // ptr1 = NULL;

  // *ptr2 = 10;    // The memory location of ptr2 is assigned the value 10
  // y = *ptr2 + 3; // Get the value from the memory location ptr2 is pointing
  // to

  // ptr1 = ptr2; // Both pointers point to x

  // *ptr1 = 100; // Update the value of x to 100

  // ptr1 = &y;  // Change ptr1 value
  // *ptr1 = 80; // Update the value of y to 80

  // printf("x: %d. y: %d\n", x, y);

  // Doing this will likely cause segfault (a memory fault)
  // ptr1 = NULL;

  // *ptr1 = 6;

  int x, result;

  x = 10;

  result = change(&x, 20);

  printf("result = %d. x = %d\n", result, x); // result = 10. x = 30

  return 0;
}
