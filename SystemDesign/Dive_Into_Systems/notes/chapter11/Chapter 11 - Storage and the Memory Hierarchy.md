> [!summary]
> - Devices form a memory hierarchy based on capacity and access time.
> - At the top of the hierarchy is primary storage devices (CPU caches, main memory) that quickly provides data directly to the CPU, and at the lower of the hierarchy is secondary storage devices like SSDs and HDDs that offer dense bulk storage.
> - Systems rely on data access patterns namely temporal locality (access the same data repeatedly) and spatial locality (access data nearby other) to determine which data to use.
> - When a program attempts to access main memory, the CPU first checks for data in the cache to avoid costly trips to main memory.
> - A program provides a memory address to read/write memory, and that address is separated into index + tag + offset bits to identify which subset of main memory a cache line stores.


[[The Memory Hierarchy]]

[[Storage Devices]]

[[Locality]]

[[Caching]]

[[Looking Ahead - Caching on Multicore Processors]]

