#include <stdio.h>
#include <string.h>

typedef unsigned char *byte_pointer; // Pointer to an object of type unsigned char

// Print the byte representations of C program objects
// We use size_t as the preferred data type to represent size of data structures
void show_bytes(byte_pointer start, size_t len) {
  int i;
  for (i = 0; i < len; i++) {
    printf(" %.2x", start[i]); // Here we reference array elements with pointer notation
    printf("\n");
  }

  printf("Total byte length: %zu\n", len);
}


void show_int(int x) {
  // This pointer, as a sequence of bytes, is the lowest byte address occupied by the object
  // sizeof return the NUMBER OF BYTES in the object
  show_bytes((byte_pointer) &x, sizeof(int));
}

void show_float(float x) {
  show_bytes((byte_pointer) &x, sizeof(float));
}

void show_pointer(void *x) {
  show_bytes((byte_pointer) &x, sizeof(void *));
}

// Swap the values stored at the locations denoted by pointers
// We do not need a temp variable to store one value when moving the other here
// There is no performance gain here, it is only for amusement :)
void inplace_swap(int *x, int *y) {
  *y = *x ^ *y; // Step 1
  *x = *x ^ *y; // Step 2
  *y = *x ^ *y; // Step 3

}

// This only works for even-length arrays
// For odd-length arrays, the middle element will be set as 0
void reverse_array(int a[], int cnt) {
  int first, last;
  for (first = 0, last = cnt-1; first < last; first++, last--) {
    inplace_swap(&a[first], &a[last]);
  }

  for (int i = 0; i < cnt; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

void test_show_bytes(int val) {
  int ival = val;
  float fval = (float) ival;
  int *pval = &val;
  printf("Calling show_int...\n");
  show_int(ival);
  printf("Calling show_float...\n");
  show_float(fval);
  printf("Calling show_pointer...\n");
  show_pointer(pval);
}

// Bit set
int bis(int x, int m) {
  return x | m;
};

// Bit clear
int bic(int x, int m) {
  return x & ~m;
};

int bool_or(int x, int y) {
 int result = bis(x, y);
 return result;
}

int bool_xor(int x, int y) {
  int result = bis(bic(x, y), bic(y, x));
  return result;
}

// Longer way to check equal instead of x == y
int equal(int x, int y) {
  // If EVERY bit of x matches with every bit of y (x equal y) then x ^ y = false
  return !(x ^ y);
}

int main(int argc, char *argv[])
{
    // test_show_bytes(12345);
    // int a = 0x12345678;
    // byte_pointer ap = (byte_pointer) &a;
    // show_bytes(ap, 1); // As on WSL2, a little-endian machine
    // show_bytes(ap, 2);
    // show_bytes(ap, 3);
    // show_int(2607352);
    // show_float(3510593.0);
    // const char *m = "mnopqr";
    // show_bytes((byte_pointer) m, strlen(m));
    // int arr[] = {1,2,3,4,5};
    // int count = sizeof(arr) / sizeof(arr[0]);
    // reverse_array(arr, count);
    // int x = 0b10101010; // 170
    // int y = 0b11001100; // 204
    // printf("bis(x, y) = %d\n", bis(x, y)); // 238
    // printf("bic(x, y) = %d\n", bic(x, y)); // 34
    // printf("bool_or(x, y) = %d\n", bool_or(x, y)); // 238
    // printf("bool_xor(x, y) = %d\n", bool_xor(x, y)); // 102

    // int z = equal(1, 1);
    // printf("Result is %d\n", z);

    // short x = -12345; // 1001110000001100
    // short mx = -x; // 1110001111110011
    // short ux = 53191; // 1110001111110011
    // show_bytes((byte_pointer) &x, sizeof(short));
    // show_bytes((byte_pointer) &mx, sizeof(short));
    // show_bytes((byte_pointer) &ux, sizeof(short));

    // short int v = -12345;
    // unsigned short uv = (unsigned short) v;
    // printf("v= %d, uv = %u\n", v, uv); // Different bit interpretation

    // unsigned u = 4294967295u; // UMax
    // int tu = (int) u; // The underlying bit representation stays the same here
    // printf("u = %u, tu = %d\n", u, tu); // u = 4294967295, tu = -1

    // int x = -1;
    // unsigned u = 2147483648;
    // printf("x = %u = %d\n", x, x); // x = 4294967295 = -1
    // printf("u = %u = %d\n", u, u); // u = 2147483648 = -2147483648

    int s = -2147483647-1U;
    unsigned u = -2147483647;
    printf("Result is %i\n", s < u); // 0

    return 0;
}
