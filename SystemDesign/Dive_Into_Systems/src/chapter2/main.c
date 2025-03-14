#include <stdio.h>

int myfunc(int param);

int main() {
  int ret;
  ret = myfunc(32);
  printf("myfunc(32) %d\n", ret);
  return 0;
}
