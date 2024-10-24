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
    const char *m = "mnopqr";
    show_bytes((byte_pointer) m, strlen(m));
    return 0;
}
