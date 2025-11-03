To implement such a protocol, a processor when the coherency state changes between L1 caches. 

## Snooping

A mechanism for this is through **snooping** on a bus that is shared by all L1 caches: A snooping cache controller *listens* to the bus for reads/writes to the blocks that it caches. 

A snooping L1 cache controller can identify any read/write from another L1 cache and responds appropriately based on the coherency protocol. For example: The controller can set the I flag on a cache line when it listens to the same address by another L1 cache -> **write-invalidate protocol** that invalidates copies of cached entries on writes

**Write-update coherency protocols** is where the new value of data is snooped from the bus and applied to update all copies stored in other L1 caches

## Other mechanisms

A **directory-based cache coherence mechanism** can be used to *trigger cache coherency protocols*. This mechanism *scales better* than snooping does, as snooping has performance limitations of multiple cores sharing a single bus. However, directory-based mechanisms *require more state to detect* when memory blocks are shared, and are slower than snooping.