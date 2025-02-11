/*
* Extract whitespace-delimited tokens from a line of input
* and print them one per line.
*
* to compile:
* gcc -g -Wall strtokexample.c
*
* example run:
* Enter a line of text:
 aaaaa        bbbbbbbbb       cccccc
*
* The input line is:
*
 aaaaa        bbbbbbbbb       cccccc
 * Next token is aaaaa
* Next token is bbbbbbbbb
* Next token is cccccc
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main() {
  /* Stores the delim string passed to strtok
   * ' ': space '\t': tab '\f': form feed '\r': carriage return
   * '\v': vertical tab '\n': new line
   * */
  char *whitespace = " \t\f\r\v\n";

  char *token; // Next token in the line
  char *line;  // The line of text read to be tokenized

  line = malloc(200 * sizeof(char));

  if (line == NULL) {
    printf("ERROR: malloc failed\n");
    exit(1);
  }

  printf("Enter a line of text:\n");
  // Read in a line entered by user from "standard in"
  line = fgets(line, 200 * sizeof(char),
               stdin); 
  if (line == NULL) {
    printf("ERROR: reading input failed, exiting...\n");
    exit(1);
  }

  printf("The input line is: \n%s\n", line);

  // Divide the string into tokens
  token = strtok(line, whitespace); // Get 1st token
  while (token != NULL) {
    printf("Next token is %s\n", token);
    token = strtok(NULL, whitespace); // Get next token
  }

  free(line);
  line = NULL;

  return 0;
}
