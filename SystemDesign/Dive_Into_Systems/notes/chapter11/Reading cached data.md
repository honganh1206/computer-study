When a program wants to access a memory address, the cache must:

1. [[Locating cached data]]
2. [[Identifying Cache Contents]]
3. [[Retrieving Cached Data]] if available

[[Memory Address Division]]

Consider a CPU with the following characteristics:

1. 16-bit memory addresses
2. A direct-mapped cache with 128 cache lines
3. 32-byte cache data blocks

![[image-10.png|505x354]]


The CPU wants to access the following memory locations: `1010000001100100`, `1010000001100111`, `1001000000100000`, `1111000001100101`

> **Follow these steps when tracing the behavior of a cache:**
> 1. Divide the requested address from right (low-order bits) to left (high-order bits) into an offset, an index and a tag
> 2. Use the index to find the cache line to which the address maps
> 3. Check the cache line's valid bit
> 4. Check the cache line's tag with the address' tag to check for either cache hit or cache miss
> 5. On a hit, use the offset to extract the program's desired data

Continue from the above example:

[[Address Division for direct-mapped cache]]