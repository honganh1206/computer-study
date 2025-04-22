#include <stdio.h>

int main(int argc, char **argv) {
  unsigned int u_val = 0xFF000000;
  int s_val = 0xFF000000;

  printf("%08X\n", u_val >> 12); // Logical right shift  -> 000FF000
  printf("%08X\n", s_val >> 12); // Arithmetic right shift ->  FFFFF000

  return 0;
}
