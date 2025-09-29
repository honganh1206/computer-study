In a multicore system, each core maintains its own private cache memory at the highest level(s) of the memory hierarchy (fastest to access), and all cores share a single cache with all cores at lower levels.

![[01-Areas/Computer/SystemDesign/Dive_Into_Systems/notes/chapter11/image-21.png|551x457]]


Each core simultaneously executes an independent stream of instructions (often from separate programs). Each core's L1 cache stores a copy of only those blocks of memory that are from its execution stream, and this design yields a higher hit rate in each core's private L1 cache.

Today's processors often include more than two levels of cache. There are three available levels:

-  Highest level L1 is split into *two separate L1 caches*, one for instructions and the other for program data
-  L2 and L3 are **unified caches** (storing both instructions and program data). While L3 is shared by all cores, L2 varies substantially in modern CPU designs. 

[[Processor and Cache information on Linux systems]]

[[Cache coherency]]

[[Modified-Shared-Invalid (MSI) Protocol]]

[[Implementing Cache Coherency Protocols]]

The **false sharing problem** occurs when multiple threads of a single multithread parallel program are running simultaneously across multiple cores, and such threads are accessing locations near to those accessed by other threads?