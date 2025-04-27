The **fetch-decode-execute-store** cycle of actions

## Fetching

The control unit fetches the next instruction from the program counter

It then places the address on the address bus & a `read` command on the control bus

The memory unit then reads the bytes stored at the specific address and sends them to the control unit via the data bus

The instruction register (IR) stores the bytes of the instruction received from the memory unit

The control unit increments the PC's value to store the address of the next-in-line instruction

![[Pasted image 20250424213643.png]]

## Decoding

The control unit decodes the instruction bits stored in the IR to get the operator + addresses of the operands

The decoded instruction bits are based on the ISA's definition of encoding of its instructions

The control unit also fetches the data operand values from their locations, which could be the CPU registers, RAM, or encoded in the instruction bits

## Executing

The ALU performs the instruction operation on the instruction data operands

![[Pasted image 20250424214722.png]]

## Storing

The result of the operation is stored to memory

The control unit writes the result to memory by placing the result value in the data bus, the address of the result storage location on the address bus, and the `write` command to the control bus

The memory unit receives the request and store the result value to the given memory location