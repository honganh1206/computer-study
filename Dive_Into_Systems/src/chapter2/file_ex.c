#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>
int main() {
  char cwd[1024];
  if (getcwd(cwd, sizeof(cwd)) != NULL) {
    printf("Current working directory: %s\n", cwd);
  } else {
    perror("getcwd() error");
  }
  // These pointers cannot be dereferenced
  // They refer to a specific file stream when passed in the I/O library
  FILE *infile;
  FILE *outfile;

  // Check if the file exists
  struct stat buffer;
  int exists = stat("./Dive_Into_Systems/src/chapter2/input.txt", &buffer) == 0;
  printf("File exists: %s\n", exists ? "Yes" : "No");

  infile = fopen("./Dive_Into_Systems/src/chapter2/input.txt", "r"); // Relative path in read mode
  if (infile == NULL) {
    printf("Error: unable to open file %s\n", "input.txt");
    exit(1);
  }

  outfile = fopen("/home/honganh/output.txt", "w");
  if (outfile == NULL) {
    printf("Error: unable to open file %s\n", "output.txt");
    exit(1);
  }

  // Move to a specific position
  fseek(infile, 3, SEEK_CUR);

  int ch; // Since all char values can be stored in int, use int
  ch = getc(infile);
  if (ch != EOF) {
    putc(ch, outfile);
  }

  fclose(infile);
  fclose(outfile);

}
