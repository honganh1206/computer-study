A cache must quickly determine whether the subset of memory corresponding to the requested address is in the cache or not, and to do so it first *determines which cache line(s) to check*

In [[Direct-Mapped Caches]], each address corresponds to *exactly one cache line*, hence the *direct-mapped* name.

![[image-5.png|Mapping memory addresses to cache lines in a 4-line direct-mapped cache]]

All the memory regions that map to the same cache line i.e., chunks of the same color,  *compete for space in the same cache line*, so **only one region of each color can reside in the cache at a time**

> A cache line does not just store one value, it stores a *whole block* of consecutive bytes from RAM due to spatial locality.
## Index calculation

How can a cache map a memory address to a cache line? Using a *portion of the bits in the memory address*. That portion is taken from the *middle* of the memory address, known as the **index portion**, to determine which cache line the address maps to.

 ![[image-6.png]]
 
 Why do we pick the middle? Doing so *reduces competition* for the same cache line when program data is *clustered together* (which is often the case for programs with good locality). We use bits from the middle of the address to ensure *data is spread evenly among available cache lines*
 
What is the competition in this context? Clustered variables *share the same high-order bits* and their addresses differ only in low-order bits. If the cache index comes from such high-order bits, the clustered variables will *all map to the same cache lines* and thus leaving the rest of the cache unused.