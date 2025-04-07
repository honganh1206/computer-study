
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void foo(char *str) {
  char a[5]; // On the stack
  char b[5];
  char *c; // On the heap

  int i;

  c = (char *)malloc(sizeof(char) * 5);

  // No check for malloc error
  strcpy(a, "aaa");
  strcpy(b, "bbb");
  strcpy(c, "ccc");

  // Going beyond the bound of the stack
  for (i = 0; i <= 5; i++) {
    a[i] = str[i];
  }
  // Going beyond the bound of the heap
  for (i = 0; i <= 5; i++) {
    c[i] = str[i]; // Beyond the end of array c if i = 5
  }

  printf("a = %s, b = %s, c = %s\n", a, b, c);
}

int main() {
  char *s;

  s = (char *)malloc(sizeof(char) * 8);
  strcpy(s, "ssssss");

  foo(s); // Call foo with an allocated and initialized string
  printf("s=%s\n", s);
  free(s);

  s = (char *)malloc(sizeof(char) * 8);
  foo(s); // Call foo with an allocated but uninitialized string
  free(s);
  foo(s); // Call foo with an unallocated but uninitialized string

  s = (char *)malloc(sizeof(char) * 8);
  strcpy(s, "xxxx");
  printf("s=%s\n", s);
  s = (char *)malloc(sizeof(char) * 8); // Memory leak
  printf("s=%s\n", s);                  // Uninitialized read
  free(s);
  free(s); // Freeing already freed memory

  return 0;
}
