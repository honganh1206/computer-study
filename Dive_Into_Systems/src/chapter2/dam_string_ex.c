#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main() {
  int size;
  char sta_str[64];     // statically allocated
  char *dyn_str = NULL; // dynamically allocated

  strcpy(sta_str, "Hello");
  size = strlen(sta_str);

  dyn_str = malloc(sizeof(char) * (size + 1)); // 1 for '\0'

  if (dyn_str == NULL) {
    printf("ERROR: malloc failed! exiting.\n");
    exit(1);
  }
  strcpy(dyn_str, sta_str);
  printf("%s %s\n", sta_str, dyn_str);

  strcat(sta_str, " There"); // concatenation

  printf("%s\n", sta_str);
  free(dyn_str);
  dyn_str = NULL;
  return 0;
}
