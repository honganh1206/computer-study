#include "examplelib.h"

int libraryfunc(int x, int y) {
  int result = x * y;
  if (result > MAX) {
      return MAX;
  }

  return result;
}
