## Fetching

The CPU *fetches* the next instruction from memory and store it inside the instruction register (IR).

The memory address of that next instruction is stored in the program counter (PC). The PC keeps track of the memory address of the next instruction for the next *fetch* phase.

Example: If all instructions are 32 bits long, the PC's value is incremented by 4 with each byte being 8 bits (4x8=32) so it has enough storage to store the memory address of the next instruction

The PC's value is incremented by arithmetic circuits that are *separate from the ALU increment*

![[01-Areas/Computer/SystemDesign/Dive_Into_Systems/notes/chapter5/image-21.png|The fetch stage of execution: Read the instruction in memory -> Store the instruction in the IR -> Increment the PC's value]]

## Decoding

The CPU *decodes* the instruction bits stored in the register into **four parts**: 

1. The high-order bits of the instruction encodes the opcode
2. The remaining bits are divided into three subsets that specify two operand sources and the result destination

The opcode is sent to the [[Arithmetic Logic Unit]] (ALU) as input and the two sets of operand bits are inputs to [[The Register File]]

Destination bits in the IR are sent in the WriteBack phase

![[01-Areas/Computer/SystemDesign/Dive_Into_Systems/notes/chapter5/image-22.png|Decoding the instructions -> Send opcode to ALU and operand bits to the register file.]]


## Executing

Data inputs of the ALU come from *the two outputs of the register file* `Data out 0` and `Data out 1`, and the ALU's selection input comes from the opcode bits of the instruction

The ALU outputs the result of adding the values in `Reg1` and `Reg3` (now stored in the register file) , together with the condition code. The result is stored in the *destination register*, which is sent via the `Data in` input of the register file 

![[01-Areas/Computer/SystemDesign/Dive_Into_Systems/notes/chapter5/image-23.png|The ALU performs the specified operation (from the opcode) on its input values (as outputs from the register file)]]

## WriteBack

If the destination register is `Reg0`, then the bits encoding `Reg0` in the IR are sent as the `Sw` input to the register file to *pick the destination register in many registers*. The ALU's result is then sent to the destination register, with WE bit set to 1 to enable writing the ALU result into `Reg0`

![[image-24.png|The result of the Execution stage is written to the destination register, picked by the Sw input]]