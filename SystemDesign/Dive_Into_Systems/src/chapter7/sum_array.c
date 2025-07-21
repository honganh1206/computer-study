#include <stdio.h>

int sumArray(int *arr, int length) {
    int i, total = 0;
    for (i = 0; i < length; i++) {
        total += arr[i];
    }
    return total;
}

int main(void) {
   int arr[5] = {1,2,3,4,5}; 
   int total;
   total = sumArray(arr, 5);
   printf("Sum of array: %d\n", total);
   return 0;
}
