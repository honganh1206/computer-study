Cache is divided into sets, and each set contains multiple lines. Sets are separated *horizontally* while lines are separated *vertically*

Index bits select a set.  When performing an address lookup, the cache simultaneously checks every line in the set.

Tag is compared *only* against the lines in that set

> Think of it like narrowing down the search area.  When the lookup narrows the search to just one cache line, it proceeds like [[Direct-Mapped Caches]].


In a **two-way set associative cache**, each set has 2 cache lines. When we index into the cache using the address, we land on a specific set. Inside that set, there are *two possible slots* for the data block

![[image-17.png|Valid bit verification and tag matching in a two-way set associative cache]]

A compromise between complexity and conflicts:

- There is a limited number of lines in a set, and it narrows down how many places a cache needs to check during a lookup
- Multiple regions that map to the same set do not trigger conflict misses (unless the entire set fills)

A new challenge: When loading a value into a cache/evicting data already resident in the cache, the cache must decide *which* of the lines to use. 

-> To solve this, we go back to [[Temporal locality]]:  We use the [[Least recently used (LRU) line]] as a **cache replacement policy** to evict.

[[Address Division for two-way set associative cache]]
