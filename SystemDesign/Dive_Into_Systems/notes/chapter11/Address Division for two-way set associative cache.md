Consider the following characteristics:

- 16-bit memory address
- A two-way set associative cache with 64 sets
- 32-byte cache blocks
- LRU policy with 0 for leftmost line as LRU and 1 for rightmost line as LRU

![[image-19.png|Empty two-way associative example cache]]

Example: 1. Read from address 1010000001100100

32-byte block size -> Rightmost 5 bits `00100` of the address ($\log_{2}32 = 5$) comprise the offset portion 

64-set cache -> Next six bits `000011` comprises the index portion 

Remaining bits `10100` for the tag

![[image-20.png]]

Both lines at index 000011 (set 3) are invalid, so the request misses, and the cache loads data from main memory. The set’s LRU bit is 0, so the cache loads data into the left line and updates the LRU bit to 1.