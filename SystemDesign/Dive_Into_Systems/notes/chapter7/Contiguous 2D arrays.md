A matrix named `m`, `m + (i * cols)` is equivalent to `&m[i]`

![[image-30.png]]

Example: Element `(1,2)` is located at address `M1 + 1*COLS + 2` and with `COLS=3` (length of each colored block), `(1,2)` corresponds to `M1 + 5`.  

To access this element, the compiler must multiply 5 by the size of the `int` data type i.e., 4 bytes, thus yielding `M1 + 20` which is for `x20`. De-referencing this location gives us element `5`