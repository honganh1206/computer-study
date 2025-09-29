---
sr-due: 2025-09-28
sr-interval: 3
sr-ease: 250
---

Tags: #review 

Sometimes processes try to access a page that is not currently stored in RAM, leading to a **page fault**. When a page fault occurs, the OS needs to read the page from disk into RAM before the processes can continue executing.

## Handling the page fault

The MMU reads a PTE's valid bit whether it needs to trigger a page fault exception. If the PTE has an invalid bit (0), it traps the OS and takes the following steps:

1. The OS finds a *free frame* e.g., frame j, of RAM to load the fault page into it.
2. The OS issues a read to the disk, demanding to load a page into frame j of RAM.
3. When the read request is completed, the OS updates the PTE entry, setting the frame number to j and valid bit to 1.
4. The OS restarts the process at the instruction that caused the page fault.

> OSes often keep a list of free frames available for allocating a page fault. 

If there is no free frame available, the OS picks a frame and replaces the page it stores with the faulted page. The replaced page is written back to disk if its in-RAM contents differ from its on-disk version. 

PTEs of ten include a **dirty bit** to signal content difference, and it tells the replaced page to have its content written to disk before being replaced.