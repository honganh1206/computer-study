A C primitive that *forces program execution to switch to another line in the code*

The Assembly equivalent of `goto` is `jmp`

Structure: `goto <label>`. Example is `goto done` meaning the program should jump to the line marked by label `done`

Not a good practice in modern code since it reduces code readability

GCC typically changes C code with conditionals to `goto` form prior to translating it to assembly