#include <stdio.h>
void test_arr_update(int a[], int size) {
  if (size > 3) {
    a[3] = 8;
  }
  size = 2; // Changing parameter does NOT change argument

  printf("Address stored in parameter 'a': %p\n", (void *)a);
}

int main() {
  int arr[5], n = 5, i;
  for (i = 0; i < n; i++) {
    arr[i] = i;
  }

  printf("%d %d\n", arr[3], n); // 3 5

  // Value get passed is the base address here
  // Parameter a refers to the same array storage locations as its argument, arr
  test_arr_update(arr, n);

  // The array's 4th element will be modified however
  printf("%d %d\n", arr[3], n); // 8 5

  printf("Address of array 'arr': %p\n", (void *)arr);
}
