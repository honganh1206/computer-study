---
id: How to use Memcheck
aliases:
  - How to use Memcheck
tags: []
---

# How to use Memcheck

First compile the program with the `-g` flag to add debugging information to the executable

```bash
$ gcc -g valgrindbadprog.c
$ valgrind -v ./a.out
# re-direct valgrind (and a.out) output to file 'output.txt'
$ valgrind -v ./a.out >& output.txt
# view program and valgrind output saved to out file
$ vim output.txt
```

> [!TIP]
> Although memory leaks are important to fix, other types of memory access errors are much more critical. A programmer should focus on fixing these type of memory access errors first.

```txt
==454523== Invalid write of size 1
==454523==    at 0x109246: foo (valgrindbadprog.c:25)
==454523==    by 0x1092C5: main (valgrindbadprog.c:37)
==454523==  Address 0x4a9c095 is 0 bytes after a block of size 5
alloc'd
==454523==    at 0x4848899: malloc (in /usr/libexec/valgrind/vgpr
eload_memcheck-amd64-linux.so)
==454523==    by 0x1091D1: foo (valgrindbadprog.c:12)
==454523==    by 0x1092C5: main (valgrindbadprog.c:37)

```
