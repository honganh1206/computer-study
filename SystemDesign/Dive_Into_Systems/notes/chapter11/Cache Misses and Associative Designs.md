Cache designers aim to *maximize a cache's hit rate* so that as many memory requests as possible can avoid going to main memory

Although, real caches cannot expect to hit on every access due to:

- **Compulsory misses** or **cold-start misses**: If a program has never accessed a memory location, it might not be able to find the location's data in a cache (Unavoidable)
- **Capacity misses**: If a program is actively using more memory than fits in the cache, it cannot get all the data it wants in the cache, thus misses
- **Conflict misses**: Certain cache designs limit where data can reside to reduce the complexity when finding data, but sometimes such restrictions can lead to misses. An example is a program ends up with addresses of two frequently used variables mapping to *the same cache location*. In such cases, each access to one of those variables will evict the other from the cache (as they compete for the same cache line)

> In general, a cache's design mainly affects its conflict miss rate. Direct-mapped caches suffer most from this.

The alternative to direct-mapped cache is [[Associative Cache]]

## Core ideas behind cache misses

In an N-way set associative cache using LRU, *a block can survive at most N-1 other distinct blocks inserted into the same set between uses*. If the reuse distance (number of distinct other tags accessed between two consecutive references to the same tag) is larger than N-1, that block will have been evicted, leading to *a miss on every access*

> For first-ever references we call that a *compulsory* i.e., no previous reference

A direct-mapped cache has N=1, and set associative caches have N as the ways.

Supposed a reuse distance is 5:
- **Direct-mapped (N=1):** N−1 = 0 < 5 ⇒ every access misses → **12/12** (given).
- **2-way set associative (N=2):** N−1 = 1 < 5 ⇒ every access misses → **12/12**.
- **4-way set associative (N=4):** N−1 = 3 < 5 ⇒ every access misses → **12/12**.