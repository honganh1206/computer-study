As multiple memory ranges map to the same cache line, the cache examines the line's *metadata* to answer two questions:

1. Does this cache line hold a valid subset of memory?
2. If yes, which memory subset does this cache line hold?

Each cache line's metadata includes a **valid bit** (indicate whether a cache line is storing a valid subset of memory, in that case valid is set to 1 and 0 if invalid) and a **tag** (uniquely identify which subset of memory the line's cache block is holding)

To produce a cache hit, the tag field stored in the cache line must *exactly match* the tag portion (higher-order bits) of the requested memory address. If there is a tag mismatch, the cache line's data block does not contain the requested memory

![[image-7.png|Verify the line's valid bit and check its tag]]

> To determine if there is a cache hit, we must check:
> 1. *The number of bits in a memory address* to define how many tag, index and offset bits in total. Without this, we cannot split the address.
> 2. Size of the cache blocks. Larger block size means more offset bits and fewer left for index + tag
> 3. Total number of sets. Fewer sets = fewer index bits, meaning more tag bits.