![[image-7.png]]

Node 1 receives the write from A but not from B due to a transient error.

Last write wins: We force an arbitrary order on the writes. Pick the one with the biggest timestamp and discard the rest. -> If losing data is unacceptable, LWW is a poor choice. Safest option is to ensure each key is written once and then immutable (Cassandra)

How do we decide if one write happens before another? If one of them knows about the other -> Not concurrent if they don't know about each other.

> To define concurrency, exact time does not matter. If two operations are unaware of each other, regardless of the physical time, they are concurrent.

Scenario: Two people adding items to the same cart

![[image-8.png]]

The clients are never fully up to date with the data on the server, since there is always another operation going on concurrently. Old versions are overwritten eventually, and no writes are lost.

> The server checks if two operations are concurrent by *looking at the version numbers* and not checking the value (so the value could be of any data structure)

## Merging concurrently written values

Algorithm: A version number for every key, increment the number whenever that key is written -> Return all not-overwritten values + version number with each read -> When writing, read the key first, then merge all values received from the prior read -> Server overwrites all values with a new version number.

One approach is to take the union of the siblings (remove duplicates from the two versions). When removing an item from a sibling, we mark the item on the other sibling with the version number (tombstone) to signal that the item has been removed.

## Version vectors

Each replica needs its own version number, and a collection of these numbers is called a **version vector**. This vector is sent to clients during reads, and sent back to the database during writes.

This vector helps us differentiate between overwrites and concurrent writes.