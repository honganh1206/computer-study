#include <stdio.h>

int find_and_return_max(int *arr, int len, int *max) {
  int i;
  if (!arr || len <= 0) {
    return -1;
  }
  *max = arr[0];
  for (i = 1; i < len; i++) {
    if (*max < arr[i]) {
      *max = arr[i];
    }
  }

  return *max;
}

int main(int argc, char *argv[]) {
  int arr[5] = {17, 21, 44, 2, 60};
  int max = arr[0];

  if (find_and_return_max(arr, 5, &max) != 0) {
    printf("max value in the array is %d\n", max);
  }
  return 0;
}
