---
tags:
  - "#study"
  - "#review"
cssclasses:
  - center-images
---
At that time, most system programs had to be written largely in assembly code to *have access to the low-level representations of different data types*

First major version of C was the *ANSI C standard in 1989* before being adopted by the ISO as “ISO C90”. ISO continued to sponsor an update on the language in 1999 with “ISO C99” with new data types and support for text strings of non-English languages. All of the updates are *backward compatible*.

To compile programs in different versions:

`gcc <option> prog.c`

| C version     | gcc command-line option |
| ------------- | ----------------------- |
| GNU 89<br>    | none, -std=gnu89        |
| ANSI, ISO C90 | -ansi, -std=c89         |
| ISO C99       | -std=c99                |
| ISO C11       | -std=c11                |
