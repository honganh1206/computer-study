Cache store operations have two strategies:

1. **Write-through cache**: A memory write operation *simultaneously* modifies the value in the cache + the contents of main memory. A write operation *always* synchronizes the contents of the cache and main memory *immediately*
2. **Write-back cache**: A memory write operation only modifies the value stored in the cache's data block and NOT update the main memory

When evicting the data block from a dirty cache line, the cache block's data must first be written back to main memory to synchronize their contents.

How do we know if the cache blocks whose contents differ from their main memory counterparts? Each cache line stores an additional **dirty bit**, a bit that indicates whether the data stored in the cache line has been modified.

![[image-14.png|Cache extended with a dirty bit]]

We can see the trade-off between the two cache strategies: Write-though is *less complex* and *removes the need to store extra metadata* (the dirty bit), on the other hand, write-back *reduces the cost of repeated writes*

Example: When a program frequently updates the same variable without that variable's memory ever being evicted from the cache.

```c
int counter = 0;

// counter variable never gets evicted from the cache
for (int i = 0; i < 1_000_000; i++) {
    counter += 1;
}

```

In this scenario, going for the write-through strategy is expensive (each subsequent update is going to overwrite the previous one), and we should go for the write-back strategy (write to memory only when we evict the cache block)

> Most modern caches opt for a write-back design

## Example

> Writes to the cache behave like reads, except *they also set the modified cache line's dirty bit*

When evicting a dirty cache line, the cache must *write the modified data block to memory*

Scenario: Writes to two addresses 1111000001100000 and 1010000001100100

![[image-15.png]]

Index 0000011 (line 3) is valid, and the tag (1111) matches, so the request hits. Because this access is a write, the cache sets the line’s dirty bit to 1.

![[image-16.png]]

Index 0000011 (line 3) is valid, but the tag doesn’t match, so the request misses. 

Because the target line is both valid and dirty, the cache must save the existing data block to main memory *before* loading the new one. This access is a write, so the cache sets the newly loaded line’s dirty bit to 1.