---
id: Common compilation errors
aliases:
  - Common compilation errors
tags: []
---

# Common compilation errors

Linking `.h` file does not work

```bash
$ gcc -c myprog.c -lexamplelib
/usr/bin/ld: cannot find -lexamplelib
collect2: error: ld returned 1 exit status

```

To resolve, the programmer must _explicitly provide paths on the command line_ using `-I` and `-L`

```bash
# -I for header file and -L for shared object file
gcc -I/home/me/include -o myprog myprog.c -L/home/me/lib -lexamplelib
```

[[Creating my own library - A quick glance]]
