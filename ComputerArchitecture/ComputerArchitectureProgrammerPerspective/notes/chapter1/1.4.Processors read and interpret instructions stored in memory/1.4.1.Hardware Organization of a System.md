---
tags:
  - "#study"
cssclasses:
  - center-images
---

![[F1.4-Hardware organization of a typical system.drawio.svg|Hardware organization of a typical system]]

### Buses

- Responsible for carrying fixed-size chunks of bytes of information (words) back and forth between components
- Word size is the **number** of bytes in a word: Most machines today has either word sizes of 4 bytes (32 bits) or 8 bytes (64 bits)

### I/O Devices

- Help our devices connect to the external world (keyboard, mouse, display, disk)
- I/O devices are connected to I/O bus to transfer data back and forth by either:
	- Chip sets in the device or on the system’s motherboard (Controllers)
	- A card that plugs into a slot on the motherboard (Adapter)

### Main memory

- A **temporary** storage device holding a program + the data the program manipulates while the processor is executing the program
- Consists of a **list** of *dynamic random access memory* (DRAM) chips
- Memory is organized as a **linear array of bytes**
- Each machine instruction constituting a program can consist of a varying number of bytes
- Data items in C vary according to type (`short` needs 2 bytes/ `int` and `float` need 4 bytes/`long` and `double` need 8 bytes - x84-64 machine running Linux)

### Processor 

- CPU is the **engine** that interprets the instructions stored in the main memory
- Core: Word-size storage device (register) called the **program counter** (PC) that is responsible for *pointing* at machine-language instructions in the main memory
- The processor follows a simple instruction execution model defined by its **instruction set architecture**:
	- (In short) The processor **repeatedly executes** instructions pointed at by the PC and **updates** the PC to point to the next instruction
	- (In detail) Executing an instruction involves steps
		1. The processor reads the instruction pointed by the PC then interprets the bits in the instruction + perform operation dictated by the instruction
		2. The processor updates the PC to point to the next instruction (NOTE: the next instruction might not be contiguous in memory to the just-executed instruction)
- Register file stores a **collection of unique word-size registers**
- The Arithmetic/Logic Unit (ALU) computes new data and address values (Actually responsible for executing the instructions)
- Examples of simple operations:
	1. **Load**: Copy a byte/word *from main memory → a register* >< Store: Copy a byte/word *from a register to a location in main memory* (both operations overwrite the previous content of the register/location)
	2. **Operate**: Copy the contents of two registers to the ALU → Perform an arithmetic operation on the two words → Store the result in a register + overwrite the previous contents of that register
		- Example: `ADD R3, R1, R2` means *adding the values in `R1` and `R2` and storing the result in `R3`* with the content of `R1` as 5 and `R2` as 7 → Perform the addition `5 + 7 = 12`
	3. **Jump**: Extract a word from the instruction → Copy that word into the PC + overwrite the previous value of that PC
		- Example: `JMP 0x0040` means jumping to Address `0x0040`
			- The CPU fetches the instruction `0001 (JMP instruction) 0000 0000 0100 0000 0000 (0x0040 - target address)`from the memory → PC holds the new value *`0x0040` as the target address* → The CPU will later fetch the instruction from the address `0x0040`

> [!important] 
> 
> While the note above describes a simple implementation of the instruction set architecture, modern processors use far more complex mechanisms to speed up execution.
