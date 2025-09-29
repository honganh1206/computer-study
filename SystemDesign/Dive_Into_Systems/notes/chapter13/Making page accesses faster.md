Tags: #review 

In a paged virtual memory system, every load and store to a virtual memory address requires *two RAM accesses*: The 1st access *reads the PTE* to get the frame number for VA-to-PA translation, and the 2nd access *writes the bytes* at the RAM physical address. -> Every memory access is twice as slow as in a system that supports direct physical RAM addressing.

How to improve this? We *cache* the mappings of VA to PA: When translating a VA, the MMU first checks for the page number in the cache. If found, the page's frame number mapping can be grabbed from the cache entry, avoiding the 1st RAM access.

To do so, we use a [[Translation look-aside buffer]].
