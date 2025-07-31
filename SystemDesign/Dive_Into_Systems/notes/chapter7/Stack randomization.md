The OS allocates the starting address of the stack *at a random location in stack memory*. That way the size/position of the call stack can vary from one run of a program to another.

Multiple machines running the same code would have different stack addresses.

A trick to brute force is to use a lot of `nop` instructions (aka NOP sled): As `nop` has no effect, the attacker can cause the program counter to increment to the right address for exploit.