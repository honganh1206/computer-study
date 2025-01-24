#include <stdio.h>
#include <string.h>

struct studentT {
  char name[64];
  int age;
  float gpa;
  int grad_yr;
};

int checkID(struct studentT s, int min_age);

int checkID(struct studentT s, int min_age) {
  int ret = 1; // return true

  if (s.age < min_age) {
    ret = 0;
    // test changing the student's age
    // here only the value inside the struct parameter is modified
    // the value inside the struct argument is in another memory address
    s.age = min_age + 1;
  }

  printf("%s is %d years old\n", s.name, s.age); // Rick will be 19 here

  return ret;
}

int main() {
  // struct studentT student1, student2;

  // strcpy(student1.name, "Hong Anh Pham");
  // student1.age = 25;
  // student1.gpa = 3.6;
  // student1.grad_yr = 2020;

  // printf("name: %s age: %d gpa: %g, year: %d\n", student1.name, student1.age,
  //        student1.gpa, student1.grad_yr);

  // student2 = student1;

  // /* Make a few changes to the student2 variable. */
  // strcpy(student2.name, "Frances Allen");
  // student2.grad_yr = student1.grad_yr + 1;
  // /* Print the fields of student2. */
  // printf("name: %s age: %d gpa: %g, year: %d\n", student2.name, student2.age,
  //        student2.gpa, student2.grad_yr);
  // /* Print the size of the struct studentT type. */
  // printf("number of bytes in student struct: %lu\n", sizeof(struct
  // studentT));

  int can_vote;
  struct studentT std;

  strcpy(std.name, "Rick");

  std.age = 17;
  std.gpa = 3.5;
  std.grad_yr = 2021;

  can_vote = checkID(std, 18);
  // Rick will still be 17 here

  if (can_vote) {
    printf("%s is %d years old and can vote.\n", std.name, std.age);
  } else {
    printf("%s is %d years old and cannot vote.\n", std.name, std.age);
  }

  return 0;
}
