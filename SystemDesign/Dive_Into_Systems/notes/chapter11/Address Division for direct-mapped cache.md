Offset: 32-byte cache block size means the lowest-order bits (rightmost) comprise the offset portion by $\log_{2}32 = 5$

Index: 128 cache lines means the next 7 bits of the address ($\log_{2}128=7$) comprise the index portion

Tag: The remaining 4 bits are for the tag

![[image-11.png|Example 1]]

0000011 (line 3) is valid,  the tag (1010) matches -> Cache hit

The cache yields data beginning at byte 7 (offset 0b00111) of its data block.

![[image-12.png|Example 2]]

Index 0000001 (line 1) is invalid -> the request misses and we load data from main memory

![[image-13.png]]

Index 0000011 (line 3) is valid, but the tag doesn’t match, so the request misses and the cache loads data from main memory.
