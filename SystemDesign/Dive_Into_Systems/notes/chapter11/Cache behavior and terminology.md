Recall: When accessing data in memory, a program first computes the data's memory address (refer back to [[Assembly Basics of the x86-64 ISA]]). 

A **cache block** refers to the *unit of data* transferred between main memory and the cache. A **cache line** refers to the *physical storage location* in the cache that holds one cache block.

A single cache line holds exactly *one* block of data.

If the data at the desired address is already inside the cache, we allow the program to *skip accessing main memory*. The hardware can simultaneously send the desired address to *both the cache and main memory*.

If the data is present in the cache i.e., a **cache hit**, the cache hardware *cancels the pending memory access*. Otherwise, if the data isn't in the cache (**cache miss**), then the CPU has to wait for memory to retrieve it.


When we write to an address not in the cache (a miss), *the CPU will still load that memory block into the cache*, so when the program touches it again soon, the access will be faster

Sometimes a CPU might find the cache does not have enough space, and in such cases, the cache must first *evict some resident data* to make room for the new data. And when we evict cached data, we need to *update the contents of main memory prior to the eviction*, since the cached data might be outdated.