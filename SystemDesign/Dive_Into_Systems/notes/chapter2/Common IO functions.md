---
id: Common IO functions
aliases:
  - Common IO functions
tags: []
---

# Common IO functions

## printf

```sh
%f, %g: placeholders for a float or double value
%d: placeholder for a decimal value (char, short, int)
%u: placeholder for an unsigned decimal
%c: placeholder for a single character
%s: placeholder for a string value
%p: placeholder to print an address value
%ld: placeholder for a long value
%lu: placeholder for an unsigned long value
%lld: placeholder for a long long value
%llu: placeholder for an unsigned long long value
```

## scanf

`scanf` is picky about the exact format in which the user inputs data 

Programs combine the `&` operator with a variable name to produce the location of the variable in the program's memory 

`scanf` will skip over leading and trailing whitespace characters and find the start and end of each numerical value 

```c
int x;
float pi;
// read in an int and a float separated by at least one white space character
scanf("%d%g", &x, &pi);
return 0;

```

## getchar and putchar
```c
ch = getchar(); // read in the next char value from stdin
putchar(ch); // write the value of ch to stdout
```
