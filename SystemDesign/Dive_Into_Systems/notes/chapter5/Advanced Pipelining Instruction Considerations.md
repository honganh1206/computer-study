[[Five-stage Pipeline]]

```assembly
MOV M[0x84], Reg1     # move value at memory address 0x84 to register Reg1
ADD 2, Reg1, Reg1     # add 2 to value in Reg1 and store result in Reg1
MOV 4, Reg2           # copy the value 4 to register Reg2
ADD Reg2, Reg2, Reg2  # compute Reg2 + Reg2, store result in Reg2
JMP L1<0x14>          # jump to executing code at L1 (code address 0x14)
```

> Not all instructions require the same number of pipeline stages to execute. The `MOV` instruction requires all five stages, while the later three instructions only require F, D, E, W to execute given that *the operations involve only registers*

The last instruction `JMP` is a type of *branch* or *conditional* instruction. It is to *transfer the flow of control* to another part of the code

Since the `JMP` instruction does not update a general-purpose register, the WriteBack stage is omitted

A **pipeline stall** occurs when *any instruction is forced to wait for another to finish*

[[Data Hazards]]

[[Control Hazards]]