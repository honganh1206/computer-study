Recall:

1. Arrays are ordered collections of data elements of the same type. All elements are contiguously stored in memory (See [[Arrays in C]])
2. Compilers often convert array references into pointer arithmetic prior to translating to Assembly like `arr + i` is equivalent to `&arr[i]`, or `*(arr + i)` is equivalent to `arr[i]` (See [[Pointer Arithmetic]])
3. `int` takes 4 bytes of space, where `int *` takes up 8 bytes of space

## Common array operations

| Operation      | Type    | Assembly Representation    | Note                                                                                                                    |
| -------------- | ------- | -------------------------- | ----------------------------------------------------------------------------------------------------------------------- |
| `x = arr`      | `int *` | `mov %rdx, %rax`           | `mov` de-references pointer                                                                                             |
| `x = arr[0]`   | `int`   | `mov (%rdx), %eax`         |                                                                                                                         |
| `x = arr[i]`   | `int`   | `mov (%rdx, %rcx,4), %eax` | The address to look at will be `arr+3*4`, since the compiler must multiply the index by the size of the data type `int` |
| `x = &arr[3]`  | `int *` | `lea 0xc(%rdx), %rax`      | `lea` computes addresses                                                                                                |
| `x = arr+3`    | `int *` | `lea 0xc(%rdx), %rax`      |                                                                                                                         |
| `x = *(arr+5)` | `int`   | `mov 0x14(%rdx), %eax`     |                                                                                                                         |

## Arrays layout in memory

![[image-28.png|A 10-integer array in memory. Each x-labeled box represents 4 bytes]]

The element at index `i` in an array is stored at address `arr + sizeof(T) * i`. To compute the address of element with index 3, the compiler multiplies the index 3 by the data size of `int` (4 bytes) to yield an offset of 12 (`0xc`). 

`cltq` stands for "Convert long to quad" to convert 32-bit value stored in `%eax` to 64-bit value to store in `%rax`

> Addresses are stored as 64-bit words