At a minimum, most architectures provide a **page table base register** (PTBR), which stores the *base address* of the currently running process's page table.

When performing virtual-to-physical address translation, the virtual page number (p) part is combined with the value stored in the PTBR to find the PTE for the virtual page. -> The virtual page number is an *index* into the process's page table.

Example: PTBR + p x (PTE size)  is the RAM address of the PTE for page p

> [!info]
> Some architectures may support full page table lookup by *manipulating PTE bits in hardware*. 

The usual way is the OS needs to be interrupted to handle parts of page table lookup + access PTE bits to translate a virtual address to physical address.

During a context switch, the OS *saves and restores* the PTBR values of different processes to ensure when a process runs on the CPU, *it accesses its own virtual-to-physical address mappings* from its own page table in RAM (separation of concerns?). -> Processes cannot access the VA-PA mappings of another process.



