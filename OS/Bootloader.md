The [[BIOS]] will transfer control of the PC to the **bootloader**, and its task is to *transfer the control to us developers and our code*.

The bootloader is split into two parts: The 1st part will transfer control to the 2nd part, meaning it gives control of the PC to the OS.

Example is the GNU GRand Unified Bootloader (GRUB), and a legacy example is `stage2_eltorito`

The OS is frist built as an [[Executable Format]] (ELF), which will be loaded by GRUB into the correct memory location

GRUB must load the kernel at a memory address larger than/equal to `0x00100000` (1MB), as it is reserved for legacy components like GRUB, BIOS memory-mapped I/O, etc. To do so, we need a linker script `.ld`

The Multiboot Standard stands as an interface between the bootloader and the OS kernel. 

How the Standard works: It puts some values in some global variables (*multiboot header*) which is searched for by the bootloader. When the kernel sees the values, it recognizes the kernel as multiboot compatible and it knows how to load us.