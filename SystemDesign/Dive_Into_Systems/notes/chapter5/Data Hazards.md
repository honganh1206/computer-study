When? Two instructions attempt to access common data in an instruction pipeline

```assembly
MOV M[0x84], Reg1     # move value at memory address 0x84 to register Reg1
ADD 2, Reg1, Reg1     # add 2 to value in Reg1 and store result in Reg1
```

While `MOV` requires five stages, `ADD` only needs four stages, thus both instructions will attempt to write into `Reg1` at the same time

![[image-29.png]]

How to resolve? The processor will *force every instructions to take five stages*, and for instructions that take fewer than five stages, the CPU adds a "no-operation" (NOP) instruction to substitute that stage

But `MOV` needs to finish writing to the register `Reg1` *before* `ADD` instruction can execute correctly

Another example

```assembly
MOV 4, Reg2           # copy the value 4 to register Reg2
ADD Reg2, Reg2, Reg2  # compute Reg2 + Reg2, store result in Reg2
```

Again, the `ADD` instruction executes *before* the `MOV` instruction finishes writing the value 4 to `Reg2`

In this case, we use a technique named **operation forwarding**, in which the pipeline reads the result from the previous operation

![[image-30.png]]

While the `MOV` instruction executes, it *forwards* its results to `ADD` and `ADD` can use the updated value of `Reg2` 