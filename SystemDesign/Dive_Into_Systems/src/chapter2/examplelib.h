#ifndef _EXAMPLELIB_H_
#define _EXAMPLELIB_H_
#define MAX 10

// The function's definition comes from another file
// Provided by one of the .c files in the library's implementation
// Link this with gcc -g myprog.c -lexamplelib
extern int libraryfunc(int x, int y);
#endif // !DEBUG
