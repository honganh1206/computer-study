Paging is the *most widely used* implementation of virtual memory. The OS divides the virtual address space of each process into fixed-sized chunks (**pages**). Page sizes are around 4 KB by default.

Physical memory is divided by the OS into page-sized chunks called **frames**. Any page on a process's virtual memory can be stored in any frame.

> [!info] In a paging system
> - Pages do not need to be stored in contiguous RAM frames.
> - Not every page needs to be loaded into RAM for a process to run.

![[image-14.png|Paged virtual memory. Individual pages of a process's virtual address space (VAS) are stored in RAM frames]]

Any page of virtual address space can be stored at any frame of physical memory. For example above, P1's virtual page 500 resides in frame 513.

[[Virtual and Physical Addresses in Paged Systems]]

[[Page Tables for Virtual-To-Physical Page Mapping]]

[[Paging implementation]]

[[Page fault]]

