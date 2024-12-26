#include <stdio.h>
#include <string.h>

typedef unsigned char
    *byte_pointer; // Pointer to an object of type unsigned char

// Print the byte representations of C program objects
// We use size_t as the preferred data type to represent size of data structures
void show_bytes(byte_pointer start, size_t len) {
  int i;
  for (i = 0; i < len; i++) {
    printf(" %.2x",
           start[i]); // Here we reference array elements with pointer notation
    printf("\n");
  }

  printf("Total byte length: %zu\n", len);
}

void show_int(int x) {
  // This pointer, as a sequence of bytes, is the lowest byte address occupied
  // by the object sizeof return the NUMBER OF BYTES in the object
  show_bytes((byte_pointer)&x, sizeof(int));
}

void show_float(float x) { show_bytes((byte_pointer)&x, sizeof(float)); }

void show_pointer(void *x) { show_bytes((byte_pointer)&x, sizeof(void *)); }

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
  for (first = 0, last = cnt - 1; first < last; first++, last--) {
    inplace_swap(&a[first], &a[last]);
  }

  for (int i = 0; i < cnt; i++) {
    printf("%d ", a[i]);
  }
  printf("\n");
}

void test_reverse_array() {

  int arr[] = {1, 2, 3, 4, 5};
  int count = sizeof(arr) / sizeof(arr[0]);
  reverse_array(arr, count);
}

void test_show_bytes(int val) {
  int ival = val;
  float fval = (float)ival;
  int *pval = &val;
  printf("Calling show_int...\n");
  show_int(ival);
  printf("Calling show_float...\n");
  show_float(fval);
  printf("Calling show_pointer...\n");
  show_pointer(pval);
}

// Bit set
int bis(int x, int m) { return x | m; };

// Bit clear
int bic(int x, int m) { return x & ~m; };

int bool_or(int x, int y) {
  int result = bis(x, y);
  return result;
}

void test_bis_bic() {
  int x = 0b10101010;                    // 170
  int y = 0b11001100;                    // 204
  printf("bis(x, y) = %d\n", bis(x, y)); // 238
  printf("bic(x, y) = %d\n", bic(x, y)); // 34
}

int bool_xor(int x, int y) {
  int result = bis(bic(x, y), bic(y, x));
  return result;
}

void test_boolor_boolxor() {

  int x = 0b10101010;                              // 170
  int y = 0b11001100;                              // 204
  printf("bis(x, y) = %d\n", bis(x, y));           // 238
  printf("bic(x, y) = %d\n", bic(x, y));           // 34
  printf("bool_or(x, y) = %d\n", bool_or(x, y));   // 238
  printf("bool_xor(x, y) = %d\n", bool_xor(x, y)); // 102
}

// Longer way to check equal instead of x == y
int equal(int x, int y) {
  // If EVERY bit of x matches with every bit of y (x equal y) then x ^ y =
  // false
  return !(x ^ y);
}

void test_equal() {
  int z = equal(1, 1);
  printf("Result is %d\n", z);
}

// Casting happens after left + right shifting
int fun1(unsigned word) { return (int)((word << 24) >> 24); }

// Casting happens before left shifting
int fun2(unsigned word) { return ((int)word << 24) >> 24; }

void test_fun1_fun2() {
  unsigned test_values[] = {0x00000076,  // 118
                            0x87654321,  // 2271560481
                            0x000000C9,  // 201
                            0xEDCBA987}; // 2271560481

  printf("Testing fun1 and fun2:\n");
  for (int i = 0; i < sizeof(test_values) / sizeof(test_values[0]); i++) {
    unsigned word = test_values[i];
    printf("Input: 0x%08X |  Numerical value: %15u | fun1: %d | fun2: %d\n",
           word, word, fun1(word), fun2(word));
  }
}

void test_expand_bit_representation() {
  short sx = -12345;       // -12345
  unsigned short usx = sx; // 53191
  int x = sx;
  unsigned ux = usx;
  unsigned uy = sx;
  // 16-bit word size
  printf("sx = %d:\t", sx);                     // -12345
  show_bytes((byte_pointer)&sx, sizeof(short)); // c7 cf byte length: 2
  printf("usx: %u:\t", usx);                    // 53191
  show_bytes((byte_pointer)&usx, sizeof(unsigned short)); // c7 cf byte length 2
  // 32-bit word size
  printf("x = %d:\t", x);                    // -12345
  show_bytes((byte_pointer)&x, sizeof(int)); // c7 cf ff ff byte length 4

  printf("ux = %d:\t", ux);                        // -12345
  show_bytes((byte_pointer)&ux, sizeof(unsigned)); // c7 cf 00 00 byte length: 4
  printf("uy = %d:\t",
         uy); // This will behave differently on big-endian machines
  show_bytes((byte_pointer)&uy, sizeof(unsigned));
}

void test_conversion() {
  short int v = -12345;
  unsigned short uv = (unsigned short)v;
  printf("v= %d, uv = %u\n", v, uv); // Different bit interpretation

  unsigned u = 4294967295u; // UMax
  int tu = (int)u; // The underlying bit representation stays the same here
  printf("u = %u, tu = %d\n", u, tu); // u = 4294967295, tu = -1
}

void test_truncation() {
  int x = 53191;
  short sx = (short)x; // -12345
  int y = sx;          // -12345
  printf("sx = %d, y = %d\n", sx, y);
  show_bytes((byte_pointer)&sx, sizeof(short)); // Byte length 2
  show_bytes((byte_pointer)&y, sizeof(int));    // Byte length 4
}

float sum_elements(float a[], unsigned length) {
  int i;
  float result = 0;
  for (i = 0; i < length; i++) {
    result += a[i];
  }
  return result;
}

