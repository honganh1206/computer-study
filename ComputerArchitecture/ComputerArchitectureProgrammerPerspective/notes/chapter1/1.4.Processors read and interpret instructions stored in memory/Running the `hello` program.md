---
tags:
  - "#study"
cssclasses:
  - center-images
---
> [!info]
> 
> What described below will just be the big picture.

![[Pasted image 20240908114221.png]]


1. When we type `./hello`, the shell program reads *each character* into a register then stores it in memory
2. (Figure 1.5) When we hit enter: The shell loads the executable `hello` file from the disk → main memory by *executing a sequence of instructions*
3. (Figure 1.6) The data travels directly from disk to main memory *without passing through the processor* using **direct memory access** (DMA - more in chapter 6) - 

![[Pasted image 20240908114520.png|500]]

4. (Figure 1.7 - Pre-condition: Code and data loaded into memory) The processor executes the machine-language instructions in the program’s **main** routine: Copy the bytes from `hello, world\n` string from memory to the register file → to display device → displayed to user

![[Pasted image 20240908115105.png]]


> [!important]
> 
> You can see that the I/O bridge and I/O bus are invoked A LOT here to transfer data continuously between components.


