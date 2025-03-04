---
id: Standard input-output
aliases:
  - Standard input-output
tags: []
---

# Standard input-output

Three default I/O streams: `stdout` - Standard out, `stdin` - Standard in, `stderr` - Standard error  

We print output to `stdout` and `stderr` then to the terminal, and the program reads input values from the keyboard then `stdin`   

Shell commands to redirect a program's `stdin/stdout/stderr` to a file 

```sh
# redirect a.out's stdin to read from file infile.txt:
$ ./a.out < infile.txt
# redirect a.out's stdout to print to file outfile.txt:
$ ./a.out > outfile.txt
# redirect a.out's stdout and stderr to a file out.txt
$ ./a.out &> outfile.txt
# redirect all three to different files:
# (< redirects stdin, 1> stdout, and 2> stderr):
$ ./a.out < infile.txt 1> outfile.txt 2> errorfile.txt
```

[[Common IO functions]]

