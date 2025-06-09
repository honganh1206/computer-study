Control changes arising from `if` statements or loops can affect the pipeline performance

Example in C:

```c
int result = *x; // x holds an int
int temp = *y;   // y holds another int

if (result <= temp) {
	result = result - temp;
}
else {
	result = result + temp;
}
return result;
```

The assembly version of the C code:

```assembly
  MOV M[0x84], Reg1 # move value at memory address 0x84 to register Reg1
  MOV M[0x88], Reg2 # move value at memory address 0x88 to register Reg2
  CMP Reg1, Reg2    # compare value in Reg1 to value in Reg2
  JLE L1<0x14>      # switch code execution to L1 if Reg1 less than Reg2
  ADD Reg1, Reg2, Reg1  # compute Reg1 + Reg2, store result in Reg1
  JMP L2<0x20>          # switch code execution to L2 (code address 0x20)
L1:
  SUB Reg1, Reg2, Reg1  # compute Reg1 - Reg2, store in Reg1
L2:
  RET                   # return from function
```

The `if` instruction is represented by *two instructions*: The compare (`CMP`) and the conditional jump less than (`JLE`) instruction. The `JLE` instruction is a special type of **branch** that *switches code execution to another part of the program* if the condition is true

> Unlike other code snippets, conditional statements are NOT guaranteed to execute in a particular way

A **control hazard** occurs when the pipeline has to "guess" whether a conditional branch will be taken. If the branch is not taken, the process continues executing the next instruction in sequence

![[image-31.png|If the branch is taken, the next instruction should be `SUB`]]

Problem: It is *impossible* to know whether the branch is taken until `JLE` finishes executing, but at that point `ADD` and `JMP` are already loaded into the pipeline

But if the branch IS taken i.e., the statement in `if` is executed, the "junk" instructions in the pipeline i.e., `else` in this case, need to be *removed/flushed* before the pipeline can be reloaded

Measures to take:

![[image-32.png]]

1. Stall the pipeline: Simple by adding lots of `NOP` bubbles, but will impact performance
2. Branch prediction: Most common one by *predicting which way a branch will go*based on previous executions. However this has recently caused some security vulnerabilities e.g., Spectre (See more [here](https://stackoverflow.com/a/11227902))
3. Eager execution (Immediately evaluate expressions or operations when encountering them): The CPU executes both sides of the branch and performs a *conditional transfer of data rather than control*. This enables the processor to continue execution without disrupting the pipeline, but not all code can take advantage of eager execution

```c
int compute(int x) {
    if (x > 0)
        return x * 2;
    else
        return x * 3;
}

# Compute both branches in parallel
int compute_eager(int x) {
    int a = x * 2;
    int b = x * 3;
    return (x > 0) ? a : b;
}

```