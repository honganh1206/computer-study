---
id: File IO
aliases:
  - File IO
tags: []
---

# File IO

A text file represents **a stream of characters**, and each open file *tracks its current position in the character stream*

The stream starts at the *very first* character of the file, and it moves as every character is read from/written to the file 

To skip characters we use the `fseek` function. We can use functions like `fputc/fgetc/fputs/fgets` to read and write individual characters or strings to file streams  

Text files may contain special chars like newlines `\n` or tabs `\t`  

The I/O library of C also generates a special end-of-file (EOF) character that *represents the end of the file* 

Some common functions
```c
int x;
double d;
char c, array[MAX];
// write int & char values to file separated by colon with newline at the end
fprintf(outfile, "%d:%c\n", x, c);
// read an int & char from file where int and char are separated by a comma
fscanf(infile, "%d,%c", &x, &c);
// read a string from a file into array (stops reading at whitespace char)
fscanf(infile,"%s", array);
// read a double and a string up to 24 chars from infile
fscanf(infile, "%lf %24s", &d, array);
// read in a string consisting of only char values in the specified set (0-5)
// stops reading when...
// 20 chars have been read OR
// a character not in the set is reached OR
// the file stream reaches end-of-file (EOF)
fscanf(infile, "%20[012345]", array);
// read in a string; stop when reaching a punctuation mark from the set
fscanf(infile, "%[^.,:!;]", array);
// read in two integer values: store first in long, second in int
// then read in a char value following the int value
fscanf(infile, "%ld %d%c", &x, &b, &c);
```
