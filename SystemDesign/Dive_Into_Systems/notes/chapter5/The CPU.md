As instruction operands are stored in general-purpose registers, the register file send data to the ALU inputs. In turns, the ALU's *result* is sent as input to the register file

The CPU has **additional circuitry** to move data between the ALU, register file and other components like the main memory

![[image-19.png]]

Such additional circuitry makes up the **data path** which includes parts of the CPU  that performs arithmetic/logic operations and (ALU) and stores data (registers) and the buses connecting those parts

The **control path** drives the execution of program instructions. It also *issues commands* to I/O devices and *coordinates memory accesses* by instructions

