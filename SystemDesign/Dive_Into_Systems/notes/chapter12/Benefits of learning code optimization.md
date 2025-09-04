At the end of the day, compilers are not black boxes but just a piece of software that performs a series of code transformations to speed up code.

Limitations of compilers:

> Algorithmic Strength Reduction is Impossible

Poor code performance is usually the result of bad choices of data structures and algorithms. Compilers cannot magically fix these bad decisions.

> Compiler Optimization Flags are not guaranteed to make code "optimal" (or consistent)

Increase the level of compiler optimizations e.g., from 02 to 03, may not always decrease the runtime of a program, and even slow the program down.

There are also cases where updating optimization flags can lead to segmentation faults or other errors in a previously working program.

Note that GCC debug flag `-g` is NOT COMPATIBLE with its optimization flag `-O`

```c
// Supposed that a = INT_MAX
// This will lead to integer overflow, 
// but C/C++ standard does not define how integer overflow should be handled by the compiler
int silly(int a) {
  return (a + 1) > a;
}
```


[[The compiler is not required to handle undefined behavior]]

> Pointers can prove problematic

If a transformation risks changing the behavior of the program, the compiler will NOT make the transformation.

**Memory aliasing** is when two different pointers point to the same address in memory. 

Consider these code snippets:

```c
// Un-optimized version
void shiftAdd(int *a, int *b){
    *a = *a * 10; //multiply by 10
    *a += *b; //add b
}

// Optimized version
// Remove an additional memory reference to a
// resulting in a smaller set of instructions
void shiftAddOpt(int *a, int *b){
    *a = (*a * 10) + *b;
}
```
