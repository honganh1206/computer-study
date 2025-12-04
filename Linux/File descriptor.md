> An integer that uniquely represents an opened file for the process.

When we open a file, the OS *creates an entry to represent that file* and store the information about that opened file.

Supposed that we have 100 files opened, then there will be 100 entries in the OS (somewhere in the kernel?). Those entry numbers are **file descriptors**