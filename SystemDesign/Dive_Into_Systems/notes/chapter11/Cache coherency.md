The reason why each core has its own L1 caches for data and instructions is because *programs typically exhibit a high degree of locality of reference*. 

However, multiple L1 caches can result in **cache coherency** problems: The value of a cached block of memory in a core's L1 cache is *different* from the value of a cached block of memory in another core's L1 cache.

How can this happen? This occurs when one core writes to a block cached in its L1 cache, but that block is also cached in another core's L1 caches. 

-> Thus, the system needs to maintain *a coherent single value of the memory contents* across all copies of cached blocks

Multicore  processors implement a **cache-coherence protocol** to ensure a coherent view of memory that can be cached + accessed by multiple cores. This ensures any core accessing a memory location will see the *most recently modified value*.

## How does it work?

A cache coherence strategy invalidates or updates cached copies of shared values in other caches when a write to the shared data value is made in one cache. An example of this is the [[Modified-Shared-Invalid (MSI) Protocol]]

We can implement MSI with snooping (Refer to [[Implementing Cache Coherency Protocols]]) to ensure that: The only valid version of the block is in the cache that is written to, whereas all other copies of the block in other caches are marked as invalid.