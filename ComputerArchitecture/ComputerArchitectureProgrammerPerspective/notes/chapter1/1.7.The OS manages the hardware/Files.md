---
tags:
  - "#study"
cssclasses:
  - center-images
---
A file is just **a sequence of bytes**, and every IO device is modeled as a file.

ALL input and out in the system is performed by reading + writing files via a small set of system calls named Unix I/O (a uniform view of all the varied I/O devices contained in the system)

Benefits of Unix I/O:

- *Abstract specific disk technology* from a programmer manipulating the contents of a disk file
- Allow the same program to *run on different systems* that use different disk technologies