void test_sum_elements() {
  float test_values[] = {1.1, 2.2, 3.3};
  size_t len = sizeof(test_values) / sizeof(test_values[0]);
  float result = sum_elements(test_values, len);
  printf("result = %f\n", result);
}

typedef struct {
  char *input_s;
  char *input_t;
  int expected_output;
} TEST_STRLONGER;

int strlonger(char *s, char *t) { return (int)strlen(s) - (int)strlen(t) > 0; }

void test_strlonger() {
  TEST_STRLONGER test_table[] = {
      {"hello", "hi", 1},  // Test case 1
      {"hi", "hello", 0},  // Test case 2
      {"abc", "def", 0},   // Test case 3
      {"", "nonempty", 0}, // Test case 4
      {"nonempty", "", 1}, // Test case 5
      {"", "", 0},         // Test case 6
      {"a ", "a", 1},      // Test case 7.1
      {"a", "a ", 0},      // Test case 7.2
      {"!@#$", "!@", 1},   // Test case 8
      {"aaaaa", "aaa", 1}, // Test case 11
      {"世界", "a", 1}     // Test case 12
  };

  int numCases = sizeof(test_table) / sizeof(test_table[0]);

  for (int i = 0; i < numCases; i++) {
    TEST_STRLONGER test = test_table[i];
    int result = strlonger(test.input_s, test.input_t);

    if (result == test.expected_output) {
      printf("Test %d passed.\n", i + 1);
    } else {
      printf("Test %d failed. Input: ('%s', '%s'). Expected: %d. Got %d\n",
             i + 1, test.input_s, test.input_t, test.expected_output, result);
    }
  }
}

// PP 2.27: Determine whether arguments can be added without overflow
int uadd_ok(unsigned x, unsigned y) {
    unsigned sum = x + y;
    return sum >= x;
}

typedef struct {
    unsigned x;
    unsigned y;
    int expected_output;
} TEST_UADD_OK;

void test_uadd_ok() {
    TEST_UADD_OK test_table[] = {
        {1, 1, 1},                    // Simple addition
        {0, 0, 1},                    // Zero case
        {~0u, 1, 0},                 // Basic overflow case (~0u is all 1s = UINT_MAX)
        {~0u - 5, 10, 0},            // Overflow with larger numbers
        {~0u, 0, 1},                 // Edge case with max value
        {0, ~0u, 1},                 // Edge case other way
        {~0u/2, ~0u/2, 1},          // Half max values
        {~0u/2 + 1, ~0u/2 + 1, 0}   // Just over half
    };

    int numCases = sizeof(test_table) / sizeof(test_table[0]);

    for (int i = 0; i < numCases; i++) {
        TEST_UADD_OK test = test_table[i];
        int result = uadd_ok(test.x, test.y);

        if (result == test.expected_output) {
            printf("Test %d passed.\n", i + 1);
        } else {
            printf("Test %d failed. Input: (%u, %u). Expected: %d, Got: %d\n",
                   i + 1, test.x, test.y, test.expected_output, result);
        }
    }
}

// PP 2.30
int tadd_ok(int x, int y) {
    int sum = x + y;
    return !((x > 0 && y > 0 && sum <= 0) || // Positive overflow detection
        (x < 0 && y < 0 && sum >= 0)); // Negative overflow detection
    // return (sum-x == y) && (sum-y == x); // PP 2.31 - This is wrong because (x+y)-x still evaluates to y whether an overflow occurs or not
}

// PP 2.32 - The results will be wrong in case -y is equal to TMin. In that case, overflow will occure if x is negative.
int tsub_ok(int x, int y) {
    return tadd_ok(x,  -y);
}

typedef struct {
    int x;
    int y;
    int expected_output;
} TEST_TADD_OK;

void test_tadd_ok() {
    int int_max = ~(1 << 31);         // 0x7FFFFFFF
    int int_min = (1 << 31);          // 0x80000000

    TEST_TADD_OK test_table[] = {
        {1, 1, 1},                    // Simple addition
        {0, 0, 1},                    // Zero case
        {int_max, 1, 0},              // Positive overflow
        {int_min, -1, 0},             // Negative overflow
        {int_max - 1, 1, 1},          // Just below positive overflow
        {int_min + 1, -1, 1},         // Just below negative overflow
        {int_max/2, int_max/2, 1},    // Large positive numbers that don't overflow
        {int_min/2, int_min/2, 1},    // Large negative numbers that don't overflow
        {int_max, -1, 1},             // Mixed signs, no overflow
        {int_min, 1, 1},              // Mixed signs, no overflow
        {int_max, int_max, 0},        // Guaranteed overflow with two max values
        {int_min, int_min, 0}         // Guaranteed overflow with two min values
    };

    int numCases = sizeof(test_table) / sizeof(test_table[0]);

    for (int i = 0; i < numCases; i++) {
        TEST_TADD_OK test = test_table[i];
        int result = tadd_ok(test.x, test.y); // Could be replaced with tsub_ok()

        if (result == test.expected_output) {
            printf("Test %d passed.\n", i + 1);
        } else {
            printf("Test %d failed. Input: (%d, %d). Expected: %d, Got: %d\n",
                   i + 1, test.x, test.y, test.expected_output, result);
        }
    }
}


int main(int argc, char *argv[]) {
  // test_show_bytes(12345);
  //  test_reverse_array();
  // test_bis_bic();
  // test_boolor_boolxor();
  // test_equal();
  // test_conversion();
  // test_fun1_fun2();
  // test_truncation();
  // test_sum_elements();
  // test_strlonger();
  // test_uadd_ok();
  test_tadd_ok();
  return 0;
}
