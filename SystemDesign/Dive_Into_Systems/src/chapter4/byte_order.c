#include<stdio.h>

int main(int argc, char **argv) {
  // A 4-byte integer
  int value = 0xAABBCCDD;
  // Point to the address of the integer
  char *p = (char *) &value;
  int i;
  // Print each byte's memory address and value starting from the base address
  for (i = 0; i < sizeof(value); i++) {
    printf("Address: %p, Value: %02hhX\n", p, *p);
    p += 1;

  // Address: 0x7ffd8f3d9aa8, Value: DD
  // Address: 0x7ffd8f3d9aa9, Value: CC
  // Address: 0x7ffd8f3d9aaa, Value: BB
  // Address: 0x7ffd8f3d9aab, Value: AA

  }

  return 0;

}
