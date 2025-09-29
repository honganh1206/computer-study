The MMU hardware, together with the OS, are responsible for implementing address translation. This hardware/software split depends on the specific combination of hardware and the OS.

Usually the MMU does all the hard work as a mapper between virtual and physical addresses, but in some cases the OS has to handle the translation.

![[01-Areas/Computer/SystemDesign/Dive_Into_Systems/notes/chapter13/image-22.png|When the CPU needs to fetch data from physical memory, the virtual address is first translated by the MMU to a physical address]]

During a [[Context Switching]] scenario, the OS updates the MMU hardware to refer to the swapped-on process's virtual to physical memory mappings.