Tags: #review 

We know from [[The Memory Hierarchy]] that memory references usually exhibit a very high degree of locality, meaning processes usually access pages in their assigned memory space with a high degree of spatial/temporal locality.

However, this is not the case, as *processes typically never access large extents of their full address spaces*.

So the OS treats RAM as a cache for disk: Some of the virtual memory pages loaded into physical frames of RAM, while other virtual memory pages remain on secondary storage devices. This is called the OS's **virtual memory abstraction** - A single large physical "memory" as a combination of RAM storage and secondary storage.

By doing so, the OS keeps in RAM the pages that are being accessed/have been accessed recently, while others are stored on slower disk. Doing this has several benefits:

- More efficient use of RAM: We don't store not-frequently-used pages on RAM.
- More efficient use of CPU: As processes can share RAM space to store active pages, more processes are ready, reducing the time CPU is idle.

[[Page fault]]

[[Page replacement policy]]

