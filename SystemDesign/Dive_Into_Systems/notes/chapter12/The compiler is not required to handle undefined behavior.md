The inconsistent output produced by the compiler is not a flaw in the compiler's design or a consequence of using optimization flags.

Compilers are designed to *follow a language's specification*. The C language standard does not define what a compiler should do when it encounters undefined behavior.

Ultimately, the programmer is responsible for identifying and eliminating undefined behavior in the code.