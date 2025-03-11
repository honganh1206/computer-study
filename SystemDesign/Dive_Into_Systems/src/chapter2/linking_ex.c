#include "examplelib.h" // Search in same dir with source code
#include "mylib.h"
#include <stdio.h> // Search in system dir

int main(int argc, char *argv[]) {
  int result;
  float result2;
  result = libraryfunc(6, MAX);
  result2 = bigger(1.0, 2.0);
  printf("result is %d\n", result);
  printf("result2 is %f\n", result2);
  return 0;
}
