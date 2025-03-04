---
id: How malloc works under the hood
aliases:
  - How malloc works under the hood
tags: []
---

# How malloc works under the hood

Program asks `malloc` for space -> `malloc` asks [sbrk](http://man7.org/linux/man-pages/man2/sbrk.2.html) to increment the heap size + return the pointer to the **start** of a new region

`sbrk(0)` returns a pointer to the _current top of the heap_, while `sbrk(foo)` increments the heap size by `foo`, then return a pointer to the _previous top of the heap_

```c
void *malloc(size_t size) {
  void *p = sbrk(0);
  void *request = sbrk(size);
  if (request == (void*) -1) {
    return NULL; // sbrk failed.
  } else {
    assert(p == request); // Not thread safe.
    return p;
  }
}
```

Problem of the above `malloc` implementation : Given a pointer allocated by `malloc`, we need to know *what size block it is associated with* or simply put: Where do we store this?

Solution: Store **meta-information** about a memory region in some space that we put *just below the pointer we return*  


Say the top of the heap is currently at `0x1000`, and we request `0x400` bytes. Our current `malloc` implementation with `sbrk` will return a pointer to `0x1000`.

However, if we request `0x10` bytes to store information about the block, our `malloc` will request instead `0x410` bytes and return a pointer to `0x1010`, thus *hiding our `0x10` byte block of meta-information from the code that is calling `malloc`* -> We get a free block 

One troublematic thing: The heap region we get from the OS via `malloc` has to be *contiguous*,  



