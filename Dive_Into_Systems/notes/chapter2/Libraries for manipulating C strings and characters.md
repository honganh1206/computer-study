---
id: Libraries for manipulating C strings and characters
aliases:
  - Libraries for manipulating C strings and characters
tags: []
---

# Libraries for manipulating C strings and characters

`string.h` is useful when writing programs that use C strings

`stdlib.h` and `stdio.h` libraries also contain functions for string manipulation

`ctype.h` contains functions to manipulate _individual character values_

Most functions from the above libraries [do not check if the allocated memory is sufficient nor that you pass a valid string](./Dynamically allocating strings.md)

Also, the callers of these functions need to ensure that the strings are correctly formatted i.e., having '\0' at the end

## `char[]` and `char *` parameters and `char *` return type

We can pass either a statically declared/dynamically allocated arrays of characters to a parameter of `char *` type since **the name of either type evaluates to the base address of the array in memory** (Also more commonly used than `char []`)

If a function returns a value of type `char *`, its return value can only be assigned to a variable of type `char *` and cannot be assigned to a statically declared array variable. This happens because [the name of a statically declared array variable is not a valid lvalue](../chapter1/About lvalues.md)

[`strcpy` is often unsafe](../chapter1/5-2-Introduction to Strings and C String Library.md) to use when the source string might be longer than the total capacity of the destination string. For this reason, one should use `strncpy`

## String comparison with `strcmp` and `strncmp`

The `==` operator does NOT compare the characters but only the base addresses of the two strings

How does the comparison work? The comparison _compares the `char` values in corresponding positions of the two parameter arrays_ i.e., compare each character. This can **yield un-intuitive results**

Example: The ASCII encoding for `a` is **larger** than the one for `Z`, thus `strcmp("aaa", "Zoo")` will indicate that `"aaa"` is greater than `"Zoo"`

## Other useful functions

`strcat` and `strncat` is for string concatenation

`strstr` to locate a substring inside a string. `strchr` to locate a character inside a string

Calls to `strchr` and `strstr` return the **address** of the first element in the parameter array. `strchr` will return the address of the matching character value, while `strstr` will return the address of the matching substring value

We have `strtok` and `strtrok_r` to divide a string into [[Tokens]]

The `sprintf` function "prints" into a string rather than printing output to a terminal

```c
char str[64];
float ave = 76.8;
int num = 2;
// initialize str to format string, filling in each placeholder with
// a char representation of its arguments' values
sprintf(str, "%s is %d years old and in grade %d", "Henry", 12, 7);
printf("%s\n", str); // prints: Henry is 12 years old and in grade 7
sprintf(str, "The average grade on exam %d is %g", num, ave);
printf("%s\n", str); // prints: The average grade on exam 2 is 76.8
```

## Functions for individual character values

```c
#include <stdlib.h>
 // include stdlib and ctype to use these
#include <ctype.h>
int islower(ch);
int isupper(ch);
int isalpha(ch);
int isdigit(ch);
int isalnum(ch);
int ispunct(ch);
int isspace(ch);
char tolower(ch);
char toupper(ch);
// these functions return a non-zero value if the
// test is TRUE, otherwise they return 0 (FALSE)
// re
```

## Functions to convert strings to other types

```c
#include <stdlib.h>
int atoi(const char *nptr); // convert a string to an integer
double atof(const char *nptr); // convert a string to a float
```
