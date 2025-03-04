#include <math.h>
#include <stdio.h>

int main() {
  printf("Hello World\n");
  printf("sqrt(4) is %f\n",
         sqrt(4)); // Need to explicitly specify a newline character
  printf("number of bytes in an int: %lu\n", sizeof(int));
  printf("number of bytes in a short: %lu\n", sizeof(short));
  printf("automatic type conversion for 1 + 2.00 = %f\n", 1 + 2.00);

  // Pre - increment
  int x_pre = 6;
  int y_pre = ++x_pre + 2;

  // Post-increment
  int x_post = 6;
  int y_post = x_post++ + 2;

  printf("Pre: %d | Post: %d\n", y_pre, y_post);
  char ch;

  ch = 'A';
  // Print a char value as its decimal representation
  printf("ch value is %d which is ASCII value of %c\n", ch, ch);

  return 0;
}
