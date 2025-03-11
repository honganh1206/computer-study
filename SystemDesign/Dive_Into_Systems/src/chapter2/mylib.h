#ifndef _MYLIB_H_
#define _MYLIB_H_
#define MAX_FOO 20

struct foo_struct {
  int x;
  float y;
};

// Export global vars
extern int total_times;

// Function prototype
extern float bigger(float y, float z);
#endif
