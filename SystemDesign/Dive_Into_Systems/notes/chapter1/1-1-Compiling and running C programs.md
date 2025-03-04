---
id: 1-1-Compiling and running C programs
aliases:
  - 1-1-Compiling and running C programs
tags: []
---

# 1-1-Compiling and running C programs

For Python, the Python interpreter acts like a VM on which Python programs are run. The Python interpreter is a **program** that can be run _directly_ on the underlying system as **binary executable**

    +---------------------------+
    |        Python program     |
    | def main():               |
    |   x = 6 + 7;              |
    |   print("x %d" % x)       |
    | main()                    |
    +---------------------------+
               |
               v
    +---------------------------+
    |  Python interpreter       |
    |  program (a binary exec)  |
    +---------------------------+
               |
               v
    +---------------------------+
    |    Operating System (OS)  |
    +---------------------------+
               |
               v
    +---------------------------+
    |     Computer Hardware     |
    +---------------------------+

For C, the C compiler _translates the C source code into a binary executable_ for the hardware to directly execute it

```bash
gcc hello.c
./a.out
gcc hello.c -lm # Some C compilers need to be explicitly told to link the math library

```

    +---------------------------+        +---------------------------+        +---------------------------+
    |        C program          | ---->  |        C compiler         | ---->  |          a.out            |
    | int main() {              |        |                           |        |  01010110101              |
    |   int x;                  |        |                           |        |  01010101010              |
    |   x = 6 + 7;              |        |                           |        |  10101010101              |
    |   printf("x %d",x);       |        |                           |        |  01010100                 |
    |   return 0;               |        |                           |        +---------------------------+
    | }                         |        +---------------------------+
    +---------------------------+

                                        +---------------------------+
                                        |  a.out (binary executable)|
                                        +---------------------------+
                                                   |
                                                   v
                                        +---------------------------+
                                        |    Operating System (OS)  |
                                        +---------------------------+
                                                   |
                                                   v
                                        +---------------------------+
                                        |     Computer Hardware     |
                                        +---------------------------+

When compiling with gcc, it is better to include several command line options like `gcc -Wall  (enable all warnings) -g (include debugging info) -o hello hello.c`

## Variables and C numeric types

In C, all variables must be declared before they can be used like this `type_name variable_name`
