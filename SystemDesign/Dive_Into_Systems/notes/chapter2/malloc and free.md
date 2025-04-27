---
id: malloc and free
aliases:
  - malloc and free
tags: []
---

# malloc and free

In C, heap memory must be **explicitly allocated** (aka malloc'ed) and deallocated (aka freed)

```c
int main() {
  int *p;
  p = malloc(sizeof(int)); // Allocate heap mem for an int

  if (p != NULL) {
    *p = 6; // The heap memory p points to the value 6
  }
}
```

Note that `malloc` returns a `void*` (void pointer) Thus, sometimes we might see calls to `malloc` that _explicitly recast its return type from `void` to match the type of the pointer variable_

```c
int* p = (int*)malloc(sizeof(ptr));
```

> [!WARNING]
> A call to `malloc` fails if _there is not enough free heap memory_ to satisfy the requested number of bytes to allocate.
> Some cases of this could be mallocing a large request, passing a negative number of bytes, or mallocing infinitely until we run out of heap memory

Always remember to test `malloc`'s return value for `NULL` before dereferencing

```c
  if (p == NULL) {
    printf("Bad malloc error\n");
    exit(1); // exit the program and indicate error
  }

  *p = 6;
```

If a program no longer eeds the heap memory from the `malloc`, we should _explicitly_ deallocate the memory by calling `free`

Also we should set the pointer variable to `NULL` after calling `free` to avoid the [dangling pointer](01-Areas/Computer/Dive_Into_Systems/notes/chapter2/Dangling%20pointer.md)

```c
free(p);
p = NULL;
```

# Odd: Why `free` expects only the address of the heap space without needing the size of the heap space?

Answer: `malloc` also allocates **a few additional bytes** right before the allocated chunk to store a **header structure**

As the structure stores metadata about the allocated chunk, the implementation of `free` can get the size from the header that is _in memory right before the allocated chunk_
