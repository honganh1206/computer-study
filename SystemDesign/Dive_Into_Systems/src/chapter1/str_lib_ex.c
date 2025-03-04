#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main() {
  int len, i, ret;
  char sta_str[32];     // statically allocated
  char *dyn_str = NULL; // dynamically allocated
  char *ptr; // points to the beginning of a substring inside another string
  strcpy(sta_str, "Zebra fish");
  len = strlen(sta_str);

  dyn_str = malloc(sizeof(char) * (len + 1));

  if (dyn_str == NULL) {
    printf("ERROR: malloc failed! exiting.\n");
    exit(1);
  }
  strcat(sta_str, " stripes");
  printf("%s\n", sta_str);
  strncat(sta_str, " are black.", 8); // Safe concatenation
  printf("%s\n", sta_str);            // spaces count

  ptr = strstr(sta_str, "trip");

  if (ptr != NULL) {
    printf("%s\n", ptr); // tripes are bla
  }

  ptr = strchr(sta_str, 'e');

  if (ptr != NULL) {
    printf("%s\n", ptr); // ebra fish stripes are bla
  }

  /**/
  /*strcpy(dyn_str, "Zebra");*/
  /**/
  /*ret = strcmp(sta_str, dyn_str);*/
  /**/
  /*if (ret == 0) {*/
  /*  printf("%s us equal to %s\n", sta_str, dyn_str);*/
  /*} else if (ret < 0) {*/
  /*  printf("%s is less than %s\n", sta_str, dyn_str);*/
  /*} else {*/
  /*  printf("%s is greater than %s\n", sta_str, dyn_str);*/
  /*}*/
  /**/
  /*ret = strncmp(sta_str, "all", 3);*/

  free(dyn_str);
  dyn_str = NULL;

  return 0;
}
