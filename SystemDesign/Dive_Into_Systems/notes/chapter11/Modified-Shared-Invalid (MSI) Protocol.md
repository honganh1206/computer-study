The MSI protocol adds three flags (bits) to each cache line.

A flag's value is either clear (0) or set (1). Those values encode the *state* of its data block with respect to [[Cache coherency]] with other cached copies. The values trigger cache coherency actions on read/write accesses.

- The M (Modified) flag indicates the block has been modified, meaning this core has written to its copy of the cached value
- The S (Shared) flag indicates the block is unmodified and thus safe to be shared
- The I (Invalid) flag indicates the cached block is invalid or contains stale data.

## On a read access

If a cache block is in either M/S state, the cache value is used to satisfy the read

If it is in I state, the cached copy is out of date, and the block's new value must be loaded into the cache line

## On a write access

If the block is in M state, we write to the cached copy of the block. No need to change the flag

If the block is in I/S state, we notify other cores that the block is being written to, and other L1 caches have to clear the S bit and set the I bit on their copies of the block.

If another L1 cache has the block in the M state, it will write its block back to the lower level and set its copy to I. The writing core then loads the new value into its L1 cache, set the M flag and clear the I flags.

## Example

![[01-Areas/Computer/SystemDesign/Dive_Into_Systems/notes/chapter11/image-22.png|Both cores have a copy of the block in their L1 caches]]

At this point, both core 0 and core 1 can safely read from the copy stored in their L1 caches.

When core 0 writes to the copy of the block in its L1 cache, its L1 cache controller notifies the other L1 caches to *invalidate their copy of the block*. Core 1 will then clear the S flag + set the I flag on its copy, while core 0 writes to the block and sets the M flag. At this point, the copy in L2 cache and in core 1's L1 cache are *stale*.

![[01-Areas/Computer/SystemDesign/Dive_Into_Systems/notes/chapter11/image-23.png|Stale copies inside core 1 and L2 cache]]


When core 1 reads from the memory block, the I flag will tell the core that the cache block cannot be used to satisfy the read.  To resolve this:

1. Core 0's L1 cache controller writes the new value to L2
2. Core 1's L1 cache can read the new value from L2 to its L1 cache


