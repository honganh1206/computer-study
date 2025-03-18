#include <stdio.h>
#include <stdlib.h>

int init_func(int *arr, int len) {
  int i;
  for (i = 1; i <= len; i++) {
    arr[i] = i;
  }

  return 0;
}

int main(int argc, char *argv[]) {
  int *arr = malloc(sizeof(int) * 6);
  int max = 6;
  if (init_func(arr, max) != 0) {
    printf("init error\n");
    exit(1);
  }

  free(arr);
  arr = NULL;

  return 0;
}
