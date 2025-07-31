![[image-31.png|Noncontiguous matrix layout in memory]]

The array of pointers is contiguous, and each element points to an array, which itself is contiguous. 

Each element in `M2` takes 8 bytes of space, and each element of `M2[i]` array is four bytes (`int` type)

Example with `M2[1][2]`:

The compiler first computes the address of `M2[1]` by multiplying 1 by 8 `sizeof(int *)`, yielding the address `x8`. We then de-reference this address to get the address `x36`, which is the pointer to an array of integers. 

The compiler then multiplies index 2 by 4 `int` and add it with `x36` to yield `x44`. This address is then de-referenced to get the value 5. We then have `M2[1][2] = 5`