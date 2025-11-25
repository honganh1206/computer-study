GRUB will transfer control to the OS by *jumping to a position in memory* by looking for a magic number to ensure it actually jumps to an OS. This magic number is part of the *multiboot specification* that GRUB adheres to.

The loader of the OS could be written in Assembly, and after we have compiled it to an executable ELF file, we can link it the the [[Kernel]]