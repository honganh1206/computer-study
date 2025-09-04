## Constant Folding

Constants in the code are evaluated at compile time to reduce the resulting number of instructions

```c
// Macro expansion replaces int debug = N - 5 with int debug = 5 - 5
// Then constant folding updates this statement to int debug = 0
#define N 5 
int debug = N - 5;
```

## Constant Propagation

Replace variables with a constant value if such a value is known at compile time.

```c
int debug = 0;

//sums up all the elements in an array
int doubleSum(int *array, int length){
    int i, total = 0;
    for (i = 0; i < length; i++){
        total += array[i];
        // Change if (debug) to if (0)
        // Also the if statement is a target of dead code elimination
        if (debug) {
            printf("array[%d] is: %d\n", i, array[i]);
        }
    }
    return 2 * total;
}
```

## Dead Code Elimination

Most compilers employ techniques such as dataflow analysis to identify unreachable code segments and remove them.

## Simplifying expressions

Some instructions are more expensive than others e.g., `imul` and `idiv`.  Compilers thus attempt to simplify mathematical operations whenever possible.

```c
//sums up all the elements in an array
int doubleSum(int *array, int length){
    int i, total = 0;
    for (i = 0; i < length; i++){
        total += array[i];
        //if statement removed through data-flow analysis
    }
    return total + total; //simplifying expression
}
```

The compiler will also transform code sequences with bit-shifting (`total * 8` to `total << 3`) and other bitwise operators (`total % 8` to `total & 7`)

## Function inlining

Replace calls to a function with the body of the function.

```c
// Original version calling to allocateArray()
int main(int argc, char **argv) {
    // omitted for brevity
    // some variables shortened for space considerations
    int lim = strtol(argv[1], NULL, 10);

    // allocation of array
    int *a = allocateArray(lim);

    // generates sequence of primes
    int len = genPrimeSequence(a, lim);

    return 0;
}

// Version with function inlining
int main(int argc, char **argv) {
    // omitted for brevity
    // some variables shortened for space considerations
    int lim = strtol(argv[1], NULL, 10);

    // allocation of array (in-lined)
    // This replaces the call to sqrt with the fsqrt function
    // subsequently move it outside of the loop
    int *a = malloc(lim * sizeof(int));

    // generates sequence of primes
    int len = genPrimeSequence(a, lim);

    return 0;
}
```

Recall: When calling a function, many instructions associated to function creation and destruction are generated.

-> Inlining functions eliminates those excessive calls and allows the compiler to identify other potential improvements

We use the flag `-finline-functions` to suggest inlining functions to the compiler.

> The compiler will NOT inline every function, and that function inlining is not guaranteed to make code faster.

Programmers should generally *avoid inlining functions manually*, as it:
- Reduces the readability of the code
- Increases the likelihood of errors
- Makes it harder to update and maintain functions

## Loop Unrolling

While branch predictors are quite good at *predicting what a conditional expression evaluates to* (especially inside loops), wrong guesses introduce hits to performance due to *disruptions in the instruction pipelines*.

Loop unrolling reduces the impact of such wrong guesses, and it does so by **reducing the number of loop iterations by a factor of N**. How can it do so? It *increases the workload each iteration performs by the factor of N*

Example: When a loop is unrolled by a factor of N = 2, the number of iterations is cut by half, where as the amount of work each iteration performs is doubled. This has been proved to marginally improve times.

```c
// Original version
int isPrime(int x) {
    int i;
    int max = sqrt(x) + 1;

    // no prime number is less than 2
    for (i = 2; i < max; i++) {
        // if the number is divisible by i
        if (x % i == 0) {
            return 0; // it's not prime
        }
    }
    return 1; // otherwise it is
}
// Version with loop unrolling
int isPrime(int x) {
    int i;
    int max = sqrt(x)+1;

    // no prime number is less than 2
    // Here the number of iterations is reduced by half
    for (i = 2; i < max; i+=2) {
		// Each iteration performs twice the work (modulo checks)
        // if the number is divisible by i or i+1
        if ( (x % i == 0) || (x % (i+1) == 0) ) {
            return 0; // it's not prime
        }
    }
    return 1; // otherwise it is
}
```

The flag `-funroll-loops` tells the compiler to unroll loops whose iterations can be determined at compile time. The flag `funroll-all-loops` could be more aggressive.