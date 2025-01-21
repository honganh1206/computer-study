#include <stdio.h>
#include <string.h>

int main() {
  char str1[10];
  char str2[10];
  int len;

  str1[0] = 'h';
  str1[1] = 'i';
  str1[2] = '\0';

  len = strlen(str1);

  printf("%s %d\n", str1, len); // Null char does not count as a char here
  strcpy(str2, str1);
  printf("%s\n", str2);

  strcpy(str2, "hello"); // Add null char to the end of the string they modify
  len = strlen(str2);
  printf("%s has %d chars\n", str2, len);

  return 0;
}
