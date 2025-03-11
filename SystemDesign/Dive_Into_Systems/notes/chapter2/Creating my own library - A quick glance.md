---
id: Creating my own library - A quick glance
aliases:
  - Creating my own library - A quick glance
tags: []
---

# Creating my own library - A quick glance

1. Create a header file `mylib.h` and implement the functions in the header file
2. Compile the file to a shared object file:

```bash
# Compile the source code into an object file
# PIC stands for Position Independent Code
gcc -c -fPIC mylib.c -o mylib.o
# Create a shared object file
gcc -shared -o libmylib.so mylib.o
# Check dependencies
ldd mylib.so
nm -D mylib.so
# Link the shared object file with the program
# Dynamically linked
# Move your library to a standard location
sudo cp mylib.so /usr/local/lib/
sudo ldconfig # Update the cache
gcc -o myprog myprog.c -lmylib
# Or (still dynamic linking)
gcc -o linking_ex linking_ex.c ./libexamplelib.so ./libmylib.so
# Statically linked
gcc -o myprog myprog.c -L. mylib.c

```
