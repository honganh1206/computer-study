#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct studentT {
  char name[64];
  int age;
  float gpa;
  int grad_yr;
};

struct personT {
  char *name;
  int age;
};

int main() {
  /*struct studentT s;*/
  /*struct studentT *sptr;*/
  /**/
  /*strcpy(s.name, "Freya");*/
  /*s.age = 18;*/
  /*s.gpa = 4.0;*/
  /*s.grad_yr = 2020;*/
  /**/
  /*sptr = malloc(sizeof(struct studentT));*/
  /*if (sptr == NULL) {*/
  /*  printf("ERROR: malloc failed\n");*/
  /*  exit(1);*/
  /*}*/
  /*strcpy(sptr->name, s.name);*/
  /*printf("%s", sptr->name);*/
  /*free(sptr);*/
  /*sptr = NULL;*/

  struct personT p1, *p2;

  // malloc from the inside
  p1.name = malloc(sizeof(char) * 8);
  strcpy(p1.name,"Anna"); 
  p1.age = 22;

  // malloc from the outside
  // first malloc space for the struct
  p2 = malloc(sizeof(struct personT));
  if (p2 == NULL) {
    printf("ERROR: malloc failed\n");
    exit(1);
  }
  // then malloc space for the name field
  p2->name = malloc(sizeof(char) * 4);
  if (p2->name == NULL) {
    printf("ERROR: malloc failed\n");
    exit(1);
  }
  strcpy(p2->name, "Vic");
  p2->age = p1.age;
  
  printf("%s\n", p2->name);
  printf("%d\n", p2->age);

  free(p2->name);
  p2->name = NULL;

  free(p2);
  p2 = NULL;

  return 0;
}
