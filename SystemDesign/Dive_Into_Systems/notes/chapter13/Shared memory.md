Two processes running on the same machine can take advantage of *shared system resources to communicate more efficiently*. For example, an OS can allow processes to share all/part of their virtual address spaces.

How do we implement partial address space sharing? We set the entries in the page tables of two or more processes to map to the same physical frames. To communicate, one process writes a value to an address on a shared page, and another process subsequently reads the value

![[image-26.png|Mapping entries on page tables to the same frame on the physical address space]]

If the OS supports partial shared memory, it will *implement an interface* to the programmer for creating and attaching to shared pages of memory. In Unix systems, we use the `shmget` system call to create or attach to a shared memory segment.

Each shared memory segment corresponds to *a contiguous set of virtual addresses*. The mappings of these addresses are shared between processes attaching to the same shared memory segment.

[[Threads]] are the OS abstraction of an *execution control flow*. A process has a single thread of execution control flow in a single virtual address space, while a multithreaded process has multiple threads in a single, shared virtual address space.