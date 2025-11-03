Recall [[Caching]]

Multiple threads may execute separate functions, and without a [[Cache coherency]] strategy, share variables may be updated inconsistently.

![[image-6.png]]

Each core is executing separate threads concurrently. The thread on Core 0 is assigned variable x, Core 1 variable y, and both threads share access to global variable g.

|Time|Core 0|Core 1|
|---|---|---|
|0|g = 5|(other work)|
|1|(other work)|y = g*4|
|2|x += g|y += g*2|

There might be *three stored values of g*: One in Core 0's L1 cache, one in Core 1's L1 cache, and a separate copy of g in L2 cache.

![[image-7.png]]

Supposed the L1 caches implement a write-back policy.When the thread executing on Core 0 writes the value 5 to g, it only updates the value of g in Core 0's L1 cache, while the value of g in Core 1's L1 cache still remains 10 (and also the copy in L2 cache).

Even if we implemented a write-through policy, there is no guarantee the copy of g stored in Core 1's L1 cache gets updated.

