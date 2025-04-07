---
id: Void type and type recasting
aliases:
  - Void type and type recasting
tags: []
---

# Void type and type recasting

`* void` represents a **generic pointer** - a pointer to any type, or a pointer to unspecified type

Why? Memory addresses on a system are always stored in the _same number of bytes_ e.g., 4 bytes on 32-bit machines and 8 bytes on 64-bit machines. Thus, _every pointer requires the same number of bytes_

> [!TIP]
>
> - `void *` is commonly used to _specify generic return types_ from functions or _generic parameters to functions_
> - `void *` can also be used as a _function parameter_ for functions that can _take any type of value_

Since `void *` is a generic pointer type, it CANNOT be _directly dereferenced_ since the compiler does not know the size of memory the address points to

Thus, we use **recasting** to tell the compiler the specific type of pointer variable, so the compiler can generate the correct memory access code

```c
// malloc returns void * here
bigfish = (int *)malloc(sizeof(int) * 10);
```

Using `void *` parameter type in a thread function allows the thread to _take any type of application-specific pointer_

The use of `void *` parameter makes `pthread_create` a generic thread creation function
