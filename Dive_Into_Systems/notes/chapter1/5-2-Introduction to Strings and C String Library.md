---
id: 5-2-Introduction to Strings and C String Library
aliases:
  - 5-2-Introduction to Strings and C String Library
tags: []
---

# 5-2-Introduction to Strings and C String Library

In C, strings are implemented as arrays of `char` values. So not every character array is used as a C string, but **every C string is a character array**

As mentioned in [5-1-Arrays in C](01-Areas/Computer/Dive_Into_Systems/notes/chapter1/5-1-Arrays%20in%20C.md), there might be cases where we do not use all the indexes of the array, and **this behavior has important implications for strings**

We CANNOT assume that _a string's length is equal to the length of the array that stores it_. Thus, **strings in C must end with the null character '\0'** to indicate the end of a string

> [!WARNING]
> Failing to properly account for null characters is a common source of errors

Keep in mind that _your arrays must be declared with enough capacity to store the string plus the null character_

For example, to store the string `"hi"` you need an array of at least 3 characters

The `string.h` library can either _locate the end of a string by searching the null character_ or _add the null character to the end of any string they modify_

> [!IMPORTANT]
> Most C string library functions expect the call to _pass in a character array_ with enough capacity for the function to perform its job. If `char str[1];` then we would not want to do `strcpy(str, "hello");`

It is also up to the programmer to **ensure string values passed to C string library functions are correctly formed** i.e., with a terminating null character

> [!WARNING] > `strcpy` is rather unsafe because it assumes its destination is large enough to store the entire string.
